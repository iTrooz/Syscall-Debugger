#include <fstream>
#include <sstream>

void parseConfig(){
	ifstream conf("config");
	string line;
	size_t t;
	int i = 0;

	while (getline(conf,line)) {
		i++;
		t = line.find('#');
		if(t!=string::npos){
			line.resize(t);
		}

		t = line.find('=');
		if(t==string::npos) throw runtime_error("Config parsing : line "+to_string(i)+" is invalid");
		config::data.insert({line.substr(0, t), line.substr(t+1)});
	}
}

void assignConfig(){
	config::syscallPath = config::getString("syscallPath");
	config::doChilds = config::getBool("doChilds");
}

int getKey(string& val){
	for(auto& c : syscalls){
		if(c.second==val)return c.first;
	}
	throw runtime_error("syscall "+val+" not found");
}

void postAssignConfig(){
	std::istringstream str(config::getString("ignoredSysCalls"));
	string s;
	while(getline(str, s, ',')){
		config::ignoredSysCalls.push_back(getKey(s));
	}
}