#include "UIs/debugWindow.h"
#include "configFile.h"
#include <asm-generic/int-ll64.h>

#ifndef UTILS
#define UTILS

extern DebugWindow* mainWindow;
extern unordered_map<int, QString*> syscalls;

#endif