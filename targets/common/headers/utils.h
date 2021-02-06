#ifndef UTILS
#define UTILS

#include <asm-generic/int-ll64.h>

#include "ui/debugWindow.h"
#include "configFile.h"
#include "process.h"


extern DebugWindow* mainWindow;
extern unordered_map<int, QString*> syscalls;

char** convert(const string& cmd);
void recurPIDs(list<Process*>&, Process*);

#endif