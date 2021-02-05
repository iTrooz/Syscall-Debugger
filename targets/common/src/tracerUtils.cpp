#include <unordered_set>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <dirent.h>
#include <csignal>

#include "process.h"
#include "baseTracer.h"

using namespace std;


void BaseTracer::stopTracer(){
	killProcess();
}


// -----------------------------------


void recurPIDs(unordered_set<Process*>* set, Process* parent){
	string ps = to_string(parent->pid);
	DIR* dir = opendir(("/proc/"+ps+"/task").c_str());
	if(dir==nullptr){
		cerr << "Failed to open /proc/"<< ps << "/task directory" << endl;
		return;
	}

	dirent* thread;
	Process* child;
	int pid, size;
	char* pos;
	ifstream file;
	while((thread = readdir(dir))){
		pid = atoi(thread->d_name);
		if(pid){
			child = new Process(pid, parent);
			set->insert(new Process(pid));

			file.open(("/proc/" + ps + "/task/" + to_string(pid) + "/children").c_str(), std::ifstream::in);
			if(!file.is_open()){
				cerr << "failed to open children file of PID " << ps << "/" << pid << endl;
				continue;
			}

			string tmp;
			file >> tmp;
			file.close();

			// we won't be using string (because every erase would make a copy, and we can do better)
			size = tmp.size();
			if(size==0)continue;
			char *buf = tmp.data();

			while(true){
				pos = std::find(buf, buf+size, ' ');

				pos[0] = '\0';

				pid = atoi(buf);
				if(pid) {
					child = new Process(pid, parent);
					recurPIDs(set, child);
				}else{
					cerr << "Got invalid PID in childen file : |" << buf << "|" << endl;
				}

				if(pos==buf+size)break;
				buf = pos+1;
			}
		}
	}
}


char** convert(const string& cmd){
	stringstream a(cmd);
	vector<string> vec;
	string s;
	while (getline(a, s, ' ')) {
		vec.push_back(s);
	}

	const char **cmdArgs = new const char* [vec.size() + 1];
	for (int i=0; i<vec.size(); i++){
		cmdArgs[i] = vec[i].c_str();
	}
	cmdArgs[vec.size()] = nullptr;
	return (char**)cmdArgs;
}