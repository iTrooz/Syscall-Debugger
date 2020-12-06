#include "utils.h"
#include "debugWindow.h"
#include <iostream>

void Utils::SpawnDebugger()
{
    DebugWindow* win = new DebugWindow();
    win->show();
}


void Utils::a(){
    DebugWindow* win = new DebugWindow();
    win->show();
}

class Test{
public:
    static void a(){
        DebugWindow* win = new DebugWindow();
        win->show();
    }
};
