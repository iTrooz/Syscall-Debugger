#include "ui/debugWindow.h"

Process* DebugWindow::getProcess(pid_t pid) const {
	for (Process *p : tracerConnect->processes) {
		if (p->pid == pid) {
			return p;
		}
	}
	return nullptr;
}
