#include <iostream>
#include <QMessageBox>
#include <QProcess>
#include "UI_debugWindow.h"
#include "utils.h"
#include "debugwindow.h"
#include "thread"

void DebugWindow::cleanUpProcess() {
	if (mainProcess != nullptr) {

		remProcess(true);

		mainProcess->treeItem = nullptr;
		for (auto *proc : processes) {
			fflush(stdout);
			delete proc;
		}

		processes.clear();
	}
}

void DebugWindow::cleanUpUI() const{
	UI.callsLogs->setRowCount(0);
	UI.processTree->topLevelItem(0)->setText(0, "NA");
	for(auto* i : UI.processTree->topLevelItem(0)->takeChildren()) {
		delete i;
	}
	UI.stdLog->clear();
}

DebugWindow::DebugWindow(){
    UI.setupUi(this);
    connect(UI.buttonClear, &QPushButton::clicked, this, &DebugWindow::clearCallsLogs);
    connect(UI.buttonRun, &QPushButton::clicked, this, &DebugWindow::runCmd);
    connect(UI.processTree, &QTreeWidget::itemClicked, this, &DebugWindow::treeClick);

	QHeaderView* header = UI.callsLogs->horizontalHeader();
	header->setSectionResizeMode(QHeaderView::Stretch);
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

void DebugWindow::changeView(Process& p) const {
	UI.callsLogs->setRowCount(0);
	for(Syscall* call : p.calls){
		addEntryStart(*call);
		addEntryEnd(*call);
	}
}

void DebugWindow::clearCallsLogs() const {
	UI.callsLogs->setRowCount(0);
	if(displayed!=nullptr){
		displayed->delCalls();
	}
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

//    QProcess qp;
//    qp.pid

    cmd = std::move(qs.toStdString());

    std::thread thr(&DebugWindow::createProcess, this);
    thr.detach();
}

void DebugWindow::addEntryStart(Syscall& call) const {
	UI.callsLogs->insertRow(0);
	UI.callsLogs->setItem(0, 0, new QTableWidgetItem(call.name->c_str()));

	// TODO format for arg type
	for(int i=0;i<6;i++){
		UI.callsLogs->setItem(0, i+1, new QTableWidgetItem(to_string(call.entry.args[i]).c_str()));
	}
	UI.callsLogs->setItem(0, 7, new QTableWidgetItem("?"));
}

void DebugWindow::addEntryEnd(Syscall& call) const{
	if(call.exit.op==255){
		UI.callsLogs->setItem(0, 7, new QTableWidgetItem("?"));
	}else{
		UI.callsLogs->setItem(0, 7, new QTableWidgetItem(to_string(call.exit.rval).c_str()));
	}
}

void DebugWindow::setPID(char* pid) const{
	UI.labelPID->setText(QString(pid));
}

void DebugWindow::setState(char s) const{
	switch(s){
		case 0:{
			UI.labelState->setText("NONE");
			break;
		}
		case 1:{
			UI.labelState->setText("RUNNING");
			break;
		}
		case 2:{
			UI.labelState->setText("EXITED");
			break;
		}
		default:{
			UI.labelState->setText("UNKNOWN");
			break;
		}
	}
}