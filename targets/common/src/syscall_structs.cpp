#include <cstring>

#include "syscall_structs.h"

syscall_entry::syscall_entry(const native_syscall_info &info) {
	std::memcpy(args, info.entry.args, sizeof(__uint64_t)*6);
	id = info.entry.nr;
}


syscall_exit::syscall_exit(const native_syscall_info &info) {
	rval = info.exit.rval;
	is_error = info.exit.is_error;
}