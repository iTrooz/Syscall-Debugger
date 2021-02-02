#ifndef SYSCALLDEBUGGER_LOCALTRACER_H
#define SYSCALLDEBUGGER_LOCALTRACER_H

#include "debugWindow.h"
#include "tracerCore.h"
#include "process.h"

class LocalTracer : public Tracer {
private:
	LocalTracer(DebugWindow&);

	void handleTracerStart() override;
	void handleTracerStop() override;
	Process* handleChildCreate(pid_t pid) override;
	bool handleChildExit(pid_t stopped) override;
	void handleCallEntry(Process& proc) override;
	void handleCallExit(Process& proc) override;

public:
	unordered_map<string, string> callsList;
	unordered_set<UIProcess*> processes;
	DebugWindow& UI;
};

#endif
