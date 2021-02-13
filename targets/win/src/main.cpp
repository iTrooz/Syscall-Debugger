#include <QApplication>
#include <QMessageBox>
#include <iostream>

#include "ui/debugWindow.h"
#include "configFile.h"
#include "configUtils.h"
#include "utils.h"

#include "plateform.h"

using namespace std;

DebugWindow* mainWindow;
unordered_map<int, QString*> syscalls;
string execPath;

void load_syscalls();


int main(int argc, char** argv){
	execPath = argv[0];
	QApplication app(argc, argv);

	try{
		parseConfig();
		assignConfig();
		load_syscalls();
		postAssignConfig();

	}catch(exception& e) {
		cerr << "An error occured !" << endl;
		cerr << e.what() << endl;

		auto msg = QMessageBox();
		msg.setIcon(QMessageBox::Critical);
		msg.setText("Config loading error");

		msg.setInformativeText(QString::fromStdString("Raison : "+(string) e.what()));
		msg.setWindowTitle("Syscall Debugger - Startup Error");
		msg.show();
		return QApplication::exec();
	}


	mainWindow = new DebugWindow;
    mainWindow->show();

    return QApplication::exec();
}


void load_syscalls(){
	ifstream file(config::syscallPath);

	string line;
	size_t t;
	while (getline(file,line)) {

		if(line.size()<13)continue;
		if(line.substr(0, 13)!="#define __NR_")continue;
		line = line.erase(0, 13);

		t = line.find(' ');
		if(t==string::npos)continue;

		try{
			QString* qs = new QString(line.substr(0, t).c_str());
			syscalls.insert({stoi(line.substr(t+1)), qs});
		}catch(invalid_argument& e){
			throw runtime_error("Invalid number "+line.substr(t+1)+" for syscall"+line.substr(0, t));
		}
	}
}