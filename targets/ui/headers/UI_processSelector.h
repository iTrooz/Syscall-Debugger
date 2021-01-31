/********************************************************************************
** Form generated from reading UI file 'dialog_sprocaaJaiE.ui_build'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DIALOG_SPROCAAJAIE_H
#define DIALOG_SPROCAAJAIE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_SProc
{
public:
	QGridLayout *gridLayout;
	QLineEdit *lineEdit;
	QTableWidget *tableWidget;

	void setupUi(QDialog *SProc)
	{
		if (SProc->objectName().isEmpty())
			SProc->setObjectName(QString::fromUtf8("SProc"));
		SProc->resize(400, 299);
		gridLayout = new QGridLayout(SProc);
		gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
		lineEdit = new QLineEdit(SProc);
		lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

		gridLayout->addWidget(lineEdit, 0, 0, 1, 1);

		tableWidget = new QTableWidget(SProc);
		if (tableWidget->columnCount() < 2)
			tableWidget->setColumnCount(2);
		QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
		tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
		QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
		tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
		if (tableWidget->rowCount() < 1)
			tableWidget->setRowCount(1);
		QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
		tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem2);
		QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
		tableWidget->setItem(0, 0, __qtablewidgetitem3);
		QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
		tableWidget->setItem(0, 1, __qtablewidgetitem4);
		tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
		tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
		tableWidget->setShowGrid(false);
		tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
		tableWidget->horizontalHeader()->setStretchLastSection(true);
		tableWidget->verticalHeader()->setCascadingSectionResizes(false);
		tableWidget->verticalHeader()->setStretchLastSection(false);

		gridLayout->addWidget(tableWidget, 1, 0, 1, 1);


		retranslateUi(SProc);

		QMetaObject::connectSlotsByName(SProc);
	} // setupUi

	void retranslateUi(QDialog *SProc)
	{
		SProc->setWindowTitle(QCoreApplication::translate("SProc", "Process Selector", nullptr));
#if QT_CONFIG(accessibility)
		SProc->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
		lineEdit->setPlaceholderText(QCoreApplication::translate("SProc", "Enter process name/PID...", nullptr));
		QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
		___qtablewidgetitem->setText(QCoreApplication::translate("SProc", "PID", nullptr));
		QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
		___qtablewidgetitem1->setText(QCoreApplication::translate("SProc", "name", nullptr));

		const bool __sortingEnabled = tableWidget->isSortingEnabled();
		tableWidget->setSortingEnabled(false);
		QTableWidgetItem *___qtablewidgetitem2 = tableWidget->item(0, 0);
		___qtablewidgetitem2->setText(QCoreApplication::translate("SProc", "-999999", nullptr));
		QTableWidgetItem *___qtablewidgetitem3 = tableWidget->item(0, 1);
		___qtablewidgetitem3->setText(QCoreApplication::translate("SProc", "TESTPROCESS", nullptr));
		tableWidget->setSortingEnabled(__sortingEnabled);

	} // retranslateUi

};

namespace Ui {
	class SProc: public Ui_SProc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DIALOG_SPROCAAJAIE_H
