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

#include "syscall.h"


using namespace std;


class Process
{
public:
	bool running = true;
    const pid_t pid;

	explicit Process(int);
	~Process();

};

#endif