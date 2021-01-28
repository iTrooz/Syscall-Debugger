#include <thread>
#include <QMessageBox>

#include "debugwindow.h"

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

}

#include <dirent.h>

void DebugWindow::searchProcess(const QString& str){
	QStringList list;

//	DIR* dir = opendir("/pid");
//	if(dir== nullptr){
//		cerr << "Failed to open /pid directory" << endl;
//		return;
//	}
//
//	dirent* pid;
//	string s;
//	char buf[128];
//	int res;
//	while((pid = readdir(dir))){
//		if(atoi(pid->d_name)){
//			s = pid->d_name;
//			if(s.starts_with(str.toStdString())){
//				list << s;
//
//			}
//			// pid check
//			string::start
//			FILE* f = fopen(("/pid/" + string(pid->d_name) + "/stat").c_str(), "r");
//			res = fread(buf,1,128,f);
//
//		}
//	}

//	list << "aaaa";
//	list << "bbbb";
//	list << "cccc";
//
//	model->setStringList(list);
}