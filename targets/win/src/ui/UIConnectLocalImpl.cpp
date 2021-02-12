#include "ui/debugWindow.h"
#include "configFile.h"
#include "utils.h"

void DebugWindow::handleCall(pid_t pid, __ptrace_syscall_info& info) {
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


// -------- Other handled related // TODO set in a separate file ?

void DebugWindow::handleTracerStartCommon(Process* proc) {
	mainProcess = proc;
	tracerConnect->processes.push_back(mainProcess);
	mainProcess->treeItem = QtUI.processTree->topLevelItem(0);
	mainProcess->treeItem->setText(0, QString(to_string(mainProcess->pid).c_str()));
	displayed = mainProcess;
}

void DebugWindow::handleTracerStart(pid_t pid) {
	handleTracerStartCommon(new Process(pid));
}

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
			tmp = new Process(p.pid, stack.back());
			stack.push_back(tmp);
			tracerConnect->processes.push_back(tmp);
		}else{
			stack.pop_back();
		}
	}
}

void DebugWindow::handleTracerStop() {

}

Process* DebugWindow::handleChildCreate(pid_t pid){ // Warning : Still need to apply Tree Item Widget. besoin = get parent parent from here
	auto* newChild = new Process(pid);
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

void DebugWindow::handleCallEntry(Process& proc) {
	if (tableLocked == 0) {
		if (displayed->pid == proc.pid) {
			mutex.lock();
			addEntryStart(proc.currentCall);
//			test1(proc.currentCall);
			mutex.unlock();
		}
		if (proc.calls.size() == config::displayLimit) {
			mutex.lock();
			delete proc.calls.front();
			proc.calls.pop_front();
			QtUI.callLogs->removeRow(config::displayLimit - 1);

			mutex.unlock();
		} else if (proc.calls.size() > config::displayLimit) {
			throw runtime_error("Calls list too large !");
		}
	} else if (tableLocked == 1)tableLocked = 2;
}

void DebugWindow::handleCallExit(Process& proc) {
	if (config::doChilds && proc.currentCall->entry.id == 56) { // TODO 56 doit pas être hardcodé
		Process *newChild = getProcess(proc.currentCall->exit.rval);
		if (newChild == nullptr) {
			newChild = handleChildCreate(proc.currentCall->exit.rval);
		}

		newChild->setupTreeItem(proc.treeItem);
	}

	if (tableLocked==0) {
		d:
		if (displayed->pid == proc.pid) {
			mutex.lock();
			addEntryEnd(proc.currentCall);
//			QtUI.test2(proc.currentCall);
			mutex.unlock();
		}
	}else if (tableLocked == 1){
		tableLocked = 2;
		goto d;
	}
}

Process* DebugWindow::getProcess(pid_t pid) const {
	for (Process *p : tracerConnect->processes) {
		if (p->pid == pid) {
			return p;
		}
	}
	return nullptr;
}
