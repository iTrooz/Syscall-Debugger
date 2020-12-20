#include <QMainWindow>
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
    string* cmd;
    pid_t current;

    void clear();
	void runCmd();
	void addEntry(Syscall& call);
	void setPID(char* pid);
	void setState(char s);

    DebugWindow();

private slots: // a voir pour suppr ?

};

#endif