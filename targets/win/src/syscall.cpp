#include <iostream>
#include "syscall.h"
#include "utils.h"

using namespace std;

// TODO IMPORT/EXPORT TO FILE FUNCTIONS ? (serialisation)

void Syscall::guessName() {
	if(name==nullptr){
		auto s = syscalls.find(entry.id);
		if (s == syscalls.end()) throw runtime_error("syscall '" + to_string(entry.id) + "' not found");
		name = s->second;
	}
}

syscall_entry& syscall_entry::operator=(const __ptrace_syscall_info &info) {

	memcpy(args, info.entry.args, sizeof(__uint64_t)*6);
	id = info.entry.nr;
	return *this;
}


syscall_exit& syscall_exit::operator=(const __ptrace_syscall_info &info) {
	rval = info.exit.rval;
	is_error = info.exit.is_error;
	return *this;
}