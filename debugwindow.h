#include <QMainWindow>
#include "UI_debugWindow.cpp"
#include "process.h"

class DebugWindow : public QMainWindow
{
    Q_OBJECT

public:
    Ui_DebugWindow UI;
    Process* mainProcess;

    void clear();
    void run();

    DebugWindow();

private slots: // a voir pour suppr ?

};
