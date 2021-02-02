#include <string>
#include <iostream>

#include "localTracer.h"
#include "tracerUtils.h"
#include "configFile.h"

using namespace std;

void LocalTracer::handleTracerStart(pid_t pid) {

	Process* mainProcess = new Process(pid);
	recurPIDs(&processes, mainProcess);

	processes.insert(mainProcess);

	mainProcess->treeItem = UI.QtUI.processTree->topLevelItem(0);
	mainProcess->treeItem->setText(0, QString(to_string(mainProcess->pid).c_str()));
	UI.displayed = mainProcess;
}

void LocalTracer::handleTracerStop() {

}

Process* LocalTracer::handleChildCreate(pid_t pid){ // Warning : Still need to apply Tree Item Widget. besoin = get parent parent from here
	auto* newChild = new Process(pid);
	processes.insert(newChild);
	return newChild;
}


bool LocalTracer::handleChildExit(pid_t stopped) { // returns true is there is no more processes

	Process *proc = nullptr;
	bool empty = true;
	for (Process *p : processes) {
		if (p->running) {
			if (p->pid == stopped) {
				p->running = false;
				proc = p;
			} else {
				empty = false;
			}
			if (!empty && proc != nullptr)break; // TODO jsp si vraiment opti
		}
	}
	if (proc == nullptr) {
		cerr << "Invalid child exited : " << stopped << endl;
	} else {
		return empty;
	}
	return false;
}


void LocalTracer::handleCall(pid_t pid, __ptrace_syscall_info& info) {
	Process* proc = getProcess(pid);
	if(proc==nullptr){
		proc = handleChildCreate(pid);
	}

	if (info.op == PTRACE_SYSCALL_INFO_ENTRY) {
		if (proc->currentCall != nullptr) {
			cerr << "Warning " << pid << " : waiting for syscall exit, got syscall entry" << endl;
		} else {
			proc->currentCall = new Syscall();
			proc->currentCall->entry = info;
			proc->calls.push_back(proc->currentCall);

			handleCallEntry(*proc);
		}

	} else if (info.op == PTRACE_SYSCALL_INFO_EXIT) {
		if (proc->currentCall == nullptr) {
			cerr << "Warning " << pid << " : waiting for syscall entry, got syscall exit" << endl;
		} else {
			proc->currentCall->exit = info;

			handleCallExit(*proc);

			proc->currentCall = nullptr;
		}
	} else {
		cerr << "Got unsupported OP " << to_string(info.op) << endl;
	}
}
