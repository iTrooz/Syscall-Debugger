#include <debugwindow.h>
#include <QApplication>
#include "utils.h"
#include "configFile.h"

using namespace std;

DebugWindow* mainWindow;
bool load_syscalls();

int main(int argc, char *argv[]){

    if(!ConfigFile::loadConfig())return 1;
    if(!load_syscalls())return 1;


    QApplication app(argc, argv);

	mainWindow = new DebugWindow;
    mainWindow->show();

    return app.exec();
}


bool load_syscalls(){

}