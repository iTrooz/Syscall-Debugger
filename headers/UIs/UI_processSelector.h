/********************************************************************************
** Form generated from reading UI file 'popup_sprocvJwqEZ.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef POPUP_SPROCVJWQEZ_H
#define POPUP_SPROCVJWQEZ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SProc
{
public:
	QGridLayout *gridLayout;
	QTableWidget *tableWidget;
	QLineEdit *lineEdit;

	void setupUi(QWidget *SProc)
	{
		if (SProc->objectName().isEmpty())
			SProc->setObjectName(QString::fromUtf8("SProc"));
		SProc->resize(400, 300);
		gridLayout = new QGridLayout(SProc);
		gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
		tableWidget = new QTableWidget(SProc);
		if (tableWidget->columnCount() < 3)
			tableWidget->setColumnCount(3);
		QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
		tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
		QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
		tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
		QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
		tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
		if (tableWidget->rowCount() < 1)
			tableWidget->setRowCount(1);
		QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
		tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem3);
		QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
		tableWidget->setItem(0, 0, __qtablewidgetitem4);
		QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
		tableWidget->setItem(0, 1, __qtablewidgetitem5);
		QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
		tableWidget->setItem(0, 2, __qtablewidgetitem6);
		tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
		tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
		tableWidget->horizontalHeader()->setStretchLastSection(true);
		tableWidget->verticalHeader()->setCascadingSectionResizes(false);
		tableWidget->verticalHeader()->setStretchLastSection(false);

		gridLayout->addWidget(tableWidget, 1, 0, 1, 1);

		lineEdit = new QLineEdit(SProc);
		lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

		gridLayout->addWidget(lineEdit, 0, 0, 1, 1);


		retranslateUi(SProc);

		QMetaObject::connectSlotsByName(SProc);
	} // setupUi

	void retranslateUi(QWidget *SProc)
	{
		SProc->setWindowTitle(QCoreApplication::translate("SProc", "Form", nullptr));
#if QT_CONFIG(accessibility)
		SProc->setAccessibleName(QCoreApplication::translate("SProc", "Process Selector", nullptr));
#endif // QT_CONFIG(accessibility)
		QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
		___qtablewidgetitem->setText(QCoreApplication::translate("SProc", "PID", nullptr));
		QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
		___qtablewidgetitem1->setText(QCoreApplication::translate("SProc", "user", nullptr));
		QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
		___qtablewidgetitem2->setText(QCoreApplication::translate("SProc", "name", nullptr));

		const bool __sortingEnabled = tableWidget->isSortingEnabled();
		tableWidget->setSortingEnabled(false);
		QTableWidgetItem *___qtablewidgetitem3 = tableWidget->item(0, 0);
		___qtablewidgetitem3->setText(QCoreApplication::translate("SProc", "56298", nullptr));
		QTableWidgetItem *___qtablewidgetitem4 = tableWidget->item(0, 1);
		___qtablewidgetitem4->setText(QCoreApplication::translate("SProc", "root", nullptr));
		QTableWidgetItem *___qtablewidgetitem5 = tableWidget->item(0, 2);
		___qtablewidgetitem5->setText(QCoreApplication::translate("SProc", "firefox", nullptr));
		tableWidget->setSortingEnabled(__sortingEnabled);

		lineEdit->setPlaceholderText(QCoreApplication::translate("SProc", "Enter process name/PID...", nullptr));
	} // retranslateUi

};

namespace Ui {
	class SProc: public Ui_SProc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // POPUP_SPROCVJWQEZ_H
