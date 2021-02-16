#include "ui/debugWindow.h"

void DebugWindow::handleCallEntry(Process& proc) {
	if (tableLocked == 0) {
		if (displayed->pid == proc.pid) {
			SIG_AddEntryStart(proc.currentCall);
		}
		if (proc.calls.size() == config.displayLimit) {
//			delete proc.calls.front();
			proc.calls.pop_front();
			SIG_removeLastEntry();

		} else if (proc.calls.size() > config.displayLimit) {
			throw runtime_error("Calls list too large !");
		}
	} else if (tableLocked == 1)tableLocked = 2;
}

void DebugWindow::handleCallExit(Process& proc) {
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
