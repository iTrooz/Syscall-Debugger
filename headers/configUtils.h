#include <fstream>

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
		if(t==string::npos) throw ("Config parsing : line "+to_string(i)+" is invalid");
		config::data.insert({line.substr(0, t), line.substr(t+1)});
	}
}

void assignConfig(){
	config::syscallPath = config::getString("syscallPath");

//	std::istringstream str(config::getString("ignoredSysCalls")); // TODO don't
//	string s;
//	while(getline(str, s)){
//		config::ignoredSysCalls.push_back(stoi(s));
//	}
}