#include <string>

#include "ui/localTracer.h"

using namespace std;

void LocalTracer::createProcess(const string& cmd) {
	tracer = gettid();

	char** cmdArgs = convert(cmd);

	pid_t child = fork();
	if(child==0){
		ptrace(PTRACE_TRACEME);
		kill(getpid(), SIGSTOP);
		execvp(cmdArgs[0], cmdArgs); // stop le flow du code
		throw runtime_error("NOT SUPPOSED TO HAPPEN : PROCESS ESCAPED"); // au cas ou
	}else {
		waitpid(child, nullptr, 0);

		mainProcess = new Process(child);
		mainProcess->treeItem = UI.processTree->topLevelItem(0);
		mainProcess->treeItem->setText(0, QString(to_string(mainProcess->pid).c_str()));
		processes.insert(mainProcess);
		displayed = mainProcess;
		startTracer();
	}
}

void LocalTracer::setupProcess(pid_t pid) {
	tracer = gettid();

	long temp = ptrace(PTRACE_ATTACH, pid, 0, 0);
	if (temp != 0) {
		cerr << "PTRACE_ATTACH failed : code " << temp << endl;
		return;
	}
	waitpid(pid, nullptr, 0);

	mainProcess = new Process(pid);
	mainProcess->treeItem = UI.processTree->topLevelItem(0);
	mainProcess->treeItem->setText(0, QString(to_string(mainProcess->pid).c_str()));

	recur(&processes, mainProcess);

	displayed = mainProcess;
	startTracer();
}
