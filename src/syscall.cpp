#include <iostream>
#include "syscall.h"
#include "utils.h"

using namespace std;

// TODO IMPORT/EXPORT TO FILE FUNCTIONS ? (serialisation)

void Syscall::guessName(){
	auto s = syscalls.find(entry.id);
	if(s==syscalls.end()) throw runtime_error("syscall not found");
	name = &s->second;
}