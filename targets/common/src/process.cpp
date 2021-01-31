#include "common/process.h"
#include "common/utils.h"
#include "iostream"

using namespace std;

void Process::delCalls(){
	for(Syscall* c : calls){
		delete c;
	}
	calls.clear();
}

void Process::setupTreeItem(QTreeWidgetItem* parent){
	treeItem = new QTreeWidgetItem;
	treeItem->setText(0, QString::number(pid));
	parent->addChild(treeItem);
}


Process::Process(int t) : pid(t){

}

Process::~Process() {
	delCalls();
//	delete treeItem; // TODO pas nécessaire ? jsp
}
