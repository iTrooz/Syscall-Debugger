#include <iostream>
#include <fstream>
#include <list>
#include <sys/capability.h>
#include <dirent.h>
#include <unordered_map>

#include "plateform.h"

using namespace std;

static pdata nullData = pdata{.valid=0};

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

int getPPID(pid_t child){
	FILE* f = fopen(("/proc/"+to_string(child)+"/stat").c_str(), "r");
	if(f==nullptr){
		cerr << "getPPID | failed to open stat of PID " << child << endl;
		return 0;
	}
	#define READ_SIZE 64
	char tmp[READ_SIZE];
	char* buf = reinterpret_cast<char*>(tmp); // thx cpp;
	int res = fread(buf,1,READ_SIZE,f); // ~number, useless to read more
	char* bufEnd = buf+res;
	fclose(f);

	char* pos;
	for(int i=0;i<3;i++){
		pos = std::find(buf, bufEnd, ' ');
		if(pos==bufEnd){
			cerr << "getPPID | could not find " << i+1 << " space in stat of PID " << child << endl;
			return 0;
		}
		buf = pos+1;
	}
	return atoi(buf);
}

bool parseProc(list<pdata>& l, pid_t toLoop);

bool parseThread(list<pdata>& l, string& parent, pid_t toLoop){
	ifstream file;
	file.open(("/proc/" + parent + "/task/" + to_string(toLoop) + "/children").c_str(), std::ifstream::in);
	if (!file.is_open()) {
		cerr << "failed to open children file of PID " << parent << "/" << toLoop << endl;
		return false;
	}

	string tmp;
	file >> tmp;
	file.close();

	if (tmp.empty())return false;
	// we won't be using string (because every erase would make a copy, and we can do better)
	char *buf = tmp.data();
	char *bufEnd = buf + tmp.size();

	pdata p{.valid=1, .subProc=1};
	while (true) {
		char *pos = std::find(buf, bufEnd, ' ');

		pos[0] = '\0';

		p.pid = atoi(buf);
		if (p.pid) {
			l.push_back(p);
			parseProc(l, p.pid);
			l.push_back(nullData);
		} else {
			cerr << "Got invalid PID in childen file : |" << buf << "|" << endl;
		}

		if (pos == bufEnd)break;
		buf = pos + 1;
	}

	return true;
}

bool parseProc(list<pdata>& l, pid_t toLoop){
	string ps = to_string(toLoop);
	DIR* dir = opendir(("/proc/"+ps+"/task").c_str());
	if(dir==nullptr){
		cerr << "Failed to open /proc/"<< ps << "/task directory" << endl;
		return false;
	}

	pdata p{.subProc=0};
	dirent* thread;

	while((thread = readdir(dir))) {

		p.pid = atoi(thread->d_name);
		if (p.pid) {
			if (p.pid != toLoop) {
				l.push_back(p);
				l.push_back(nullData);
			}
			parseThread(l, ps, p.pid);
		}
	}
	return true;
}


void loadSyscalls(std::string& path, SYSCALLS_LIST& syscalls){
	ifstream file(path);

	string line;
	size_t t;
	while (getline(file,line)) {
		if(line.size()<13)continue;
		if(line.substr(0, 13)!="#define __NR_")continue;
		line = line.erase(0, 13);

		t = line.find(' ');
		if(t==string::npos)continue;

		try{
			syscalls.insert({stoi(line.substr(t+1)), new string(line.substr(0, t))});
		}catch(invalid_argument& e){
			throw runtime_error("Invalid number "+line.substr(t+1)+" for syscall"+line.substr(0, t));
		}
	}
}
