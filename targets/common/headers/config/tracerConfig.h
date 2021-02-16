#ifndef SD_COMMON_TRACERCONFIG_H
#define SD_COMMON_TRACERCONFIG_H

#include<string>

#include "config/config.h"
#include "tracerConfig.h"


class TracerConfig : public Config {
public:
	TracerConfig();
	std::string syscallPath;

	void assignConfig() override;
};


#endif
