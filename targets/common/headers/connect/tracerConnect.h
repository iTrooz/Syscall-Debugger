#ifndef SD_COMMON_TRACERCONNECT_H
#define SD_COMMON_TRACERCONNECT_H

#include<string>

#include "process.h"
#include "config/tracerConfig.h"

using namespace std;

class TracerConnect {
public:
	bool isLocal;
	virtual void createProcess(const string& cmd) = 0;
	virtual void setupProcess(pid_t tracee) = 0;

	virtual void killProcess() = 0;

	/*
	 * In case of shared list :
	 * tracer init it when process setup (bulk)
	 * Else init/updated by window
	 */
	list<Process*> processes;
	SYSCALLS_LIST syscalls;
};


#endif
