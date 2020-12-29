#ifndef SYSCALL
#define SYSCALL

#include<string>
#include<sys/ptrace.h>

using namespace std;

class Syscall {
public:
	Syscall(__ptrace_syscall_info&);
	string& name;
	__ptrace_syscall_info& info;

public:
};

#endif
