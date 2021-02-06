#ifndef SD_COMMON_CONNECTION_H
#define SD_COMMON_CONNECTION_H

#include <sys/ptrace.h>
#include <unistd.h>

#include "process.h"

class UIConnect {
public:
	virtual void handleTracerStart(pid_t) = 0; // create
	virtual void handleTracerStartBulk(list<Process*>&) = 0; // setup
	virtual void handleTracerStop() = 0;
	virtual Process* handleChildCreate(pid_t stopped) = 0;
	virtual bool handleChildExit(pid_t stopped) = 0;
	virtual void handleCall(pid_t, __ptrace_syscall_info&) = 0;


};


#endif
