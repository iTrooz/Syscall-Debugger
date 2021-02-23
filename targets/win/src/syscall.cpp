#include <iostream>

#include "syscall.h"
#include "realTracer.h"

using namespace std;

// TODO IMPORT/EXPORT TO FILE FUNCTIONS ? (serialisation)

void Syscall::guessName(SYSCALLS_LIST& syscalls) {
	if(name.isEmpty()){
		auto s = syscalls.find(entry.id);
		if (s == syscalls.end()) throw runtime_error("Syscall::guessName | syscall '" + to_string(entry.id) + "' not found");
		name = QString::fromStdString(*s->second);
	}
}