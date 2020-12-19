#include <iostream>
#include <fstream>
#include "configFile.h"

using namespace std;


bool ConfigFile::assignOne(){

bool ConfigFile::loadConfig(){
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
		if(t==string::npos){
			cerr << "Config error : "<<i<<" is invalid";
			return false;
		}
	}
	return true;
}
