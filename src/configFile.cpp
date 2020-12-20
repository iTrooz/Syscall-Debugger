#include <iostream>
#include "configFile.h"

using namespace std;

namespace config {
	unordered_map<string, string> data;
	string syscallPath;
	vector<int> ignoredSysCalls;

	string& getString(const string& key){

		auto c = config::data.find(key);
		if(c == config::data.end()) throw ("Key "+key+" not found");
		return c->second;
	}

	int getInt(string& key){
		return stoi(getString(key));
	}
}