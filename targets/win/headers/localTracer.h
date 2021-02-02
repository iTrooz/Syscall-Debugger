#ifndef SYSCALLDEBUGGER_LOCALTRACER_H
#define SYSCALLDEBUGGER_LOCALTRACER_H

#include "debugWindow.h"
#include "tracerCore.h"
#include "process.h"
#include "sys/ptrace.h"

class LocalTracer : public Tracer {
private:
	LocalTracer(DebugWindow&);

	void stopTracer() override;
	void handleTracerStart(pid_t) override;
	void handleTracerStop() override;
	Process* handleChildCreate(pid_t pid);
	bool handleChildExit(pid_t stopped) override;
	void handleCall(pid_t, __ptrace_syscall_info&);

	void handleCallEntry(Process& proc);
	void handleCallExit(Process& proc);
	Process* getProcess(pid_t);

public:
	unordered_map<string, string> callsList;
	unordered_set<Process*> processes;
	DebugWindow& UI;
};

#endif
