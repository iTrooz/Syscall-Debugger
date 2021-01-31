#ifndef SYSCALLDEBUGGER_TRACER_H
#define SYSCALLDEBUGGER_TRACER_H

#include<string>

#include "process.h"

using namespace std;

class Tracer {
public:
	virtual void createProcess(const string& cmd) = 0;
	virtual void setupProcess(pid_t tracee) = 0;

protected:

	void startTracer();
	void stopTracer();
	bool waitProcess(pid_t& stopped);

	// process
	unordered_set<Process*> processes;
	Process* getProcess(pid_t pid);
	void killProcesses();

	Process* mainProcess;
	bool runTracer = true;
	pid_t tracerPid;


	virtual void handleTraceStart();
	virtual Process* handleChildCreate(pid_t pid);
	virtual bool handleChildExit(pid_t stopped);
	virtual void handleCallExit(Process& proc);
	virtual void handleCallEntry(Process& proc);

};

#endif
