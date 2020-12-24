#ifndef SYSCALL
#define SYSCALL

#include<string>

using namespace std;

class Syscall {
public:
	Syscall(int id);

	int id;
	int result; // TODO long ? (et id ?)
	string& name;
public:
};

#endif
