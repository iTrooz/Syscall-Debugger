#include <iostream>

#include "configFile.h"

using namespace std;

namespace config {
	unordered_map<string, string> callsList;
	string syscallPath;
	int displayLimit;
	bool doChilds;
	vector<int> ignoredSysCalls;

	string& getString(const string& key) {

		auto c = config::callsList.find(key);
		if(c == config::callsList.end()) throw runtime_error("Key " + key + " not found");
		return c->second;
	}

	bool getBool(const string& key){
		return getString(key)!="0";
	}

	int getInt(const string& key){
		return stoi(getString(key));
	}
}