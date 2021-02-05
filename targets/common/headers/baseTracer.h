#ifndef SYSCALLDEBUGGER_TRACER_H
#define SYSCALLDEBUGGER_TRACER_H

#include<string>
#include<sys/ptrace.h>
#include<unordered_set>

using namespace std;

// only helper class ?
class BaseTracer {
//protected:
//	virtual ~BaseTracer();
public:
	virtual void createProcess(const string& cmd) = 0;
	virtual void setupProcess(pid_t tracee) = 0;

	virtual void startTracer(pid_t mainProcess) = 0;
	virtual void stopTracer();

	// process
	virtual void killProcess() = 0;


	virtual void handleTracerStart(pid_t) = 0;
	virtual void handleTracerStop() = 0;
	// handleChildEntry is handled by implementations in handleCall
	virtual bool handleChildExit(pid_t stopped) = 0;
	virtual void handleCall(pid_t, __ptrace_syscall_info&) = 0;

};

#endif
