#include<vector>

#include <sys/ptrace.h>
#include <sys/reg.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <list>

#include "syscall.h"


using namespace std;

#ifndef PROCESS
#define PROCESS

class Process
{
public:
    pid_t tracee;
    vector<Process> subProcesses;
    list<Syscall> calls;


    void remove();
    bool wait();
    void startTrace();
    void createProcess(string& cmd);
    int setupProcess(pid_t tracee);
};

#endif