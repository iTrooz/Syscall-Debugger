//#include "utils.h"
#include "debugWindow.h"

#include <iostream>
#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    DebugWindow win;
    win.show();

    return app.exec();
}
