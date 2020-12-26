#include <QMainWindow>
#include <unordered_set>
#include "UI_debugWindow.h"
#include "process.h"

#ifndef DEBUGWINDOW
#define DEBUGWINDOW

class DebugWindow : public QMainWindow
{
    Q_OBJECT

public:
    Ui_DebugWindow UI;
    Process* mainProcess = nullptr;
    string cmd;
    Process* displayed = nullptr; // TODO juste mettre le PID ?

    DebugWindow();

    void clearCallsLogs();
	void runCmd();
	void treeClick(QTreeWidgetItem* item);
	void setPID(char* pid);
	void setState(char s);

	void cleanUpUI();
	void cleanUpProcess();
	void changeView(Process &p);

	void addEntryStart(Syscall& call);
	void addEntryEnd(Syscall& call);


	unordered_set<Process*> processes;
	void createProcess();
	void setupProcess(pid_t tracee);
	void killProcess(bool kil);
private:
	void startTrace();
	bool waitProcess(pid_t& stopped);
	void handleCallReturn(Process& proc);
	void handleCallStart(Process& proc);
	void handleChildExit(Process &proc);

private slots: // a voir pour suppr ?

};

#endif