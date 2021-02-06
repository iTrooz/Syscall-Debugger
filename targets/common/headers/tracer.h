#ifndef SYSCALLDEBUGGER_TRACER_H
#define SYSCALLDEBUGGER_TRACER_H

#include<string>
#include<sys/ptrace.h>
#include<unordered_set>

#include "connects/uiConnect.h"
#include "connects/tracerConnect.h"

using namespace std;

class Tracer : public TracerConnect {
public:
	// internal
	UIConnect* uiConnect;
	Tracer(UIConnect* ui);
	bool waitProcess(pid_t& stopped);

	// methods inherited from TracerConnect
	void createProcess(const string& cmd) override;
	void setupProcess(pid_t tracee) override;
	void startTracer(pid_t);

	void killProcess() override;

	// process

	pid_t tracerPID = 0;

};

#endif
