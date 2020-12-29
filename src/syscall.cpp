#include "syscall.h"
#include "utils.h"

// TODO IMPORT/EXPORT TO FILE FUNCTIONS ? (serialisation)

string& guessName(int id){
	auto s = syscalls.find(id);
	if(s==syscalls.end()) throw runtime_error("syscall not found");
	else return s->second;
}

Syscall::Syscall(__ptrace_syscall_info& info) : name(guessName(info.entry.nr)), info(info){

}