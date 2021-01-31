#ifndef SYSCALLDEBUGGER_TRACER_H
#define SYSCALLDEBUGGER_TRACER_H

class Tracer{
private:
	char** convert(const string& cmd);

	bool waitProcess(pid_t& stopped);
	virtual void createProcess(const string& cmd) = 0;
	virtual void setupProcess(pid_t tracee) = 0;

	virtual void handleCallReturn(Process& proc) = 0;
	virtual void handleCallStart(Process& proc) = 0;
	virtual bool handleChildExit(pid_t stopped) = 0;
	virtual Process* handleChildCreate(pid_t pid) = 0;
};

#endif
