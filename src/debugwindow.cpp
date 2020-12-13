#include <iostream>
#include "UI_debugWindow.h"
#include "utils.h"
#include "debugwindow.h"


DebugWindow::DebugWindow(){
    UI.setupUi(this);
    connect(UI.buttonClear, &QPushButton::clicked, this, &DebugWindow::clear);
    connect(UI.buttonRun, &QPushButton::clicked, this, &DebugWindow::run);

//    connect(UI.Clear, &QPushButton::clicked, this, &a);
}

void DebugWindow::clear(){
	UI.logs->clearContents();

	UI.logs->contentsMargins()
}

void DebugWindow::run(){
    if(mainProcess!=nullptr)mainProcess->remove();


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
