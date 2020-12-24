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
    Process* displayed; // TODO juste mettre le PID ?

    void clear();
	void runCmd();
	void setPID(char* pid);
	void setState(char s);
	void killProcess(bool kil);

    DebugWindow();


	void addEntryStart(Syscall& call);
	void addEntryEnd(Syscall& call);


	unordered_set<Process*> tracees;
	pid_t createProcess();
	int setupProcess(pid_t tracee);
private:
	void startTrace();
	bool waitProcess(pid_t& stopped);
	void handleCallReturn(Process& proc);
	void handleCallStart(Process& proc);

private slots: // a voir pour suppr ?

};

#endif