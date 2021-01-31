#ifndef DEBUGWINDOW
#define DEBUGWINDOW

#include <QMainWindow>
#include <QMutex>
#include <QComboBox>
#include <QStringListModel>
#include <unordered_set>
#include <QStandardItemModel>

#include "UI_debugWindow.h"
#include "processSelector.h"
#include "process.h"
#include "tracer.h"

Q_DECLARE_METATYPE(Syscall*);
class DebugWindow : public QMainWindow
{
    Q_OBJECT

public:
	DebugWindow();

    ProcessSelector test;

private:
	// base
	Ui_DebugWindow QtUI{};
	Tracer* tracer;
    void reset();



	// others ?
	QMutex dataMutex; // for access to QTable and calls list
	char tableLocked = 0;


	// visual
	Process* mainProcess = nullptr;
	Process* displayed = nullptr;
	void setPID(char* pid) const;
	void setState(char s) const;

	void cleanUI();
	void cleanProcess();



	// Window actions
	void playPauseTable();
	void clearCallLogs();
	void bRun();
	void chooseProcess();
	void treeClick(QTreeWidgetItem* item);
	void changeView(Process &p);

private slots:
	void addEntryStart(Syscall*) const;
	void addEntryEnd(Syscall*) const;
signals:
	void test1(Syscall*);
	void test2(Syscall*);
};


#endif