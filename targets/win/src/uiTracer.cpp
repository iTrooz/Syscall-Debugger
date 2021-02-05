#include "uiTracer.h"


UITracer::UITracer(DebugWindow &UI) : UI(UI){

}

void UITracer::stopTracer() {
	BaseTracer::stopTracer();

	for(Process* proc : processes){
		delete proc;
	}
}

Process* UITracer::getProcess(pid_t pid){
	for (Process *p : processes) {
		if (p->pid == pid) {
			return p;
		}
	}
	return nullptr;
}
