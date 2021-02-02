#include<QTreeWidgetItem>

#include "process.h"

using namespace std;

void UIProcess::setupTreeItem(QTreeWidgetItem* parent){
	treeItem = new QTreeWidgetItem;
	treeItem->setText(0, QString::number(pid));
	parent->addChild(treeItem);
}