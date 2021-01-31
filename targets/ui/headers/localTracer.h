#ifndef SYSCALLDEBUGGER_LOCALTRACER_H
#define SYSCALLDEBUGGER_LOCALTRACER_H

#include "debugWindow.h"
#include "tracer.h"

class LocalTracer : public Tracer {
private:
	void handleTraceStart() override;
	Process* handleChildCreate(pid_t pid) override;
	bool handleChildExit(pid_t stopped) override;
	void handleCallEntry(Process& proc) override;
	void handleCallExit(Process& proc) override;

public:
	DebugWindow interface;
};

#endif
