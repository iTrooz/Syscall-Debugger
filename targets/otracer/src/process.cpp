#include <iostream>

#include "process.h"
#include "utils.h"

using namespace std;

void Process::delCalls(){
	for(Syscall* c : calls){
		delete c;
	}
	calls.clear();
}

Process::Process(int t) : pid(t){

}

Process::~Process() {
	delCalls();
//	delete treeItem; // TODO pas nécessaire ? jsp
}
