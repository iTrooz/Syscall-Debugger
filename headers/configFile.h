
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

#ifndef CONFIGFILE
#define CONFIGFILE

namespace config{

	extern unordered_map<string, string> data;
	extern string syscallPath;
	extern vector<int> ignoredSysCalls;


	string& getString(const string& key);
	int getInt(string& key);
}

#endif
