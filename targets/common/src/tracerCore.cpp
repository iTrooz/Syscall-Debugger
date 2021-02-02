#include <iostream>
#include <sstream>
#include <fstream>
#include <dirent.h>
#include <unordered_set>

#include "tracerCore.h"
#include "../../otracer/headers/process.h"
#include "tracerUtils.h"

using namespace std;

void Tracer::createProcess(const string& cmd) {
	tracerPID = gettid();

	char** cmdArgs = convert(cmd);

	pid_t child = fork();
	if(child==0){
		ptrace(PTRACE_TRACEME);
		kill(getpid(), SIGSTOP);
		execvp(cmdArgs[0], cmdArgs); // stop le flow du code
		throw runtime_error("NOT SUPPOSED TO HAPPEN : PROCESS ESCAPED"); // au cas ou
	}else {
		waitpid(child, nullptr, 0);

		mainProcess = new Process(child);
		processes.insert(mainProcess);
		handleTracerStart();
		startTracer();
	}
}

void Tracer::setupProcess(pid_t pid) {
	tracerPID = gettid();

	long temp = ptrace(PTRACE_ATTACH, pid, 0, 0);
	if (temp != 0) {
		cerr << "PTRACE_ATTACH failed : code " << temp << endl;
		return;
	}
	waitpid(pid, nullptr, 0);

	mainProcess = new Process(pid);
	processes.insert(mainProcess);
	handleTracerStart();

	recurPIDs(&processes, mainProcess);
	startTracer();
}

bool Tracer::waitProcess(pid_t& stopped) {
	int status;
	while (true) {
		stopped = waitpid(-1, &status, __WALL);

		if(stopped==-1)exit(0);


		if (WSTOPSIG(status) & 0x80){
			if(WIFSTOPPED(status))return false;
			else throw runtime_error("Not supposed to happen : status marked 0x80 but not stopped");
		}

		// peut-être pas suffisant pour détecter quand le process s'arrête !
		if (WIFEXITED(status)){
			return true;
		}
		if (WIFSIGNALED(status)){
			return true;
		}

		status = ptrace(PTRACE_SYSCALL, stopped, 0, WSTOPSIG(status)); // restart le thread + l'arrête au prochain syscall
		if(status!=0){
			cerr << "failed wait_for_syscall : " << status << endl;
		}
	}
}

void Tracer::startTracer() { // TODO way to kill tracerConnection ?

	int temp, stopped;

	temp = ptrace(PTRACE_SETOPTIONS, mainProcess->pid, 0, PTRACE_O_TRACESYSGOOD|PTRACE_O_TRACEFORK|PTRACE_O_TRACEVFORK|
	PTRACE_O_TRACECLONE|PTRACE_O_TRACEEXEC|PTRACE_O_TRACEEXIT|PTRACE_O_EXITKILL);
	if (temp != 0)throw runtime_error("PTRACE_SETOPTIONS failed : " + to_string(temp));

	temp = ptrace(PTRACE_SYSCALL, mainProcess->pid, 0, 0);
	if (temp != 0)throw runtime_error("FIRST PTRACE_SYSCALL failed : " +
									  to_string(temp));

	Process* proc;
	__ptrace_syscall_info info{};
	int size = sizeof(__ptrace_syscall_info);

	while (true) {
		if (waitProcess(stopped)) {
			if(handleChildExit(stopped))break;
			else continue;
		}

		proc = getProcess(stopped);
		if(proc==nullptr){
			proc = handleChildCreate(stopped);
		}

		ptrace(PTRACE_GET_SYSCALL_INFO, stopped, size, &info);

		if(info.op==PTRACE_SYSCALL_INFO_ENTRY) {
			if (proc->currentCall != nullptr) {
				cerr << "Warning " << stopped << " : waiting for syscall exit, got syscall entry" << endl;
			} else {
				proc->currentCall = new Syscall();
				proc->currentCall->entry = info;
				proc->calls.push_back(proc->currentCall);

				handleCallEntry(*proc);
			}

		}else if(info.op==PTRACE_SYSCALL_INFO_EXIT){
			if(proc->currentCall==nullptr) {
				cerr << "Warning " << stopped << " : waiting for syscall entry, got syscall exit" << endl;
			}else {
				proc->currentCall->exit = info;

				handleCallExit(*proc);

				proc->currentCall = nullptr;
			}
		}else{
			cerr << "Got unsupported OP " << to_string(info.op) << endl;
		}

		temp = ptrace(PTRACE_SYSCALL, stopped, 0, 0); // restart le thread + l'arrête au prochain syscall
		if(temp!=0)cerr << "PTRACE_SYSCALL in-loop failed : " << temp << endl;
	}
	handleTracerStop();
	cout << "EXITED" << endl;
}
