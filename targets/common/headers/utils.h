#ifndef SD_COMMON_UTILS
#define SD_COMMON_UTILS

#include <asm-generic/int-ll64.h>

#include "ui/debugWindow.h"
#include "process.h"

extern string execPath;
char** convert(const string& cmd);

#endif