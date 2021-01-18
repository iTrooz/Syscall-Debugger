#include<debugwindow.h>
#include<iostream>
#include<sstream>
#include<libexplain/ptrace.h>
#include<unordered_set>
#include "configFile.h"

using namespace std;


void DebugWindow::setupProcess(pid_t pid) {
	mainProcess = new Process;
	mainProcess->pid = pid;
	long temp = ptrace(PTRACE_ATTACH, pid, 0, 0);
	if (temp != 0) {
		cerr << "PTRACE_ATTACH failed : code " << temp << endl;
		return;
	}

	displayed = mainProcess;
	startTrace();
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

void DebugWindow::createProcess() {

	char** cmdArgs = convert(cmd);

	pid_t child = fork();
	if(child==0){
		ptrace(PTRACE_TRACEME);
		kill(getpid(), SIGSTOP);
		execvp(cmdArgs[0], cmdArgs); // stop le flow du code
		throw runtime_error("NOT SUPPOSED TO HAPPEN : PROCESS ESCAPED"); // au cas ou
	}else {
		mainProcess = new Process;
		mainProcess->pid = child;

		displayed = mainProcess;
		startTrace();
	}
}



bool DebugWindow::waitProcess(pid_t& stopped) {
	int status;
	while (true) {

		stopped = waitpid(-1, &status, __WALL);

		if(stopped==-1)exit(0);


		if (WSTOPSIG(status) & 0x80){
			if(WIFSTOPPED(status))return false;
			else cerr << "Not supposed to happens : status marked 0x80 but not stopped" << endl;
		}

		if (WIFEXITED(status)){
			return true;
		}

		status = ptrace(PTRACE_SYSCALL, stopped, 0, WSTOPSIG(status)); // restart le thread + l'arrête au prochain syscall
		if(status!=0){
			cerr << "failed wait_for_syscall : " << status << endl;
			cerr << explain_ptrace(PTRACE_SYSCALL, stopped, 0, (void*) WSTOPSIG(status)) << endl;
		}
	}
}

void DebugWindow::startTrace() { // TODO way to kill tracer ?

	int temp, stopped;
	processes.insert(mainProcess);

	waitpid(mainProcess->pid, nullptr, 0);
	temp = ptrace(PTRACE_SETOPTIONS, mainProcess->pid, 0, PTRACE_O_TRACESYSGOOD|PTRACE_O_TRACEFORK|PTRACE_O_TRACEVFORK|PTRACE_O_TRACECLONE|PTRACE_O_TRACEEXEC|PTRACE_O_TRACEEXIT);
	if (temp != 0)throw runtime_error("PTRACE_SETOPTIONS failed : " + to_string(temp));

	temp = ptrace(PTRACE_SYSCALL, mainProcess->pid, 0, 0);
	if (temp != 0)throw runtime_error("FIRST PTRACE_SYSCALL failed : " +
									  to_string(temp));

	mainProcess->treeItem = UI.processTree->topLevelItem(0);
	mainProcess->treeItem->setText(0, QString(to_string(mainProcess->pid).c_str()));

	Process* proc;
	syscall_data* info;
	int size = sizeof(__ptrace_syscall_info);

	bool empty;
	while (true) {
		if (waitProcess(stopped)) {
			proc = nullptr;
			empty = true;
			for (Process *p : processes) {
				if (p->running){
					if(p->pid == stopped) {
						p->running = false;
						proc = p;
					}else{
						empty = false;
					}
					if(!empty&&proc!=nullptr)break; // TODO jsp si vraiment opti
				}
			}
			if(proc==nullptr){
				cerr << "Invalid child exited : " << stopped << endl;
			}else{
				handleChildExit(*proc);
				if (empty)break;
			}
			continue;
		}

		proc = getProcess(stopped);
		if(proc==nullptr){
			proc = handleChildCreate(stopped);
		}

		info = new syscall_data(); // TODO si EXIT penser à del le surplus de ENTRY
		ptrace(PTRACE_GET_SYSCALL_INFO, stopped, size, info);

		if(info->base.op==PTRACE_SYSCALL_INFO_ENTRY){
			if(proc->currentCall!=nullptr) {
				cerr << "Warning " << stopped << " : waiting for syscall exit, got syscall entry" << endl;
			}else{
				proc->currentCall = new Syscall();
				proc->currentCall->entry = &info->entry;
				proc->currentCall->guessName(); // TODO ONLY GUESS NAME IF SELECTED (no useless calcs)
				proc->calls.push_back(proc->currentCall);

//				handleCallStart(*proc);
			}


		}else{ // exit
			if(proc->currentCall==nullptr) {
				cerr << "Warning " << stopped << " : waiting for syscall entry, got syscall exit" << endl;
			}else{
				proc->currentCall->exit = &info->exit;

//				handleCallReturn(*proc);
				proc->currentCall = nullptr;
			}
		}

		temp = ptrace(PTRACE_SYSCALL, stopped, 0, 0); // restart le thread + l'arrête au prochain syscall
		if(temp!=0)cerr << "PTRACE_SYSCALL in-loop failed : " << temp << endl;
	}
}
