#include <iostream>
#include <sstream>
#include "process.h"
#include "utils.h"

using namespace std;

void Process::remove(){ // TODO jsp si ca marche
	kill(tracee, 9);
	for(Process &p : subProcesses){
		p.remove();
	}
	delete this;
}


bool Process::wait() {
	int status;
	while (true) {
		ptrace(PTRACE_SYSCALL, tracee, 0, 0);
		waitpid(tracee, &status, 0);
		if (WIFSTOPPED(status) && WSTOPSIG(status) & 0x80){
			return false;
		}
		if (WIFEXITED(status)){
			return true;
		}
	}
}



void Process::startTrace() {
	cout << "START" << endl;
	int temp;
	waitpid(tracee, &temp, 0);
	temp = ptrace(PTRACE_SETOPTIONS, tracee, 0, PTRACE_O_TRACESYSGOOD);
	if(temp!=0){
		cout << "PTRACE_SETOPTIONS failed : code " << temp << endl;
		return;
	}
	Syscall* call;
	cout << "salut" << endl;
	while (true) {
		call = new Syscall;

		if (wait()) break;
		call->id = ptrace(PTRACE_PEEKUSER, tracee, sizeof(long) * ORIG_RAX);
		if (wait()) break;
		call->result = ptrace(PTRACE_PEEKUSER, tracee, sizeof(long) * RAX);

		mainWindow->addEntry(*call);
		calls.push_back(*call);

		cout << "syscall received" << endl;
	}
	// program exited
}

int Process::setupProcess(pid_t pid) {
	tracee = pid;
	pid_t child = fork();
	if (child == 0){
		int temp;
		temp = ptrace(PTRACE_ATTACH, child, 0, 0);
		if(temp!=0){
			cout << "PTRACE_ATTACH failed : code " << temp << endl;
			return 1;
		}

	}
}

char** convert(string& cmd){
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


void Process::createProcess(string& cmd) {

	char** cmdArgs = convert(cmd);

	pid_t child = fork();
	if(child==0){
		ptrace(PTRACE_TRACEME);
		kill(getpid(), SIGSTOP);
		execvp(cmdArgs[0], cmdArgs); // stop le flow du code
		return; // au cas ou
	}else{
		tracee = child;
	}
}