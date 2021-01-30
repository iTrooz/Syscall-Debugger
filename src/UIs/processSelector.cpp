#include <dirent.h>
#include <iostream>

#include "UIs/processSelector.h"

using namespace std;

ProcessSelector::ProcessSelector() {
	UI.setupUi(this);
	updateProcs("");

	connect(UI.lineEdit, &QLineEdit::textEdited, this, &ProcessSelector::updateProcs);

}

void ProcessSelector::updateProcs(const QString& searchText) {

	UI.tableWidget->setRowCount(0);

	DIR* dir = opendir("/proc");
	if(dir==nullptr){
		cerr << "Failed to open /proc directory" << endl;
		return;
	}

	dirent* pidFile;
	QString pid;
	QString name;

	bool flag = false;
	char buf[128];
	int res;
	char* pos;
	while((pidFile = readdir(dir))){
		if(atoi(pidFile->d_name)){

			pid = pidFile->d_name;
			if(pid.startsWith(searchText, Qt::CaseInsensitive)) flag = true;

			FILE* f = fopen(("/proc/"+pid.toStdString()+"/stat").c_str(), "r");
			if(f==nullptr){
				cerr << "failed to open stat file of pid " << pidFile->d_name << endl;
				continue;
			}

			res = fread(buf,1,64,f); // useless to read more, UI would not even display it entirely
			pos = std::find(buf, buf+res, ')');
			*pos = '\0';
			pos = std::find(buf, buf+res, '(');
			name = pos+1;

			if(name.contains(searchText, Qt::CaseSensitive)) flag = true;

			if(flag){
				// TODO addRow existe
				UI.tableWidget->insertRow(0);
				UI.tableWidget->setItem(0, 0, new QTableWidgetItem(pid));
				UI.tableWidget->setItem(0, 1, new QTableWidgetItem(name));

				flag = false;
			}
		}
	}
}