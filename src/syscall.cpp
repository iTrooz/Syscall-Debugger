#include <iostream>
#include "syscall.h"
#include "utils.h"

using namespace std;

// TODO IMPORT/EXPORT TO FILE FUNCTIONS ? (serialisation)

void Syscall::guessName(){
	if(name==nullptr){
		auto s = syscalls.find(entry.id);
		if(s==syscalls.end()) throw runtime_error("syscall '" + to_string(entry.id) + "' not found");
		name = &s->second;
	}
}