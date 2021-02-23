#include <iostream>
#include <QMessageBox>
#include <QProcess>
#include <QDebug>

#include "qt/UI_debugWindow.h"
#include "ui/debugWindow.h"

using namespace std;

DebugWindow::DebugWindow(){
	QtUI.setupUi(this);
	tracerConnect = new RealTracer(this);
	config.parseConfig();
	config.assignConfig();
	config.postAssignConfig(*tracerConnect);

	// -----

	connect(QtUI.bRun, &QPushButton::clicked, this, &DebugWindow::ACT_bRun);
	connect(QtUI.bStop, &QPushButton::clicked, this, &DebugWindow::ACT_killProcess);
	connect(QtUI.bClearCallLogs, &QPushButton::clicked, this, &DebugWindow::ACT_bClearCallLogs);
	connect(QtUI.bPauseTable, &QPushButton::clicked, this, &DebugWindow::ACT_bPauseTable);
	connect(QtUI.bProcessSelect, &QPushButton::clicked, this, &DebugWindow::ACT_bChooseProcess);

	connect(QtUI.processTree, &QTreeWidget::itemClicked, this, &DebugWindow::ACT_treeClick);

	connect(this, &DebugWindow::SIG_AddEntryStart, this, &DebugWindow::SLOT_addEntryStart);
	connect(this, &DebugWindow::SIG_addEntryEnd, this, &DebugWindow::SLOT_addEntryEnd);
	connect(this, &DebugWindow::SIG_removeLastEntry, this, &DebugWindow::SLOT_removeLastEntry);

}


void DebugWindow::ACT_killProcess() { // todo virer ?
	if (mainProcess != nullptr) {
		tracerConnect->killProcess();
		mainProcess = nullptr;
	}
}

void DebugWindow::cleanUI() {
	ACT_bClearCallLogs();

	QtUI.processTree->topLevelItem(0)->setText(0, "NA");
	for(auto* i : QtUI.processTree->topLevelItem(0)->takeChildren()) {
		delete i;
	}
}

void DebugWindow::changeView(Process& p) {
	displayed = &p;
//	QtUI.callLogs->clear();
	for(Syscall* call : p.calls){
		SLOT_addEntryStart(call);
		SLOT_addEntryEnd(call);
	}
}

void DebugWindow::SLOT_addEntryStart(Syscall* call) {
	call->guessName(tracerConnect->syscalls);
	QtUI.callLogs->insertRow(0);

	QtUI.callLogs->setItem(0, 0, new QTableWidgetItem(call->name));

	for(int i=0;i<6;i++){
		QtUI.callLogs->setItem(0, i+1, new QTableWidgetItem(QString::number(call->entry.args[i])));
	}
	QtUI.callLogs->setItem(0, 7, new QTableWidgetItem("?"));
}

void DebugWindow::SLOT_addEntryEnd(Syscall* call) {
	if(call->exit.is_error==0xF){
		QtUI.callLogs->item(0, 7)->setText("?");
	}else{
		QtUI.callLogs->item(0, 7)->setText(QString::number(call->exit.rval));
	}
}

void DebugWindow::SLOT_removeLastEntry(){
	QtUI.callLogs->removeRow(config.displayLimit - 1);
}

void DebugWindow::setPID(char* pid) {
	QtUI.labelPID->setText(QString(pid));
}

void DebugWindow::setState(char s) {
	switch(s){
		case 0:{
			QtUI.labelState->setText("NONE");
			break;
		}
		case 1:{
			QtUI.labelState->setText("RUNNING");
			break;
		}
		case 2:{
			QtUI.labelState->setText("EXITED");
			break;
		}
		default:{
			QtUI.labelState->setText("UNKNOWN");
			break;
		}
	}
}