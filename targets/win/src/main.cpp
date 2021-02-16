#include <QApplication>
#include <QMessageBox>
#include <iostream>

#include "ui/debugWindow.h"

#include "plateform.h"

using namespace std;

DebugWindow* mainWindow;
string execPath;

int main(int argc, char** argv){
	execPath = argv[0];
	QApplication app(argc, argv);

	try{
		mainWindow = new DebugWindow;
		mainWindow->show();
	}catch(exception& e) {
		cerr << "An error occured !" << endl;
		cerr << e.what() << endl;

		auto msg = QMessageBox();
		msg.setIcon(QMessageBox::Critical);
		msg.setText("Config loading error");

		msg.setInformativeText(QString::fromStdString("Raison : "+(string) e.what()));
		msg.setWindowTitle("Syscall Debugger - Startup Error");
		msg.show();
	}
    return QApplication::exec();
}