#include <thread>
#include <QMessageBox>

#include "ui/debugWindow.h"

using namespace std;

void DebugWindow::bPauseTable(){
	/*
	 * 0 = enabled
	 * 1 waiting for syscall end/disabled
	 * 2 disabled
	 */
	if(tableLocked==0){ // need to lock
		tableLocked = 1;
	}else{
		tableLocked = 0;
		changeView(*displayed);
	}
}

void DebugWindow::treeClick(QTreeWidgetItem* item){
	for(Process* proc : tracerConnection->processes){
		if(proc->treeItem==item){
			changeView(*proc);
			return;
		}
	}
	if(item->text(0)=="NA")return;
	cerr << "NOT SUPPOSED TO HAPPEN : Clicked process not found" << endl;
}

void DebugWindow::bClearCallLogs() {
	mutex.lock();
	QtUI.callLogs->clear();
	if(displayed!=nullptr){
		displayed->delCalls();
	}
	mutex.unlock();
}

void DebugWindow::bRun(){
	reset();

	QString qs = QtUI.cmd->text();
	if(qs.isEmpty()){
		QMessageBox msg = QMessageBox();
		msg.setIcon(QMessageBox::Warning);

		msg.setWindowTitle("Warning");
		msg.setText("No command set !");
		msg.show();
		return;
	}

	tracerConnection->createProcess(qs.toStdString());
}

void DebugWindow::bChooseProcess(){
	int a = test.exec();
	cout << "Want : " << a << endl;
	tracerConnection->setupProcess(a);
}
