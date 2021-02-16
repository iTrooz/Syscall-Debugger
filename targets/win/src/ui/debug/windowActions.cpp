#include <thread>
#include <QMessageBox>

#include "ui/debugWindow.h"
#include "plateform.h"

using namespace std;

void DebugWindow::ACT_bPauseTable(){
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

void DebugWindow::ACT_treeClick(QTreeWidgetItem* item){
	for(Process* proc : tracerConnect->processes){
		if(proc->treeItem==item){
			changeView(*proc);
			return;
		}
	}
	if(item->text(0)=="NA")return;
	cerr << "NOT SUPPOSED TO HAPPEN : Clicked process not found" << endl;
}

void DebugWindow::ACT_bClearCallLogs() {
	QtUI.callLogs->clearContents();
	if(displayed!=nullptr){
		displayed->delCalls();
	}
}

bool DebugWindow::preRunTests(){
	if(mainProcess!=nullptr) {
		if (config.warnARunning) {
			auto msg = QMessageBox();
			msg.setIcon(QMessageBox::Warning);
			msg.setWindowTitle("Process already running");
			QString qs;
			qs.push_back("A process is already being traced !");
			qs.push_back("\n");
			qs.push_back("Click \"Kill\" button to kill it, and continue the action");
			qs.push_back("\n");
			qs.push_back("Click \"Cancel\" button to abort action");
			msg.setText(qs);
			// do not switch order : will switch .exec values
			msg.setDefaultButton(msg.addButton("Cancel", QMessageBox::ButtonRole::RejectRole));
			msg.addButton("Kill", QMessageBox::ButtonRole::AcceptRole);
			if (!msg.exec())return false;
		}

		tracerConnect->killProcess();
		cleanUI();
		for (auto *proc : tracerConnect->processes) {
			delete proc;
		}
	}
	return true;
}

void DebugWindow::ACT_bRun(){
	QString qs = QtUI.cmd->text();
	if(qs.isEmpty()){
		QMessageBox msg = QMessageBox();
		msg.setIcon(QMessageBox::Warning);

		msg.setWindowTitle("No command set !");
		msg.setText("You didn't set any command to run !");
		msg.show();
		return;
	}
	if(preRunTests()){
		tracerConnect->createProcess(qs.toStdString());
	}
}

void DebugWindow::ACT_bChooseProcess(){
	if(can_ptrace_running()){
		ProcessSelector select;
		int a = select.exec();
		if(a==0)return;

		if(preRunTests()) {
			tracerConnect->setupProcess(a);
		}
	}else{
		auto msg = QMessageBox();
		msg.setIcon(QMessageBox::Critical);
		msg.setText("CAP_SYS_PTRACE capability not activated");
		QString qs;
		qs.push_back("You can activate it by the following ways :");
		qs.push_back("\n");
		qs.push_back("- run the program using sudo");
		qs.push_back("\n");
		qs.push_back("- add the CAP_SYS_PTRACE capability to the executable");
		qs.push_back("\n\n");
		qs.push_back("Click the \"Add capability\" button to try to automatically add the capability to the executable, and stop the program");
		msg.setInformativeText(qs);
		// do not switch order : will switch .exec values
		msg.setDefaultButton(msg.addButton("Cancel", QMessageBox::ButtonRole::RejectRole));
		msg.addButton("Add capability", QMessageBox::ButtonRole::AcceptRole);
		if(msg.exec()){
			system(("pkexec setcap CAP_SYS_PTRACE+ep '"+execPath+"'").c_str());
			exit(0);
		}
	}
}
