
#include <iostream>
#include "config/tracerConfig.h"

TracerConfig::TracerConfig(){
	fileName = "config_tracer";
}

void TracerConfig::assignConfig(){
	syscallPath = getString("syscallPath");
}