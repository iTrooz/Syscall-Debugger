
#ifndef PROCESS
#define PROCESS

#include<vector>
#include <sys/ptrace.h>
#include <sys/reg.h>
#include <sys/wait.h>
#include <unistd.h>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <list>
#include <QTreeWidgetItem>

#include "syscall.h"


using namespace std;


class Process
{
public:
	bool running = true;
    pid_t pid;
    list<Syscall> calls;
    Syscall* currentCall = nullptr;
	QTreeWidgetItem* treeItem;

	void clearCalls();
};

#endif