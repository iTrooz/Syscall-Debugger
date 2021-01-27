#ifndef DEBUGWINDOW
#define DEBUGWINDOW

#include <QMainWindow>
#include <QMutex>
#include <unordered_set>

#include "UI_debugWindow.h"
#include "process.h"

class DebugWindow : public QMainWindow
{
    Q_OBJECT

public:
	DebugWindow();

private:
	// base
    void reset();


	// tracer things
	void startTracer();
	void stopTracer();
	pid_t tracer = -1;
	bool runTracer = false;

	bool waitProcess(pid_t& stopped);
	void handleCallReturn(Process& proc);
	void handleCallStart(Process& proc);
	bool handleChildExit(pid_t stopped);
	Process* handleChildCreate(pid_t pid);


	// others ?
	QMutex dataMutex; // for access to QTable and calls list
	char tableLocked = 0;


	// visual
	Ui_DebugWindow UI{};
	Process* mainProcess = nullptr;
	Process* displayed = nullptr;
	void setPID(char* pid) const;
	void setState(char s) const;

	void cleanUI();
	void cleanProcess();
	void addEntryStart(Syscall& call) const;
	void addEntryEnd(Syscall& call) const;


	// process
	unordered_set<Process*> processes;
	void createProcess(const string& cmd);
	void setupProcess(pid_t tracee);
	Process* getProcess(pid_t pid);
	void killProcesses();


	// Window actions
	void playPauseTable();
	void clearCallLogs();
	void bRun();
	void chooseProcess();
	void treeClick(QTreeWidgetItem* item);
	void changeView(Process &p);

private slots: // a voir pour suppr ?

};

#endif