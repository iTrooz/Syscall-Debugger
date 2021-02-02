#include "process.h"

Process::Process(pid_t t) : pid(t){
}

Process::Process(pid_t t, Process *b) : pid(t){
}
