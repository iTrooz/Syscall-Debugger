#ifndef SYSCALL
#define SYSCALL

#include<QString>
#include<iostream>
#include<sys/ptrace.h>
#include<plateform.h>

#include "syscall_structs.h"

using namespace std;

class Syscall {
public:
	void guessName(SYSCALLS_LIST&);
	QString name = nullptr;
	syscall_entry entry{};
	syscall_exit exit{};

public:
};

#endif
