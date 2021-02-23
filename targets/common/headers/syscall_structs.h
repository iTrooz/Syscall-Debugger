#ifndef SD_COMMON_SYSCALL_STRUCTS_H
#define SD_COMMON_SYSCALL_STRUCTS_H

#include "stdint.h"

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

	uint64_t id{};
	uint64_t args[6]{};

	syscall_entry() = default;

	explicit syscall_entry(const native_syscall_info& other);
};

struct syscall_exit {

	int64_t rval{};
	uint8_t is_error = 0xF;

	syscall_exit() = default;
	explicit syscall_exit(const native_syscall_info& other);
};


#endif
