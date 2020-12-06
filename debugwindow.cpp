#include "UI_debugWindow.cpp"
#include "debugwindow.h"
#include "utils.h"


DebugWindow::DebugWindow(){
    UI.setupUi(this);
    connect(UI.buttonClear, &QAction::triggered, this, &DebugWindow::clear);
    connect(UI.buttonRun, &QAction::triggered, this, &DebugWindow::run);

//    connect(UI.Clear, &QPushButton::clicked, this, &a);
}

void DebugWindow::clear(){
    DebugWindow* win = new DebugWindow();
    win->show();
}


void DebugWindow::run(){
    if(mainProcess!=NULL){ // TODO MAKE CONFIRMATION
        mainProcess->remove();
    }
    mainProcess = new Process;
    mainProcess->trace();
}