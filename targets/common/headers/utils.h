#ifndef UTILS
#define UTILS

#include <asm-generic/int-ll64.h>

#include "ui/debugWindow.h"
#include "configFile.h"
#include "process.h"


extern DebugWindow* mainWindow;
extern unordered_map<int, QString*> syscalls;
extern string execPath;

char** convert(const string& cmd);

#endif