#ifndef SYSCALL_DEBUGGER_PROCESSSELECTOR_H
#define SYSCALL_DEBUGGER_PROCESSSELECTOR_H

#include "UI_processSelector.h"

class ProcessSelector : public QWidget {
public:
	ProcessSelector();
	void updateProcs(const QString&);

	Ui_SProc UI{};

};


#endif
