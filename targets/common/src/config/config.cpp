#include <iostream>
#include <fstream>

#include "config/config.h"

using namespace std;

void Config::parseConfig(){
	ifstream conf(fileName);
	string line;
	size_t t;
	int i = 0;
	if(!conf.is_open())throw std::runtime_error("Can't open config "+fileName);

	while (getline(conf,line)) {
		i++;
		t = line.find('#');
		if(t!=string::npos){
			line.resize(t);
		}

		t = line.find('=');
		if(t==string::npos) throw runtime_error("Config parsing : line "+to_string(i)+" is invalid");
		data.insert({line.substr(0, t), line.substr(t + 1)});
	}
	conf.close();
}


string& Config::getString(const string& key) {
	auto c = data.find(key);
	if(c == data.end()) throw runtime_error("Config::getString | Key " + key + " not found");
	return c->second;
}

bool Config::getBool(const string& key){
	return getString(key)!="0";
}

int Config::getInt(const string& key){
	return stoi(getString(key));
}

void Config::assignConfig() {

}
