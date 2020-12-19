#include <iostream>
#include <fstream>
#include <sstream>
#include "configFile.h"

using namespace std;

#ifndef TEST
#define TEST


void parseConfig(){
	ifstream configFile("config");
	string line;
	size_t t;
	int i = 0;

	while (getline(configFile,line)) {
		i++;
		t = line.find('#');
		if(t!=string::npos){
			line.resize(t);
		}

		t = line.find('=');
		if(t==string::npos) throw ("Config parsing : line "+to_string(i)+" is invalid");
	}
}


void internal(){
//	config::syscallPath = config::getString("syscallPath");

//	std::istringstream str(config::getString("ignoredSysCalls"));
//	string s;
//	while(getline(str, s)){
//		config::ignoredSysCalls.push_back(stoi(s));
//	}
}

bool config::loadConfig(){
	try{
		parseConfig();
		internal();
		return true;
	}catch (exception& e){
		cerr << e.what() << endl;
	}catch (string& e){
		cerr << e << endl;
	}
	return false;
}

#endif