#ifndef SYSCALL_DEBUGGER_CUSTOMQCOMPLETER_H
#define SYSCALL_DEBUGGER_CUSTOMQCOMPLETER_H

#include<QCompleter>

class CustomQCompleter : public QCompleter {
	QStringList splitPath (const QString &path) const override;
	QString pathFromIndex(const QModelIndex &index) const override;
};

#endif