#ifndef SD_COMMON_TRACERCONNECT_H
#define SD_COMMON_TRACERCONNECT_H

#include<string>

#include "process.h"

using namespace std;

class TracerConnect {
public:
	virtual void createProcess(const string& cmd) = 0;
	virtual void setupProcess(pid_t tracee) = 0;

	virtual void killProcess() = 0;

	/*
	 * Tracer init this when process setup (bulk)
	 * Else init/updated by window
	 */
	list<Process*> processes;
};


#endif
