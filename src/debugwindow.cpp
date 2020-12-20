#include <iostream>
#include "UI_debugWindow.h"
#include "utils.h"
#include "debugwindow.h"


DebugWindow::DebugWindow(){
    UI.setupUi(this);
    connect(UI.buttonClear, &QPushButton::clicked, this, &DebugWindow::clear);
    connect(UI.buttonRun, &QPushButton::clicked, this, &DebugWindow::run);

}

void DebugWindow::clear(){
	UI.logs->clearContents();
}

void DebugWindow::run(){
    if(mainProcess!=nullptr){
    	cout << "deleting process.." << endl;
    	mainProcess->remove();
    }


    QString qs = UI.cmd->toPlainText();
    if(qs.isEmpty()){
		// TODO ERROR MESSAGE
		return;
    }

    mainProcess = new Process();
    string s = qs.toStdString();
    mainProcess->createProcess(s);
    mainProcess->startTrace();
}

void DebugWindow::addEntry(Syscall& call) {
	UI.logs->insertRow(0);

	UI.logs->setItem(0, 0, new QTableWidgetItem(call.name.c_str()));
	UI.logs->setItem(0, 1, new QTableWidgetItem(to_string(call.result).c_str()));
}

void DebugWindow::setPID(char* pid){
	UI.labelPID->setText(QString(pid));
}

void DebugWindow::setState(char s){
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