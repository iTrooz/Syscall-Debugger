#ifndef SD_COMMON_LINUX_H
#define SD_COMMON_LINUX_H

#include <list>

struct pdata {
	int valid : 1 = 1;
	int subProc : 1;
	pid_t pid : 24;
};

bool can_ptrace_running();
bool parseProc(std::list<pdata>& l, pid_t toLoop);
int getPPID(pid_t);

#endif

