#ifndef SD_WIN_LOCALTRACER_H
#define SD_WIN_LOCALTRACER_H

#include <sys/ptrace.h>

#include "ui/debugWindow.h"
#include "realTracer.h"
#include "uiTracer.h"
#include "process.h"

class LocalTracer : public UITracer, public RealTracer {
private:
	void handleTracerStart(pid_t) override;
	void handleTracerStop() override;
	Process* handleChildCreate(pid_t pid);
	bool handleChildExit(pid_t stopped) override;
	void handleCall(pid_t, __ptrace_syscall_info&) override;

	void handleCallEntry(Process& proc);
	void handleCallExit(Process& proc);
};

#endif
