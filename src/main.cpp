#include <debugwindow.h>
#include <QApplication>
#include <QMessageBox>
#include <iostream>
#include "utils.h"
#include "configFile.h"
#include "configUtils.h"

using namespace std;

DebugWindow* mainWindow;
unordered_map<int, string> syscalls;
void load_syscalls();

// TODO syscallPath : path different for Ubuntu/(Manjaro|Arch)/Kali (others?)

int main(int argc, char *argv[]){
	cout << "App PID : " << getpid() << endl;
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
			syscalls.insert({stoi(line.substr(t+1)), line.substr(0, t)});
		}catch(invalid_argument& e){
			throw runtime_error("Invalid number "+line.substr(t+1)+" for syscall"+line.substr(0, t));
		}
	}
}