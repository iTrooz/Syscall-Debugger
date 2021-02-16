#include <stdexcept>
#include <sstream>
#include "config/winConfig.h"
#include "connect/tracerConnect.h"

WinConfig::WinConfig(){
	fileName = "config_win";
}

void WinConfig::assignConfig(){
	doChilds = getBool("doChilds");
	displayLimit = getInt("displayLimit");
}

int getKey(std::unordered_map<int, std::string*>& syscalls, string& val){ // helper
	for(auto& c : syscalls){
		if(*c.second==val)return c.first;
	}
	throw std::runtime_error("getKey | syscall "+val+" not found");
}

void WinConfig::postAssignConfig(TracerConnect& connect){
	ignoredSyscalls.clear();
	std::istringstream str(getString("ignoredSyscalls"));
	std::string s;
	while(getline(str, s, ',')){
		ignoredSyscalls.push_back(getKey(connect.syscalls, s));
	}
}
