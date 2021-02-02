#include <unordered_set>
#include <dirent.h>
#include <fstream>
#include <sstream>

#include "tracerCore.h"
#include "../../otracer/headers/process.h"

using namespace std;

Process* Tracer::getProcess(pid_t pid){
	for (Process *p : processes) {
		if (p->pid == pid) {
			return p;
		}
	}
	return nullptr;
}

void Tracer::KillProcess(){
	for(Process* p : processes){
		kill(p->pid, SIGKILL);
	}
}


// -----------------------------------

void Tracer::handleTracerStart() {
}

void Tracer::handleTracerStop() {
}


Process* Tracer::handleChildCreate(pid_t pid){ // Warning : Still need to apply Tree Item Widget. besoin = get parent parent from here
	auto* newChild = new Process(pid);
	processes.insert(newChild);

	return newChild;
}

bool Tracer::handleChildExit(pid_t stopped){ // true is there is no more processes

	Process* proc = nullptr;
	bool empty = true;
	for (Process *p : processes) {
		if (p->running){
			if(p->pid == stopped) {
				p->running = false;
				proc = p;
			}else{
				empty = false;
			}
			if(!empty&&proc!=nullptr)break; // TODO jsp si vraiment opti
		}
	}
	if(proc==nullptr){
		cerr << "Invalid child exited : " << stopped << endl;
	}else{
		return empty;
	}
	return false;
}


void Tracer::handleCallEntry(Process& proc) {
}


void Tracer::handleCallExit(Process& proc) {
}


void Tracer::killProcess(){
	kill(mainProcess->pid, SIGKILL);
}

bool Tracer::stopTracer(){
	killProcess();
	for(Process* proc : processes){
		delete proc;
	}
	return true;
}


// -----------------------------------


void recurPIDs(unordered_set<Process*>* set, Process* p){
	string ps = to_string(p->pid);
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
			child = new Process(pid);
			child->setupTreeItem(p->treeItem);
			set->insert(new Process(pid));  // adding thread

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
					child = new Process(pid);
					child->setupTreeItem(p->treeItem);
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