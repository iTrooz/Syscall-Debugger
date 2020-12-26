#include "process.h"
#include "utils.h"
#include "iostream"

using namespace std;

void Process::clearCalls(){
	for(Syscall* c : calls){
		delete c;
	}
}
