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
	model->setRowCount(0);

	DIR* dir = opendir("/proc");
	if(dir==nullptr){
		cerr << "Failed to open /proc directory" << endl;
		return;
	}

	dirent* pidFile;
	QString pid;
	QString name;

	bool flag = false;
	char buf[128];
	int res;
	char* pos;
	int i = 0;
	while((pidFile = readdir(dir))){
		if(atoi(pidFile->d_name)){

			pid = pidFile->d_name;
			if(pid.startsWith(str, Qt::CaseInsensitive)) flag = true;

			FILE* f = fopen(("/proc/"+pid.toStdString()+"/stat").c_str(), "r");
			if(f==nullptr){
				cerr << "failed to open stat file of pid " << pidFile->d_name << endl;
				continue;
			}

			res = fread(buf,1,64,f); // useless to read more, UI would not even display it entirely
			pos = std::find(buf, buf+res, ')');
			*pos = '\0';
			pos = std::find(buf, buf+res, '(');
			name = pos+1;

			if(name.contains(str, Qt::CaseSensitive)) flag = true;

			if(flag){
				model->setRowCount(i+1);
				model->setData(model->index(i, 0), pid);
				model->setData(model->index(i, 1), name);

				flag = false;
				i++;
			}
		}
	}
}