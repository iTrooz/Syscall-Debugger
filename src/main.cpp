#include <debugwindow.h>
#include <QApplication>
#include <iostream>
#include "utils.h"

using namespace std;

DebugWindow* mainWindow;

int main(int argc, char *argv[]){
    QApplication app(argc, argv);

	mainWindow = new DebugWindow;
    mainWindow->show();

    return app.exec();
}
