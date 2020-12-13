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
}

void DebugWindow::run(){
    if(mainProcess!=nullptr)mainProcess->remove();


    QString s = UI.cmd->toPlainText();
    if(s.isEmpty()){
		// TODO ERROR MESSAGE
		return;
    }

    pid_t pid = fork();
    if(pid == 0){ // check if child

    }

    mainProcess = new Process(&pid);
    mainProcess->startTrace();
}
