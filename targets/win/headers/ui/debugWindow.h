#ifndef SD_WIN_DEBUGWINDOW
#define SD_WIN_DEBUGWINDOW

#include <QMainWindow>
#include <QMutex>
#include <QComboBox>
#include <QStringListModel>
#include <QStandardItemModel>
#include <tcpTracerConnect.h>

#include "qt/UI_debugWindow.h"
#include "ui/processSelector.h"
#include "process.h"
#include "connects/tracerConnect.h"
#include "connects/uiConnect.h"

//Q_DECLARE_METATYPE(Syscall*);
class DebugWindow : public QMainWindow, public UIConnect
{
    Q_OBJECT

public:
	// internal
	DebugWindow();
	Ui_DebugWindow QtUI{};
	TracerConnect* tracerConnect = nullptr;

	//
	// ---------- PROCESS MANAGER
	//

	// inherited from UIConnect
	void handleCall(pid_t, __ptrace_syscall_info&) override;
	void handleTracerStart(pid_t) override;
	void handleTracerStartBulk(list<Process*>&) override;
	void handleTracerStop() override;
	Process* handleChildCreate(pid_t) override;
	bool handleChildExit(pid_t) override;

	// related handlers
	void handleCallEntry(Process& proc);
	void handleCallExit(Process& proc);
	void handleTracerStartCommon(Process* proc);

	Process* getProcess(pid_t) const;




	//
	// ----------
	//

	// others ?
	ProcessSelector test;
	QMutex mutex; // for access to QTable and calls list
	char tableLocked = 0;


	// visual
	Process* mainProcess = nullptr;
	Process* displayed = nullptr;
	void setPID(char* pid) const;
	void setState(char s) const;

	void cleanUp();
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