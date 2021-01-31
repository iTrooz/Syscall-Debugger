#ifndef SD_OTRACER_TRACERUTILS_H
#define SD_OTRACER_TRACERUTILS_H

char** convert(const string& cmd);
void recurPIDs(unordered_set<Process*>* set, Process* p);

#endif
