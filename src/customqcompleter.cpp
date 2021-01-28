#include <iostream>

#include "customqcompleter.h"

using namespace std;

QStringList CustomQCompleter::splitPath(const QString &path) const
{
	auto a = QCompleter::splitPath(path);

	return a;
}

QString CustomQCompleter::pathFromIndex(const QModelIndex &index) const
{
	cout << "a" << endl;
	return index.data().toString();
}