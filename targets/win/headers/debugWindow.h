#ifndef DEBUGWINDOW
#define DEBUGWINDOW

#include <QMainWindow>
#include <QMutex>
#include <QComboBox>
#include <QStringListModel>
#include <unordered_set>
#include <QStandardItemModel>

#include "qt/UI_debugWindow.h"
#include "processSelector.h"
#include "process.h"
#include "tracerCore.h"

//Q_DECLARE_METATYPE(Syscall*);
class DebugWindow : public QMainWindow
{
    Q_OBJECT

public:
	// base
	DebugWindow();
    void reset();
	Ui_DebugWindow QtUI{};
	Tracer* tracerConnection;


	// others ?
	ProcessSelector test;
	QMutex mutex; // for access to QTable and calls list
	char tableLocked = 0;


	// visual
	Process* mainProcess = nullptr;
	Process* displayed = nullptr;
	void setPID(char* pid) const;
	void setState(char s) const;

	void cleanUI();
	void killProcess();
	void changeView(Process &p);


	// Window actions
	void bClearCallLogs();
	void bPauseTable();
	void bRun();
	void bChooseProcess();
	void treeClick(QTreeWidgetItem* item);

//public slots:
	void addEntryStart(Syscall*) const;
	void addEntryEnd(Syscall*) const;
//signals:
//	void test1(Syscall*);
//	void test2(Syscall*);

};


#endif