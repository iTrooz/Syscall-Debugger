#ifndef SYSCALL
#define SYSCALL

#include<string>
#include<sys/ptrace.h>

using namespace std;


struct syscall_entry {
	__uint64_t nr;
	__uint64_t args[6];
};

struct syscall_exit {
	__int64_t rval;
	__uint8_t is_error;
};

struct syscall_base {
	__uint8_t op;
	__uint32_t arch __attribute__ ((__aligned__ (4)));
	__uint64_t instruction_pointer;
	__uint64_t stack_pointer;
};

struct syscall_data
{
	syscall_base base;
	union
	{
		syscall_entry entry;
		syscall_exit exit;
	};
};


class Syscall {
public:
	void guessName();
	~Syscall();
	string* name;
	syscall_entry* entry;
	syscall_exit* exit;


public:
};

#endif
