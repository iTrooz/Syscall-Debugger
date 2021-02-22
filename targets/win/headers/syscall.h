#ifndef SYSCALL
#define SYSCALL

#include<QString>
#include<iostream>
#include<sys/ptrace.h>
#include<plateform.h>

using namespace std;

struct native_syscall_info {
	uint8_t op;
	uint32_t arch;
	uint64_t instruction_pointer;
	uint64_t stack_pointer;
	union {
		struct {
			uint64_t nr;
			uint64_t args[6];
		} entry;
		struct {
			int64_t rval;
			uint8_t is_error;
		} exit;
		struct {
			uint64_t nr;
			uint64_t args[6];
			uint32_t ret_data;
		} seccomp;
	};
};


struct syscall_entry {
	__uint64_t id{};
	__uint64_t args[6]{};

	syscall_entry& operator=(const native_syscall_info& other);
};

struct syscall_exit {

	__int64_t rval{};
	__uint8_t is_error = 0xF;

	syscall_exit& operator=(const native_syscall_info& other);
};

class Syscall {
public:
	void guessName(SYSCALLS_LIST&);
	QString name = nullptr;
	syscall_entry entry{};
	syscall_exit exit{};

public:
};

#endif
