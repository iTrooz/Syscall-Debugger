#ifndef SD_COMMON_TRACER_H
#define SD_COMMON_TRACER_H

#include<string>
#include<sys/ptrace.h>
#include<unordered_set>

#include "connect/uiConnect.h"
#include "connect/tracerConnect.h"

class RealTracer : public virtual TracerConnect {
public:
	// internal
	UIConnect* uiConnect;
	TracerConfig config;
	explicit RealTracer(UIConnect*);
	~RealTracer();
	bool waitProcess(pid_t&);
	void cleanUp();

	// methods inherited from TracerConnect
	void createProcess(const string&) override;
	void createProcessInternal(const string&);
	void setupProcess(pid_t tracee) override;
	void setupProcessInternal(pid_t pid);
	void startTracer();

	void killProcess() override;
	pid_t mainProcess = 0;

};

#endif
