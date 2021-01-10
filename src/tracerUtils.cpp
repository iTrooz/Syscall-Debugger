#include <debugwindow.h>
#include "configFile.h"

using namespace std;

Process* DebugWindow::getProcess(pid_t pid){
//	cout << "--" << endl;
//	int i = 0;
	for (Process *p : processes) {
//		i++;
//		if(i==2){
//			kill(getpid(), SIGSTOP);
//			waitpid(getpid(), nullptr, 0);
//		}
//		cout << p->pid << endl;
		if (p->pid == pid) {
			return p;
		}
	}
	return nullptr;
}

void DebugWindow::killProcesses(){ // TODO hardcoder ca ?
	for(Process* p : processes){
		kill(p->pid, 9);
	}
}

// -----------------------------------

void DebugWindow::handleCallStart(Process& proc) const {
	if(displayed->pid==proc.pid){
		addEntryStart(*proc.currentCall);
	}

	if(proc.calls.size()>=config::displayLimit){
		proc.calls.pop_back();
		UI.callsLogs->setRowCount(config::displayLimit);
	}

}


void DebugWindow::handleCallReturn(Process& proc) {
	if (config::doChilds && proc.currentCall->entry->nr == 56) { // TODO 56 doit pas être hardcodé
		// TODO get le processus parent du child ? (maybe en faisant un syscall depuis le child)
		Process* newChild = getProcess(proc.currentCall->exit->rval);
		if(newChild==nullptr)newChild = handleChildCreate(proc.currentCall->exit->rval);

		newChild->treeItem = new QTreeWidgetItem;
		newChild->treeItem->setText(0, QString(to_string(newChild->pid).c_str()));
		proc.treeItem->addChild(newChild->treeItem);
	}

	if(displayed->pid==proc.pid){
		addEntryEnd(*proc.currentCall);
	}
}

Process* DebugWindow::handleChildCreate(pid_t pid){ // Warning : Still need to apply Tree Item Widget
	auto* newChild = new Process();
	newChild->pid = pid;
	processes.insert(newChild);

	return newChild;
}

void DebugWindow::handleChildExit(Process& proc){

}