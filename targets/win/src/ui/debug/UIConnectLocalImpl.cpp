#include <csignal>
#include "ui/debugWindow.h"


void DebugWindow::handleTracerStartCommon(Process* proc) { // not impl from tracer, but better to be here than windowUtils.cpp
	mainProcess = proc;
	tracerConnect->processes.push_back(mainProcess);
	mainProcess->treeItem = QtUI.processTree->topLevelItem(0);
	mainProcess->treeItem->setText(0, QString(to_string(mainProcess->pid).c_str()));
	displayed = mainProcess;
}

void DebugWindow::handleTracerStart(pid_t pid) {
	handleTracerStartCommon(new Process(pid));
}

// (maybe obsolete)
// only trigerred with local&&bulk, just after handleTracerStart
// TODO make the distant&&bulk method (directly in TcpTracerConnect ?)
void DebugWindow::handleTracerStartBulk(pid_t main, list<pdata>& bulk) {
	handleTracerStartCommon(new Process(main));
	// here bulk is normally the same as tracerConnect->processes

	Process* tmp;
	list<Process*> stack;
	stack.push_back(mainProcess);
	for(auto p : bulk){
		if(p.valid){
			tmp = new Process(p.pid);
			tmp->setupTreeItem(stack.back()->treeItem);
			stack.push_back(tmp);
			tracerConnect->processes.push_back(tmp);
		}else{
			stack.pop_back();
		}
	}
}

void DebugWindow::handleTracerStop() {
	mainProcess = nullptr;
}

Process* DebugWindow::handleChildCreate(pid_t pid){ // Warning : Still need to apply Tree Item Widget. besoin = get parent parent from here
	if(!config.doChilds)return nullptr;
	Process* newChild = new Process(pid);
	Process* parent = getProcess(getPPID(pid));
	newChild->setupTreeItem(parent->treeItem);

	tracerConnect->processes.push_back(newChild);
	return newChild;
}

bool DebugWindow::handleChildExit(pid_t stopped) { // returns true is there is no more processes

	Process *proc = nullptr;
	bool empty = true;
	for (Process *p : tracerConnect->processes) {
		if (p->running) {
			if (p->pid == stopped) {
				p->running = false;
				proc = p;
			} else {
				empty = false;
			}
			if (!empty && proc != nullptr)break;
		}
	}
	if (proc == nullptr) {
		cerr << "Invalid child exited : " << stopped << endl;
	} else {
		return empty;
	}
	return false;
}


Process* DebugWindow::INT_handleCall(pid_t pid) {
	Process *proc = getProcess(pid);
	if (proc == nullptr) return handleChildCreate(pid);
	else return proc;
}


void DebugWindow::handleCallEntry(pid_t pid, syscall_entry& info) {
	Process *proc = INT_handleCall(pid);
	if (proc->currentCall != nullptr) {
		cerr << "Warning " << pid << " : waiting for syscall exit, got syscall entry" << endl;
		return;
	}
	proc->currentCall = new Syscall();
	proc->currentCall->entry = info;
	proc->calls.push_back(proc->currentCall);

	if (tableLocked == 0) {
		if (displayed->pid == proc->pid) {
			SIG_AddEntryStart(proc->currentCall);
		}
		if (proc->calls.size() == config.displayLimit) {
//			delete proc.calls.front();
			proc->calls.pop_front();
			SIG_removeLastEntry();

		} else if (proc->calls.size() > config.displayLimit) {
			throw runtime_error("Calls list too large !");
		}
	} else if (tableLocked == 1)tableLocked = 2;

}

void DebugWindow::handleCallExit(pid_t pid, syscall_exit& info) {
	Process *proc = INT_handleCall(pid);
	if (proc->currentCall == nullptr) {
		cerr << "Warning " << pid << " : waiting for syscall entry, got syscall exit" << endl;
		return;
	}
	proc->currentCall->exit = info;

	if (tableLocked == 0) {
		d:
		if (displayed->pid == proc->pid) {
			SIG_addEntryEnd(proc->currentCall);
		}
	} else if (tableLocked == 1) {
		tableLocked = 2;
		goto d;
	}

	proc->currentCall = nullptr;
}
