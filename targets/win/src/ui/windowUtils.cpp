#include "ui/debugWindow.h"
#include "configFile.h"

void DebugWindow::handleCallEntry(Process& proc) {
	if (tableLocked == 0) {
		if (displayed->pid == proc.pid) {
			SIG_AddEntryStart(proc.currentCall);
		}
		if (proc.calls.size() == config::displayLimit) {
//			delete proc.calls.front();
			proc.calls.pop_front();
			SIG_removeLastEntry();

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
			SIG_addEntryEnd(proc.currentCall);
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
