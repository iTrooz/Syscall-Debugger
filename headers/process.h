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


using namespace std;

class Process
{
public:
    pid_t tracee;
    vector<Process> subProcesses;

    void remove();
    bool wait();
    void startTrace();
    void createProcess(string& cmd);
    int setupProcess(pid_t tracee);
};