#include <QMainWindow>
#include <unordered_set>
#include <QMutex>

#include "UI_debugWindow.h"
#include "process.h"

#ifndef DEBUGWINDOW
#define DEBUGWINDOW

class DebugWindow : public QMainWindow
{
    Q_OBJECT

public:
    Ui_DebugWindow UI{};
    Process* mainProcess = nullptr;
    string cmd;
    Process* displayed = nullptr; // TODO juste mettre le PID ?

    DebugWindow();

    void clearcallLogs();
	void runCmd();
	void treeClick(QTreeWidgetItem* item);
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
private slots: // a voir pour suppr ?

};

#endif