#include<debugwindow.h>
#include<iostream>
#include <sstream>
#include <unordered_set>
#include "configFile.h"

using namespace std;


void DebugWindow::remProcess(bool kil){ // TODO jsp si ca marche
	for(Process* p : processes){
		if(kil)kill(p->pid, 9);
		delete p;
	}
	delete this;
}

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
		cout << cmdArgs[0] << endl;
		cout << cmdArgs[1] << endl;
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
		if(stopped==-1){
			exit(0);
		}

//		if(((status >> 16) & 0xffff) == PTRACE_EVENT_CLONE){
//			cout << "CLONE SIGNAL" << endl;
//		}
		if (WIFSTOPPED(status) && WSTOPSIG(status) & 0x80){
			return false;
		}
		if (WIFEXITED(status)){
			return true;
		}
		status = ptrace(PTRACE_SYSCALL, stopped, 0, 0); // restart le thread + l'arrête au prochain syscall
		if(status!=0)cerr << "failed wait_for_syscall : " << status << endl;
	}
}


void DebugWindow::startTrace() { // TODO way to kill tracer ?

	cout << "Tracer PID : " << getpid() << endl;

	int temp, stopped;
	processes.insert(mainProcess);

	waitpid(mainProcess->pid, &temp, 0);
	cout << "Child PID : " << mainProcess->pid << endl;
	temp = ptrace(PTRACE_SETOPTIONS, mainProcess->pid, 0, PTRACE_O_TRACESYSGOOD | PTRACE_O_TRACEFORK | PTRACE_O_TRACECLONE);
	if(temp!=0)throw runtime_error("PTRACE_SETOPTIONS failed : "+to_string(temp));
	temp = ptrace(PTRACE_SYSCALL, mainProcess->pid, 0, 0); // restart le thread + l'arrête au prochain syscall
	if(temp!=0)throw runtime_error("FIRST PTRACE_SYSCALL normal-failed : "+to_string(temp)); // TODO C'est normal si ca throw ici !! enlever throw

	mainProcess->treeItem = UI.processTree->topLevelItem(0);
	mainProcess->treeItem->setText(0, QString(to_string(mainProcess->pid).c_str()));

	Process* proc;
	while (true) {
		if (waitProcess(stopped)) {
			proc = nullptr;
			bool empty = true;
			for (Process *p : processes) {
				if (p->running){
					if(p->pid == stopped) {
						p->running = false;
						proc = p;
					}else{
						empty = false;
						break;
					}
				}
			}
			if(proc==nullptr){
				cerr << "Invalid child exited : " << stopped << endl;
				continue;
			}else{
				handleChildExit(*proc);
				if (empty)break;
				else continue;
			}
		}

		proc = nullptr;
		for (Process *p : processes) {
			if (p->pid == stopped) {
				proc = p;
				break;
			}
		}
		if(proc==nullptr){
			cerr << "Received data from invalid child : " << stopped << endl;
			continue;
		}

		if(proc->currentCall==nullptr){ // entry
			temp = ptrace(PTRACE_PEEKUSER, stopped, sizeof(long) * ORIG_RAX);
			proc->currentCall = new Syscall(temp);
			proc->calls.push_back(*proc->currentCall);
			handleCallStart(*proc);
		}else{ // exit
			proc->currentCall->result = ptrace(PTRACE_PEEKUSER, stopped, sizeof(long) * RAX);
			handleCallReturn(*proc);
			proc->currentCall = nullptr;
		}

		temp = ptrace(PTRACE_SYSCALL, stopped, 0, 0); // restart le thread + l'arrête au prochain syscall
		if(temp!=0)cerr << "PTRACE_SYSCALL end-loop failed : " << temp << endl;
	}
	cout << "fin" << endl;
}

void DebugWindow::handleCallReturn(Process& proc) {
	if (config::doChilds && proc.currentCall->id == 56) { // TODO 56 doit pas être hardcodé
		auto *newChild = new Process();
		newChild->pid = proc.currentCall->result;

		processes.insert(newChild);
		int temp = ptrace(PTRACE_SYSCALL, newChild, 0, 0); // restart le thread + l'arrête au prochain syscall
		if (temp != 0) cout << "normal fail : " << temp << endl; // TODO NORMAL ?


		newChild->treeItem = new QTreeWidgetItem;
		newChild->treeItem->setText(0, QString(to_string(newChild->pid).c_str()));
		proc.treeItem->addChild(newChild->treeItem);
	}

	if(displayed->pid==proc.pid){
		addEntryEnd(*proc.currentCall);
	}
}

void DebugWindow::handleCallStart(Process& proc) const {
	if(displayed->pid==proc.pid){
		addEntryStart(*proc.currentCall);
	}

	if(proc.calls.size()>=config::displayLimit){
		proc.calls.pop_back();
		UI.callsLogs->setRowCount(config::displayLimit);
	}

}

void DebugWindow::handleChildExit(Process& proc){
	if(displayed->pid==proc.pid){
		displayed = nullptr;
		// TODO Basculer sur les logs parent/main
	}
}