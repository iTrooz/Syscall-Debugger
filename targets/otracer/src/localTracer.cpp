#include <string>

#include "localTracer.h"

using namespace std;

void LocalTracer::handleTraceStart() {
	Tracer::handleTraceStart();
	mainProcess->treeItem = UI.processTree->topLevelItem(0);
	mainProcess->treeItem->setText(0, QString(to_string(mainProcess->pid).c_str()));
	displayed = mainProcess;
}

void LocalTracer::handleCallStart(pid_t pid) {
	if (tableLocked == 0) {
		if (displayed->pid == proc.pid) {
			dataMutex.lock();
			addEntryStart(proc.currentCall);
			test1(proc.currentCall);
			dataMutex.unlock();
		}
		if (proc.calls.size() == config::displayLimit) {
			dataMutex.lock();

			delete proc.calls.front();
			proc.calls.pop_front();
			UI.callLogs->removeRow(config::displayLimit - 1);

			dataMutex.unlock();
		} else if (proc.calls.size() > config::displayLimit) {
			throw runtime_error("Calls list too large !");
		}
	} else if (tableLocked == 1)tableLocked = 2;
}
void LocalTracer::handleCallExit(Process& proc) {
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
			dataMutex.lock();
			test2(proc.currentCall);
//			addEntryEnd(proc.currentCall);
			dataMutex.unlock();
		}
	}else if (tableLocked == 1){
		tableLocked = 2;
		goto d;
	}

}