#ifndef SD_COMMON_CONNECTION_H
#define SD_COMMON_CONNECTION_H

#include <sys/ptrace.h>
#include <unistd.h>
#include <list>

#include "plateform.h"
#include "process.h"
#include "realTracer.h"
#include "syscall_structs.h"

class UIConnect {
public:

	virtual void handleTracerStart(pid_t) = 0; // create
	virtual void handleTracerStartBulk(pid_t, std::list<pdata>&) = 0; // setup
	virtual void handleTracerStop() = 0;
	virtual Process* handleChildCreate(pid_t stopped) = 0;
	virtual bool handleChildExit(pid_t stopped) = 0;
	virtual void handleCallEntry(pid_t, syscall_entry&) = 0;
	virtual void handleCallExit(pid_t, syscall_exit&) = 0;


};


#endif
