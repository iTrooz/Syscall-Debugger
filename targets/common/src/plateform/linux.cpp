#include <iostream>
#include <sys/capability.h>

#include "plateform.h"

using namespace std;

bool can_ptrace_running(){
	cap_t caps = cap_get_proc();
	if(caps==nullptr){
		cerr << "An error occured in cap_get_proc " << endl;
		return false;
	}

	cap_flag_value_t val;
	if(cap_get_flag(caps, CAP_SYS_PTRACE, CAP_EFFECTIVE, &val)){
		cerr << "An error occured in cap_get_flag " << endl;
		return false;
	}
	bool ret = val==1;

	if(cap_free(caps)){
		cerr << "An error occured in cap_free " << endl;
	}

	return ret;
}