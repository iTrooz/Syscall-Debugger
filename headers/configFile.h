
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

#ifndef CONFIGFILE
#define CONFIGFILE

namespace config{
	bool loadConfig();


//	unordered_map<string, string> data;
//	string syscallPath;
//	vector<int> ignoredSysCalls;


	string& getString(const string& key){
//		auto c = config::data.find(key);
//		if(c == config::data.end()) throw ("Key "+key+" not found");
//		return c->second;
	}

//	int getInt(string& key){
//		return stoi(getString(key));
//	}
}

#endif
