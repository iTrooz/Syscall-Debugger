#include <QMainWindow>

class DebugWindow : public QMainWindow
{
    Q_OBJECT

public:
    DebugWindow();

private:

    QAction *childProcs;
};
