#include <thread>
#include <QMessageBox>

#include "ui/debugWindow.h"
#include "plateform.h"
#include "utils.h"

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
	for(Process* proc : tracerConnect->processes){
		if(proc->treeItem==item){
			changeView(*proc);
			return;
		}
	}
	if(item->text(0)=="NA")return;
	cerr << "NOT SUPPOSED TO HAPPEN : Clicked process not found" << endl;
}

void DebugWindow::bClearCallLogs() {
	QtUI.callLogs->clearContents();
	if(displayed!=nullptr){
		displayed->delCalls();
	}
}

void DebugWindow::bRun(){
	cleanUp();

	QString qs = QtUI.cmd->text();
	if(qs.isEmpty()){
		QMessageBox msg = QMessageBox();
		msg.setIcon(QMessageBox::Warning);

		msg.setWindowTitle("Warning");
		msg.setText("No command set !");
		msg.show();
		return;
	}

	tracerConnect->createProcess(qs.toStdString());
}

void DebugWindow::bChooseProcess(){
	if(can_ptrace_running()){
		ProcessSelector select;
		int a = select.exec();
		if(a==0)return;

		tracerConnect->setupProcess(a);
	}else{
		auto msg = QMessageBox();
		msg.setIcon(QMessageBox::Critical);
		msg.setText("CAP_SYS_PTRACE capability not activated");
		QString ps;
		ps.push_back("You can activate it by the following ways :");
		ps.push_back("\n");
		ps.push_back("- run the program using sudo");
		ps.push_back("\n");
		ps.push_back("- add the CAP_SYS_PTRACE capability to the executable");
		ps.push_back("\n\n");
		ps.push_back("Click the \"Add capability\" button to try to automatically add the capability to the executable, and stop the program");
		msg.setInformativeText(ps);
		// do not switch order : will switch .exec values
		msg.setDefaultButton(msg.addButton("Cancel", QMessageBox::ButtonRole::RejectRole));
		msg.addButton("Add capability", QMessageBox::ButtonRole::AcceptRole);
		if(msg.exec()){
			system(("pkexec setcap CAP_SYS_PTRACE+ep '"+execPath+"'").c_str());
			exit(0);
		}
	}
}
