
#ifndef CONFIGFILE
#define CONFIGFILE

#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

namespace config{

	extern unordered_map<string, string> data;
	extern string syscallPath;
	extern bool doChilds;
	extern int displayLimit;
	extern vector<int> ignoredSysCalls;


	string& getString(const string& key);
	bool getBool(const string& key);
	int getInt(const string& key);
}

#endif
