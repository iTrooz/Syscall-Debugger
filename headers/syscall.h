#ifndef SYSCALL
#define SYSCALL

#include<QString>
#include<iostream>
#include<sys/ptrace.h>

using namespace std;

struct syscall_entry {
	__uint64_t id{};
	__uint64_t args[6]{};

	syscall_entry& operator=(const __ptrace_syscall_info& other);
};

struct syscall_exit {

	__int64_t rval{};
	__uint8_t is_error = 0xF;

	syscall_exit& operator=(const __ptrace_syscall_info& other);
};

class Syscall {
public:
	void guessName();
	string* name = nullptr;
	syscall_entry entry{};
	syscall_exit exit{};

public:
};

#endif
