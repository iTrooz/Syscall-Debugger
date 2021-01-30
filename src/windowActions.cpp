#include <thread>
#include <QMessageBox>

#include "UIs/debugWindow.h"

void DebugWindow::playPauseTable(){
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
	for(Process* proc : processes){
		if(proc->treeItem==item){
			changeView(*proc);
			return;
		}
	}
	if(item->text(0)=="NA")return;
	cerr << "NOT SUPPOSED TO HAPPEN : Clicked process not found" << endl;
}

void DebugWindow::clearCallLogs() {
	dataMutex.lock();
	UI.callLogs->clear();
	if(displayed!=nullptr){
		displayed->delCalls();
	}
	dataMutex.unlock();
}

void DebugWindow::bRun(){
	reset();

	QString qs = UI.cmd->text();
	if(qs.isEmpty()){
		QMessageBox msg = QMessageBox();
		msg.setIcon(QMessageBox::Warning);

		msg.setWindowTitle("Warning");
		msg.setText("No command set !");
		msg.show();
		return;
	}

	std::thread thr(&DebugWindow::createProcess, this, qs.toStdString());
	thr.detach();
}

void DebugWindow::chooseProcess(){
	int a = test.exec();
	cout << "Want : " << a << endl;
	std::thread thr(&DebugWindow::setupProcess, this, a);
	thr.detach();
}
