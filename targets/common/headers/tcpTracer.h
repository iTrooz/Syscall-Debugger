#ifndef SYSCALLDEBUGGER_TCPTRACER_H
#define SYSCALLDEBUGGER_TCPTRACER_H

#include "baseTracer.h"
#include "realTracer.h"

// TODO
class TcpTracer : public RealTracer {
	void killProcess() override;
};

#endif
