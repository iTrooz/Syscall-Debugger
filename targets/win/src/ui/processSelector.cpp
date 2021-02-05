#include <dirent.h>
#include <iostream>

#include "ui/processSelector.h"

using namespace std;

ProcessSelector::ProcessSelector() {
	UI.setupUi(this);
	updateProcs("");

	connect(UI.lineEdit, &QLineEdit::textEdited, this, &ProcessSelector::updateProcs);
	connect(UI.tableWidget, &QTableWidget::itemDoubleClicked, this, &ProcessSelector::processChosen);

}
void ProcessSelector::processChosen(QTableWidgetItem* item){
	item = UI.tableWidget->item(item->row(), 0);
	bool ok;
	int a = item->text().toInt(&ok);
	if(ok)done(a);
	else{
		cerr << "Got invalid PID from QTable (choosing process) : " << a << endl;
	}
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
				cerr << "failed to open stat file of PID " << pidFile->d_name << endl;
				continue;
			}
			res = fread(buf,1,64,f); // ~number, useless to read more, QtUI would not even display it entirely
			fclose(f);

			pos = std::find(buf, buf+res, ')');
			*pos = '\0';
			pos = std::find(buf, buf+res, '(');
			name = pos+1;

			if(name.contains(searchText, Qt::CaseSensitive)) flag = true;

			if(flag){
				UI.tableWidget->insertRow(0);
				UI.tableWidget->setItem(0, 0, new QTableWidgetItem(pid));
				UI.tableWidget->setItem(0, 1, new QTableWidgetItem(name));

				flag = false;
			}
		}
	}
}