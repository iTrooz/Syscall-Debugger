#include<QTreeWidgetItem>

#include "process.h"

using namespace std;

Process::Process(pid_t t) : pid(t){

}

Process::~Process() {
	delCalls();
}

void Process::setupTreeItem(QTreeWidgetItem* parent){
	treeItem = new QTreeWidgetItem;
	treeItem->setText(0, QString::number(pid));
	parent->addChild(treeItem);
}
void Process::delCalls(){
	for(Syscall* c : calls){
		delete c;
	}
	calls.clear();
}