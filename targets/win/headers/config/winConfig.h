#ifndef SD_WIN_WINCONFIG_H
#define SD_WIN_WINCONFIG_H

#include <vector>
#include "config/config.h"
#include "connect/tracerConnect.h"

class WinConfig : public Config {
public:
	WinConfig();
	bool doChilds;
	bool warnARunning;
	int displayLimit;
	std::vector<int> ignoredSyscalls;

	void assignConfig() override;
	void postAssignConfig(TracerConnect&);
};


#endif
