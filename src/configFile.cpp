#include <iostream>
#include "configFile.h"

using namespace std;

namespace config {
	unordered_map<string, string> data;
	string syscallPath;
	int displayLimit;
	bool doChilds;
	vector<int> ignoredSysCalls;

	string& getString(const string& key) {

		auto c = config::data.find(key);
		if(c == config::data.end()) throw runtime_error("Key "+key+" not found");
		return c->second;
	}

	bool getBool(const string& key){
		return getString(key)!="0";
	}

	int getInt(string& key){
		return stoi(getString(key));
	}
}