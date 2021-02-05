#include <wait.h>

#include "realTracer.h"

using namespace std;

void RealTracer::killProcess(){
	kill(tracerPID, SIGKILL); // stop loop softly instead ? (threads seems not to like this)
}
