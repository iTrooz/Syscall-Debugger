#ifndef CONFIGFILE
#define CONFIGFILE

#include<string>
#include<map>

using namespace std;

namespace config{
	map<string, string> data;
	string syscallPath;


	bool loadConfig();
}


#endif
