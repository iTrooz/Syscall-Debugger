#include <debugwindow.h>
#include <QApplication>
#include <iostream>

using namespace std;

int maina(int argc, char *argv[]){
    QApplication app(argc, argv);

    DebugWindow win;
    win.show();

    return app.exec();
}

int main(int argc, char *argv[]){
	Process p;
	string s = "ls -al";
	p.createProcess(s);
	p.startTrace();
}