#ifndef SD_OTRACER_TRACERUTILS_H
#define SD_OTRACER_TRACERUTILS_H

#include "process.h"

char** convert(const string& cmd);
void recurPIDs(unordered_set<Process*>*, Process*);

#endif
