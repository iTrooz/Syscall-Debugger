#ifndef SD_OTRACER_PROCESS_H
#define SD_OTRACER_PROCESS_H

#include "wait.h"

// Minimal class, at least needed for recurPIDs()
class Process {
public:
	explicit Process(pid_t);
	Process(pid_t, Process*);

	const pid_t pid;
};

#endif
