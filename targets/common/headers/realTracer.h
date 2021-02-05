#ifndef SD_COMMON_REALTRACER_H
#define SD_COMMON_REALTRACER_H

#include "baseTracer.h"

class RealTracer : public BaseTracer {
	void createProcess(const string& cmd) override;
	void setupProcess(pid_t tracee) override;

	void startTracer(pid_t mainProcess) override;
	bool waitProcess(pid_t& stopped);

	void killProcess() override;
	pid_t tracerPID = 0;



};


#endif
