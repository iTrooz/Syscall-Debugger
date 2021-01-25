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
    Ui_DebugWindow UI{};
    Process* mainProcess = nullptr;
    string cmd;
    Process* displayed = nullptr; // TODO juste mettre le PID ?

    DebugWindow();

	void setPID(char* pid) const;
	void setState(char s) const;

	void cleanUpUI();
	void cleanUpProcess();
	void changeView(Process &p);

	void addEntryStart(Syscall& call) const;
	void addEntryEnd(Syscall& call) const;


	unordered_set<Process*> processes;
	void createProcess();
	void setupProcess(pid_t tracee);
	void killProcesses();
	Process* getProcess(pid_t pid);
private:
	void startTrace();
	bool waitProcess(pid_t& stopped);
	void handleCallReturn(Process& proc);
	void handleCallStart(Process& proc);
	bool handleChildExit(pid_t stopped);
	Process* handleChildCreate(pid_t pid);

	QMutex dataMutex; // for access to QTable and calls list

	// Window actions
	void playPauseTable();
	void clearCallLogs();
	void runCmd();
	void treeClick(QTreeWidgetItem* item);

private slots: // a voir pour suppr ?

};

#endif