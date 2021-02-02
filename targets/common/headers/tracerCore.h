#ifndef SYSCALLDEBUGGER_TRACER_H
#define SYSCALLDEBUGGER_TRACER_H

#include<string>
#include<unordered_set>

#include "../../otracer/headers/process.h"

using namespace std;

class Tracer {
//protected:
//	virtual ~Tracer();
public:
	virtual void createProcess(const string& cmd) = 0;
	virtual void setupProcess(pid_t tracee) = 0;

	void startTracer();
	virtual bool stopTracer();
	bool waitProcess(pid_t& stopped);

	// process
	unordered_set<Process*> processes;
	Process* getProcess(pid_t pid);
	void killProcess();

	Process* mainProcess;
	pid_t tracerPID;


	virtual void handleTracerStart();
	virtual void handleTracerStop();
	virtual Process* handleChildCreate(pid_t pid);
	virtual bool handleChildExit(pid_t stopped);
	virtual void handleCallExit(Process& proc);
	virtual void handleCallEntry(Process& proc);

};

#endif
