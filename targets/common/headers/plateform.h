#ifndef SD_COMMON_LINUX_H
#define SD_COMMON_LINUX_H

#include <list>
#include <string>
#include <unordered_map>
#include <string>

extern std::string execPath;

struct pdata {
	int valid : 1 = 1;
	int subProc : 1;
	pid_t pid : 24;
};

bool can_ptrace_running();
bool parseProc(std::list<pdata>& l, pid_t toLoop);
int getPPID(pid_t);


#define SYSCALLS_LIST std::unordered_map<int, std::string*>
void loadSyscalls(std::string&, SYSCALLS_LIST&);

#endif
