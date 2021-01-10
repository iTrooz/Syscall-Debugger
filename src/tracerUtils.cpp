#include <debugwindow.h>
#include <iostream>
#include "configFile.h"

using namespace std;

void DebugWindow::handleCallStart(Process& proc) const {
	if (config::doChilds && proc.currentCall->entry->nr == 56) {
		cout << "Child creation init" << endl;
		fflush(stdout);
	}
		if(displayed->pid==proc.pid){
		addEntryStart(*proc.currentCall);
	}

	if(proc.calls.size()>=config::displayLimit){
		proc.calls.pop_back();
		UI.callsLogs->setRowCount(config::displayLimit);
	}

}

void DebugWindow::handleChildExit(Process& proc){

}


void DebugWindow::handleCallReturn(Process& proc) {
	if (config::doChilds && proc.currentCall->entry->nr == 56) { // TODO 56 doit pas être hardcodé
		int temp;
		auto* newChild = new Process();
		newChild->pid = proc.currentCall->exit->rval;
		processes.insert(newChild);

		cout << "New child " << to_string(newChild->pid) << endl;
		fflush(stdout);

		kill(SIGSTOP, newChild->pid);
		waitpid(newChild->pid, &temp, 0);
		temp = ptrace(PTRACE_SYSCALL, newChild->pid, 0, 0); // restart le thread + l'arrête au prochain syscall

		if (temp != 0){
			cerr << "normal fail : " << temp << endl; // TODO NORMAL ?
//			cerr << explain_ptrace(PTRACE_SYSCALL, newChild->pid, 0, 0) << endl;
		}
		fflush(stderr);


		newChild->treeItem = new QTreeWidgetItem;
		newChild->treeItem->setText(0, QString(to_string(newChild->pid).c_str()));
		proc.treeItem->addChild(newChild->treeItem);
	}

	if(displayed->pid==proc.pid){
		addEntryEnd(*proc.currentCall);
	}
}