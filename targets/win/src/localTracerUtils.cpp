#include "localTracer.h"
#include "configFile.h"

using namespace std;
void LocalTracer::handleCallEntry(Process& proc) {
	if (UI.tableLocked == 0) {
		if (UI.displayed->pid == proc.pid) {
			UI.mutex.lock();
			UI.addEntryStart(proc.currentCall);
//			test1(proc.currentCall);
			UI.mutex.unlock();
		}
		if (proc.calls.size() == config::displayLimit) {
			UI.mutex.lock();
			delete proc.calls.front();
			proc.calls.pop_front();
			UI.QtUI.callLogs->removeRow(config::displayLimit - 1);

			UI.mutex.unlock();
		} else if (proc.calls.size() > config::displayLimit) {
			throw runtime_error("Calls list too large !");
		}
	} else if (UI.tableLocked == 1)UI.tableLocked = 2;
}

void LocalTracer::handleCallExit(Process& proc) {
	if (config::doChilds && proc.currentCall->entry.id == 56) { // TODO 56 doit pas être hardcodé
		Process *newChild = getProcess(proc.currentCall->exit.rval);
		if (newChild == nullptr) {
			newChild = handleChildCreate(proc.currentCall->exit.rval);
		}

		newChild->setupTreeItem(proc.treeItem);
	}

	if (UI.tableLocked==0) {
		d:
		if (UI.displayed->pid == proc.pid) {
			UI.mutex.lock();
			UI.addEntryEnd(proc.currentCall);
//			UI.test2(proc.currentCall);
			UI.mutex.unlock();
		}
	}else if (UI.tableLocked == 1){
		UI.tableLocked = 2;
		goto d;
	}
}