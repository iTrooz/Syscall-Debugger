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

	if(proc.calls.size()==config::displayLimit){
		list<Syscall*>::iterator a = proc.calls.begin();
		a++;
		delete *a;
		proc.calls.pop_front();

		UI.callsLogs->setRowCount(config::displayLimit);
	}else if(proc.calls.size()>config::displayLimit){
		throw runtime_error("Calls list too large !");
	}

}


void DebugWindow::handleCallReturn(Process& proc) {
	if (config::doChilds && proc.currentCall->entry.id == 56) { // TODO 56 doit pas être hardcodé
		Process* newChild = getProcess(proc.currentCall->exit.rval);
		if(newChild==nullptr)newChild = handleChildCreate(proc.currentCall->exit.rval);

		newChild->treeItem = new QTreeWidgetItem;
		newChild->treeItem->setText(0, QString(to_string(newChild->pid).c_str()));
		proc.treeItem->addChild(newChild->treeItem);
	}

//	if(displayed->pid==proc.pid){
//		addEntryEnd(*proc.currentCall);
//	}
}

Process* DebugWindow::handleChildCreate(pid_t pid){ // Warning : Still need to apply Tree Item Widget. besoin = get parent parent from here
	auto* newChild = new Process();
	newChild->pid = pid;
	processes.insert(newChild);

	return newChild;
}

void DebugWindow::handleChildExit(Process& proc){

}