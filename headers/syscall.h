#ifndef SYSCALL
#define SYSCALL

#include<string>
#include<iostream>
#include<sys/ptrace.h>

using namespace std;

struct syscall_entry {
	__uint64_t id;
	__uint64_t args[6];

	syscall_entry() = default;
	syscall_entry(const __ptrace_syscall_info& info){
		id = info.entry.nr;
		for(int i=0;i<6;i++)args[i] = info.entry.args[i];
	}
};

struct syscall_exit {

	__int64_t rval;
	__uint8_t is_error = 0xF;


	syscall_exit() = default;
	syscall_exit(const __ptrace_syscall_info& info){
		rval = info.exit.rval;
		is_error = info.exit.is_error;
	}
};

class Syscall {
public:
	void guessName();
	string* name;
	syscall_entry entry{};
	syscall_exit exit{};

public:
};

#endif
