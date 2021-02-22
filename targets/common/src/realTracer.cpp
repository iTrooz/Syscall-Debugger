#include <iostream>
#include <sstream>
#include <fstream>
#include <unordered_set>
#include <sys/ptrace.h>
#include <unistd.h>
#include <wait.h>
#include <thread>
#include <vector>

#include "realTracer.h"
#include "plateform.h"

using namespace std;

char** convert(const string& cmd);

RealTracer::RealTracer(UIConnect *ui) {
	isLocal = true;
	uiConnect = ui;

	config.parseConfig();
	config.assignConfig();

	loadSyscalls(config.syscallPath, syscalls);
}

void RealTracer::cleanUp(){
	for(auto* proc : processes){
//		delete proc;
	}
	processes.clear();
}

void RealTracer::createProcess(const string& cmd) {
	thread thr(&RealTracer::createProcessInternal, this, cmd);
	thr.detach();
}

void RealTracer::createProcessInternal(const string& cmd) {
	cleanUp();

	char** cmdArgs = convert(cmd);

	mainProcess = fork();
	if(mainProcess==0){
		ptrace(PTRACE_TRACEME);
		kill(getpid(), SIGSTOP);
		execvp(cmdArgs[0], cmdArgs); // stop le flow du code
		throw runtime_error("NOT SUPPOSED TO HAPPEN : PROCESS ESCAPED"); // au cas ou
	}else {
		waitpid(mainProcess, nullptr, 0);

		uiConnect->handleTracerStart(mainProcess);

		startTracer();
	}
}

void RealTracer::setupProcess(pid_t pid) {
	thread thr(&RealTracer::setupProcessInternal, this, pid);
	thr.detach();
}

void RealTracer::setupProcessInternal(pid_t pid) {
	cleanUp();
	mainProcess = pid;

	long temp = ptrace(PTRACE_ATTACH, pid, 0, 0);
	if (temp != 0) {
		cerr << "PTRACE_ATTACH failed : code " << temp << endl;
		return;
	}
	waitpid(pid, nullptr, 0);

	list<pdata> pids;
	parseProc(pids, pid);

	uiConnect->handleTracerStartBulk(pid, pids);

	startTracer();
}

bool RealTracer::waitProcess(pid_t& stopped) {
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

void RealTracer::startTracer() {
	int temp, stopped;

	temp = ptrace(PTRACE_SETOPTIONS, mainProcess, 0, PTRACE_O_TRACESYSGOOD|PTRACE_O_TRACEFORK|PTRACE_O_TRACEVFORK|
													 PTRACE_O_TRACECLONE|PTRACE_O_TRACEEXEC|PTRACE_O_TRACEEXIT|PTRACE_O_EXITKILL);
	if (temp != 0)throw runtime_error("PTRACE_SETOPTIONS failed : " + to_string(temp));

	temp = ptrace(PTRACE_SYSCALL, mainProcess, 0, 0);
	if (temp != 0)throw runtime_error("FIRST PTRACE_SYSCALL failed : " +
									  to_string(temp));

	native_syscall_info info{};
	int size = sizeof(native_syscall_info);

	while (true) {
		if (waitProcess(stopped)) {
			if(uiConnect->handleChildExit(stopped))break;
			else continue;
		}

		ptrace(PTRACE_GET_SYSCALL_INFO, stopped, size, &info);
		uiConnect->handleCall(stopped, info);

		temp = ptrace(PTRACE_SYSCALL, stopped, 0, 0); // restart le thread + l'arrête au prochain syscall
		if(temp!=0)cerr << "PTRACE_SYSCALL in-loop failed : " << temp << endl;
	}
	uiConnect->handleTracerStop();
	cout << "EXITED" << endl;
}


void RealTracer::killProcess(){
	kill(mainProcess, SIGKILL); // stop loop softly instead ? (threads seems not to like to be killed)
}

RealTracer::~RealTracer() {
	cleanUp();
}





char** convert(const string& cmd){
	stringstream a(cmd);
	vector<string> vec;
	string s;
	while (getline(a, s, ' ')) {
		vec.push_back(s);
	}

	const char **cmdArgs = new const char* [vec.size() + 1];
	for (int i=0; i<vec.size(); i++){
		cmdArgs[i] = vec[i].c_str();
	}
	cmdArgs[vec.size()] = nullptr;
	return (char**)cmdArgs;
}