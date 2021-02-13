#ifndef SD_WIN_PROCESS_H
#define SD_WIN_PROCESS_H

#include<QTreeWidgetItem>

#include "syscall.h"

class Process {
public:
	bool running = true;
	const pid_t pid;
	list<Syscall*> calls;
	Syscall* currentCall = nullptr;

	QTreeWidgetItem* treeItem;

	explicit Process(pid_t);
	~Process();
	void delCalls();
	void setupTreeItem(QTreeWidgetItem*);
};

#endif
