#ifndef SYSCALL
#define SYSCALL

#include<string>

using namespace std;

class Syscall {
public:
	Syscall(int id);

	int id; // TODO long ?
	long result;
	string& name;
public:
};

#endif
