#include<vector>

#include <sys/ptrace.h>
#include <sys/reg.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <cstdlib>
#include <cstdio>
#include <cerrno>
#include <string>
#include <list>
#include <QTreeWidgetItem>

#include "syscall.h"


using namespace std;

#ifndef PROCESS
#define PROCESS

class Process
{
public:
    pid_t pid;
    list<Syscall> calls;
    Syscall* currentCall = nullptr;
	QTreeWidgetItem* treeItem;
};

#endif