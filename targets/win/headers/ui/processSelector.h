#ifndef SD_WIN_PROCESSSELECTOR_H
#define SD_WIN_PROCESSSELECTOR_H

#include "qt/UI_processSelector.h"

class ProcessSelector : public QDialog {
public:
	ProcessSelector();
	void updateProcs(const QString&);

	Ui_SProc QtUI{};

	void processChosen(QTableWidgetItem *item);
};


#endif
