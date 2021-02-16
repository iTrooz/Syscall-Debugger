#ifndef SD_WIN_DEBUGWINDOW
#define SD_WIN_DEBUGWINDOW

#include <QMainWindow>
#include <QMutex>
#include <QComboBox>
#include <QStringListModel>
#include <QStandardItemModel>
#include <connect/tcpTracerConnect.h>

#include "qt/UI_debugWindow.h"
#include "ui/processSelector.h"
#include "process.h"
#include "connect/tracerConnect.h"
#include "connect/uiConnect.h"
#include "config/winConfig.h"

//Q_DECLARE_METATYPE(Syscall*);
class DebugWindow : public QMainWindow, public UIConnect
{
    Q_OBJECT

public:
	// base
	DebugWindow();
    WinConfig config;
	Ui_DebugWindow QtUI{};
	TracerConnect* tracerConnect = nullptr;


	//
	// ---------- PROCESS MANAGER
	//

	// inherited from UIConnect
	void handleCall(pid_t, __ptrace_syscall_info&) override;
	void handleTracerStart(pid_t) override;
	void handleTracerStartBulk(pid_t, list<pdata>&) override;
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
	char tableLocked = 0;


	// visual
	Process* mainProcess = nullptr; // null mean no process running
	Process* displayed = nullptr;
	void setPID(char* pid);
	void setState(char s);

	void cleanUp();
	void cleanUI();
//	void killProcess();
	void changeView(Process &p);
	bool preRunTests();


	// Window actions
	void bClearCallLogs();
	void bPauseTable();
	void bRun();
	void bChooseProcess();
	void treeClick(QTreeWidgetItem* item);

private slots:
	void addEntryStart(Syscall*);
	void addEntryEnd(Syscall*);
	void removeLastEntry();
signals:
	void SIG_AddEntryStart(Syscall*);
	void SIG_addEntryEnd(Syscall*);
	void SIG_removeLastEntry();

};


#endif