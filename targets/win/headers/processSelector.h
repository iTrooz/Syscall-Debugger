#ifndef SYSCALL_DEBUGGER_PROCESSSELECTOR_H
#define SYSCALL_DEBUGGER_PROCESSSELECTOR_H

#include "qt/UI_processSelector.h"

class ProcessSelector : public QDialog {
public:
	ProcessSelector();
	void updateProcs(const QString&);

	Ui_SProc UI{};

	void processChosen(QTableWidgetItem *item);
};


#endif
