#include "process.h"
#include "utils.h"
#include "iostream"

using namespace std;

void Process::delCalls(){
	for(Syscall* c : calls){
		delete c;
	}
}

Process::~Process() {
	delCalls();
//	delete treeItem; // TODO pas nécessaire ? jsp
}
