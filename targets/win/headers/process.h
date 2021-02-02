#ifndef SD_OTRACER_PROCESS_H
#define SD_OTRACER_PROCESS_H

#include<QTreeWidgetItem>

#include "../../otracer/headers/process.h"

class UIProcess : public Process {
public:
	void setupTreeItem(QTreeWidgetItem *parent);
	QTreeWidgetItem* treeItem;
};


#endif
