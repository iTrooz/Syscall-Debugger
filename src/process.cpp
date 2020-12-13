#include <iostream>
#include <sstream>
#include "process.h"

using namespace std;

void Process::remove(){
	kill(*tracee, 9);
	delete this;
}


bool wait(pid_t child) {
	int status;
	while (1) {
		ptrace(PTRACE_SYSCALL, child, 0, 0);
		waitpid(child, &status, 0);
		if (WIFSTOPPED(status) && WSTOPSIG(status) & 0x80)
			return false;
		if (WIFEXITED(status))
			return true;
	}
}

char** convert(char* cmd);

void Process::startTrace() {
	ptrace(PTRACE_SETOPTIONS, tracee, 0, PTRACE_O_TRACESYSGOOD);
	int temp;
	while (true) {
		if (wait(tracee) != 0) break;
		temp = ptrace(PTRACE_PEEKUSER, tracee, sizeof(long) * ORIG_RAX);
		fprintf(stderr, "syscall(%d) = ", temp); // syscall
		if (wait(tracee) != 0) break;
		temp = ptrace(PTRACE_PEEKUSER, tracee, sizeof(long) * RAX);
		fprintf(stderr, "%d\n", temp); // retval
	}
}

int Process::setupProcess(pid_t pid) {
	tracee = pid;
	pid_t child = fork();
	if (child == 0){
		int temp;
		temp = ptrace(PTRACE_ATTACH, child, 0, 0);
		if(temp!=0){
			cout << "ptrace failed : code " << temp << endl;
			return 1;
		}
		waitpid(child, &temp, 0);

	}
}


int Process::createProcess(char *cmd) {

	char** cmdArgs = convert(cmd);

	pid_t child = fork();
	if(child==0){
		ptrace(PTRACE_TRACEME);
		kill(getpid(), SIGSTOP);
		return execvp(cmdArgs[0], cmdArgs);
	}else{
		tracee = child;
	}
}








char** convert(char* cmd){
	stringstream a(cmd);
	vector<string> vec;
	string s;
	while (getline(a, s, ' ')) {
		vec.push_back(s);
		cout << s << endl;
	}

	const char **cmdArgs = new const char* [vec.size() + 1];
	for (int i=0; i<vec.size(); i++){
		cmdArgs[i] = vec[i].c_str();
	}
	cmdArgs[vec.size()] = nullptr;
	return (char**)cmdArgs;
}
