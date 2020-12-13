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

    void clear();
	void run();
	void addEntry(Syscall& call);
	void setPID(char* pid);
	void setState(char s);

    DebugWindow();

private slots: // a voir pour suppr ?

};

#endif