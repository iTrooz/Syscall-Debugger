#include <iostream>
#include <sstream>
#include <fstream>
#include <unordered_set>
#include <sys/ptrace.h>
#include <unistd.h>
#include <wait.h>

#include "tracerCore.h"
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

		handleTracerStart(child);
		startTracer(child);
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

	handleTracerStart(pid);

	startTracer(pid);
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

void Tracer::startTracer(pid_t mainProcess) { // TODO way to kill tracerConnection ?

	int temp, stopped;

	temp = ptrace(PTRACE_SETOPTIONS, mainProcess, 0, PTRACE_O_TRACESYSGOOD|PTRACE_O_TRACEFORK|PTRACE_O_TRACEVFORK|
	PTRACE_O_TRACECLONE|PTRACE_O_TRACEEXEC|PTRACE_O_TRACEEXIT|PTRACE_O_EXITKILL);
	if (temp != 0)throw runtime_error("PTRACE_SETOPTIONS failed : " + to_string(temp));

	temp = ptrace(PTRACE_SYSCALL, mainProcess, 0, 0);
	if (temp != 0)throw runtime_error("FIRST PTRACE_SYSCALL failed : " +
									  to_string(temp));

	__ptrace_syscall_info info{};
	int size = sizeof(__ptrace_syscall_info);

	while (true) {
		if (waitProcess(stopped)) {
			if(handleChildExit(stopped))break;
			else continue;
		}

		ptrace(PTRACE_GET_SYSCALL_INFO, stopped, size, &info);
		handleCall(stopped, info);

		temp = ptrace(PTRACE_SYSCALL, stopped, 0, 0); // restart le thread + l'arrête au prochain syscall
		if(temp!=0)cerr << "PTRACE_SYSCALL in-loop failed : " << temp << endl;
	}
	handleTracerStop();
	cout << "EXITED" << endl;
}
