#ifndef SD_COMMON_CONFIG_H
#define SD_COMMON_CONFIG_H

#include <string>
#include <unordered_map>

class Config{
public:
	std::unordered_map<std::string, std::string> data;
	std::string fileName;

	void parseConfig();
	virtual void assignConfig() = 0;

	std::string& getString(const std::string& key);
	bool getBool(const std::string& key);
	int getInt(const std::string& key);

};


#endif
