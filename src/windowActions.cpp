#include <thread>
#include <QMessageBox>

#include "debugwindow.h"

void DebugWindow::playPauseTable(){

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

void DebugWindow::runCmd(){
	cleanUpUI();
	cleanUpProcess();

	QString qs = UI.cmd->toPlainText();
	if(qs.isEmpty()){
		auto* msg = new QMessageBox();
		msg->setIcon(QMessageBox::Warning);

		msg->setWindowTitle("Warning");
		msg->setText("No command set !");
		msg->show();
		return;
	}

	cmd = std::move(qs.toStdString());

	std::thread thr(&DebugWindow::createProcess, this);
	thr.detach();
}


