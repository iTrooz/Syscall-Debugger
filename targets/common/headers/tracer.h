#ifndef SYSCALLDEBUGGER_TRACER_H
#define SYSCALLDEBUGGER_TRACER_H

#include<string>
#include<sys/ptrace.h>
#include<unordered_set>

#include "connects/uiConnect.h"
#include "connects/tracerConnect.h"

using namespace std;

class Tracer : public virtual TracerConnect {
public:
	// internal
	UIConnect* uiConnect;
	explicit Tracer(UIConnect*);
	~Tracer();
	bool waitProcess(pid_t&);
	void cleanUp();

	// methods inherited from TracerConnect
	void createProcess(const string&) override;
	void createProcessInternal(const string&);
	void setupProcess(pid_t tracee) override;
	void setupProcessInternal(pid_t pid);
	void startTracer(pid_t);

	void killProcess() override;

	// process

	pid_t tracerPID = 0;

};

#endif
