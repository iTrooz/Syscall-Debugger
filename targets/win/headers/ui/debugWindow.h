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
	void handleCall(pid_t, native_syscall_info&) override;
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

	void cleanUI();
	void changeView(Process &p);
	bool preRunTests();


	// Window actions
	void ACT_bClearCallLogs();
	void ACT_bPauseTable();
	void ACT_bRun();
	void ACT_bChooseProcess();
	void ACT_treeClick(QTreeWidgetItem* item);
	void ACT_killProcess();

private slots:
	void SLOT_addEntryStart(Syscall*);
	void SLOT_addEntryEnd(Syscall*);
	void SLOT_removeLastEntry();
signals:
	void SIG_AddEntryStart(Syscall*);
	void SIG_addEntryEnd(Syscall*);
	void SIG_removeLastEntry();

};


#endif