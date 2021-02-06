#ifndef SYSCALLDEBUGGER_TCPTRACER_H
#define SYSCALLDEBUGGER_TCPTRACER_H

#include "tracer.h"

// TODO
class TcpTracerConnect : public TracerConnect {
	void killProcess() override;
};

#endif
