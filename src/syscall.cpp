#include <iostream>
#include "syscall.h"
#include "utils.h"

using namespace std;

// TODO IMPORT/EXPORT TO FILE FUNCTIONS ? (serialisation)

void Syscall::guessName(){
	auto s = syscalls.find(entry->nr);
	if(s==syscalls.end()) throw runtime_error("syscall '" + to_string(entry->nr) + "' not found");
	name = &s->second;
}

Syscall::~Syscall() {
//	cout << entry << endl;
//	delete entry;
//	delete exit;
}
