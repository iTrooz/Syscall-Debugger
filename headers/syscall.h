#ifndef SYSCALL
#define SYSCALL

#include<string>
#include<sys/ptrace.h>

using namespace std;

struct ptrace_entry {
	__uint8_t op;
	__uint32_t arch __attribute__ ((__aligned__ (4)));
	__uint64_t instruction_pointer;
	__uint64_t stack_pointer;

	__uint64_t id;
	__uint64_t args[6];
};

struct ptrace_exit {
	__uint8_t op;
	__uint32_t arch __attribute__ ((__aligned__ (4)));
	__uint64_t instruction_pointer;
	__uint64_t stack_pointer;

	__int64_t rval;
	__uint8_t is_error;
};


class Syscall {
public:
	void guessName();
	string* name;
	ptrace_entry entry;
	ptrace_exit exit{.op=255};


public:
};

#endif
