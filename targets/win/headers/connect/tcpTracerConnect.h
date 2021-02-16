#ifndef SYSCALLDEBUGGER_TCPTRACER_H
#define SYSCALLDEBUGGER_TCPTRACER_H

#include "realTracer.h"

// TODO
class TcpTracerConnect : public virtual TracerConnect {
public:
	TcpTracerConnect();

	void killProcess() override;
};

#endif
