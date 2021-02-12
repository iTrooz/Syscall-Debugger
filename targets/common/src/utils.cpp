#include <unordered_set>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <dirent.h>

#include "process.h"

using namespace std;


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