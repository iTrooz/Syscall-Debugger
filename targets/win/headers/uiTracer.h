#ifndef SD_WIN_UITRACER_H
#define SD_WIN_UITRACER_H

#include <unordered_map>

#include "process.h"
#include "baseTracer.h"

class DebugWindow;
class UITracer : public BaseTracer {
public:
	explicit UITracer(DebugWindow&);

	unordered_map<string, string> callsList;
	unordered_set<Process*> processes;
	DebugWindow& UI;

	void stopTracer() override;
	Process* getProcess(pid_t);
};


#endif
