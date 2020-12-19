#include <debugwindow.h>
#include <QApplication>
#include <iostream>
#include "utils.h"
#include "configFile.h"

using namespace std;

DebugWindow* mainWindow;
bool load_syscalls();

int main(int argc, char *argv[]){

    if(!config::loadConfig())return 1;
    if(!load_syscalls())return 1;
    // TODO switch to check errors

//    cout << config::syscallPath << endl;

//    QApplication app(argc, argv);

//	  mainWindow = new DebugWindow;
//    mainWindow->show();

//    return app.exec();

	return 0;
}


bool load_syscalls(){
	return true;
}