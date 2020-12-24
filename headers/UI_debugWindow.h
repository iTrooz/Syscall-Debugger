/********************************************************************************
** Form generated from reading UI file 'debugger-5kLXpRL.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DEBUGGER_2D_5KLXPRL_H
#define DEBUGGER_2D_5KLXPRL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DebugWindow
{
public:
	QAction *actionSaveAs;
	QAction *actionSettings;
	QAction *actionAbout;
	QAction *actionGithub;
	QAction *actionTraceChilds;
	QAction *actionClearChilds;
	QAction *actionQuickProcessSelect;
	QAction *actionQuickProcessCmd;
	QWidget *centralwidget;
	QGridLayout *gridLayout_2;
	QVBoxLayout *verticalLayout_3;
	QHBoxLayout *horizontalLayout;
	QPushButton *buttonRun;
	QPushButton *buttonStop;
	QPushButton *buttonClear;
	QSpacerItem *horizontalSpacer_2;
	QPushButton *buttonPause;
	QSpacerItem *horizontalSpacer_3;
	QFrame *frame;
	QGridLayout *gridLayout;
	QLabel *labelPID;
	QLabel *labelState;
	QSpacerItem *verticalSpacer;
	QVBoxLayout *verticalLayout;
	QTextEdit *processSelector;
	QTextEdit *cmd;
	QSpacerItem *verticalSpacer_2;
	QVBoxLayout *verticalLayout_2;
	QTableWidget *logs;
	QTextEdit *filter;
	QSpacerItem *horizontalSpacer;
	QTreeWidget *processTree;
	QMenuBar *menubar;
	QMenu *menu_File;
	QMenu *menu_Tools;
	QMenu *menuQuickRun;
	QMenu *menu_Help;
	QStatusBar *statusbar;

	void setupUi(QMainWindow *DebugWindow)
	{
		if (DebugWindow->objectName().isEmpty())
			DebugWindow->setObjectName(QString::fromUtf8("DebugWindow"));
		DebugWindow->resize(946, 678);
		actionSaveAs = new QAction(DebugWindow);
		actionSaveAs->setObjectName(QString::fromUtf8("actionSaveAs"));
		actionSettings = new QAction(DebugWindow);
		actionSettings->setObjectName(QString::fromUtf8("actionSettings"));
		actionAbout = new QAction(DebugWindow);
		actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
		actionGithub = new QAction(DebugWindow);
		actionGithub->setObjectName(QString::fromUtf8("actionGithub"));
		actionTraceChilds = new QAction(DebugWindow);
		actionTraceChilds->setObjectName(QString::fromUtf8("actionTraceChilds"));
		actionTraceChilds->setCheckable(true);
		actionTraceChilds->setChecked(true);
		actionClearChilds = new QAction(DebugWindow);
		actionClearChilds->setObjectName(QString::fromUtf8("actionClearChilds"));
		actionClearChilds->setEnabled(false);
		actionQuickProcessSelect = new QAction(DebugWindow);
		actionQuickProcessSelect->setObjectName(QString::fromUtf8("actionQuickProcessSelect"));
		actionQuickProcessSelect->setCheckable(true);
		actionQuickProcessCmd = new QAction(DebugWindow);
		actionQuickProcessCmd->setObjectName(QString::fromUtf8("actionQuickProcessCmd"));
		actionQuickProcessCmd->setCheckable(true);
		centralwidget = new QWidget(DebugWindow);
		centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
		gridLayout_2 = new QGridLayout(centralwidget);
		gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
		verticalLayout_3 = new QVBoxLayout();
		verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
		horizontalLayout = new QHBoxLayout();
		horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
		buttonRun = new QPushButton(centralwidget);
		buttonRun->setObjectName(QString::fromUtf8("buttonRun"));
		buttonRun->setMaximumSize(QSize(16777215, 27));

		horizontalLayout->addWidget(buttonRun);

		buttonStop = new QPushButton(centralwidget);
		buttonStop->setObjectName(QString::fromUtf8("buttonStop"));
		buttonStop->setMaximumSize(QSize(16777215, 25));

		horizontalLayout->addWidget(buttonStop);

		buttonClear = new QPushButton(centralwidget);
		buttonClear->setObjectName(QString::fromUtf8("buttonClear"));
		buttonClear->setMaximumSize(QSize(16777215, 25));

		horizontalLayout->addWidget(buttonClear);

		horizontalSpacer_2 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

		horizontalLayout->addItem(horizontalSpacer_2);

		buttonPause = new QPushButton(centralwidget);
		buttonPause->setObjectName(QString::fromUtf8("buttonPause"));
		buttonPause->setMaximumSize(QSize(16777215, 25));
		buttonPause->setCheckable(true);

		horizontalLayout->addWidget(buttonPause);

		horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

		horizontalLayout->addItem(horizontalSpacer_3);

		frame = new QFrame(centralwidget);
		frame->setObjectName(QString::fromUtf8("frame"));
		frame->setFrameShape(QFrame::StyledPanel);
		frame->setFrameShadow(QFrame::Raised);
		gridLayout = new QGridLayout(frame);
		gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
		labelPID = new QLabel(frame);
		labelPID->setObjectName(QString::fromUtf8("labelPID"));

		gridLayout->addWidget(labelPID, 0, 0, 1, 1);

		labelState = new QLabel(frame);
		labelState->setObjectName(QString::fromUtf8("labelState"));

		gridLayout->addWidget(labelState, 1, 0, 1, 1);


		horizontalLayout->addWidget(frame);


		verticalLayout_3->addLayout(horizontalLayout);

		verticalSpacer = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Fixed);

		verticalLayout_3->addItem(verticalSpacer);

		verticalLayout = new QVBoxLayout();
		verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
		processSelector = new QTextEdit(centralwidget);
		processSelector->setObjectName(QString::fromUtf8("processSelector"));
		processSelector->setEnabled(true);
		QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
		sizePolicy.setHorizontalStretch(0);
		sizePolicy.setVerticalStretch(0);
		sizePolicy.setHeightForWidth(processSelector->sizePolicy().hasHeightForWidth());
		processSelector->setSizePolicy(sizePolicy);
		processSelector->setMaximumSize(QSize(16777215, 30));

//		verticalLayout->addWidget(processSelector);

		cmd = new QTextEdit(centralwidget);
		cmd->setObjectName(QString::fromUtf8("cmd"));
		sizePolicy.setHeightForWidth(cmd->sizePolicy().hasHeightForWidth());
		cmd->setSizePolicy(sizePolicy);
		cmd->setMaximumSize(QSize(16777215, 30));

		verticalLayout->addWidget(cmd);


		verticalLayout_3->addLayout(verticalLayout);

		verticalSpacer_2 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Fixed);

		verticalLayout_3->addItem(verticalSpacer_2);

		verticalLayout_2 = new QVBoxLayout();
		verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
		logs = new QTableWidget(centralwidget);
		if (logs->columnCount() < 2)
			logs->setColumnCount(2);
		QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
		logs->setHorizontalHeaderItem(0, __qtablewidgetitem);
		QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
		logs->setHorizontalHeaderItem(1, __qtablewidgetitem1);
		logs->setObjectName(QString::fromUtf8("logs"));

		verticalLayout_2->addWidget(logs);

		filter = new QTextEdit(centralwidget);
		filter->setObjectName(QString::fromUtf8("filter"));
		filter->setMaximumSize(QSize(16777215, 30));

		verticalLayout_2->addWidget(filter);


		verticalLayout_3->addLayout(verticalLayout_2);


		gridLayout_2->addLayout(verticalLayout_3, 0, 2, 1, 1);

		horizontalSpacer = new QSpacerItem(15, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

		gridLayout_2->addItem(horizontalSpacer, 0, 1, 1, 1);

		processTree = new QTreeWidget(centralwidget);
		QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(processTree);
//		new QTreeWidgetItem(__qtreewidgetitem);
//		new QTreeWidgetItem(__qtreewidgetitem);
		processTree->setObjectName(QString::fromUtf8("processTree"));
		QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
		sizePolicy1.setHorizontalStretch(0);
		sizePolicy1.setVerticalStretch(0);
		sizePolicy1.setHeightForWidth(processTree->sizePolicy().hasHeightForWidth());
		processTree->setSizePolicy(sizePolicy1);

		gridLayout_2->addWidget(processTree, 0, 0, 1, 1);

		DebugWindow->setCentralWidget(centralwidget);
		menubar = new QMenuBar(DebugWindow);
		menubar->setObjectName(QString::fromUtf8("menubar"));
		menubar->setGeometry(QRect(0, 0, 946, 30));
		menu_File = new QMenu(menubar);
		menu_File->setObjectName(QString::fromUtf8("menu_File"));
		menu_Tools = new QMenu(menubar);
		menu_Tools->setObjectName(QString::fromUtf8("menu_Tools"));
		menuQuickRun = new QMenu(menu_Tools);
		menuQuickRun->setObjectName(QString::fromUtf8("menuQuickRun"));
		menu_Help = new QMenu(menubar);
		menu_Help->setObjectName(QString::fromUtf8("menu_Help"));
		DebugWindow->setMenuBar(menubar);
		statusbar = new QStatusBar(DebugWindow);
		statusbar->setObjectName(QString::fromUtf8("statusbar"));
		DebugWindow->setStatusBar(statusbar);

		menubar->addAction(menu_File->menuAction());
		menubar->addAction(menu_Tools->menuAction());
		menubar->addAction(menu_Help->menuAction());
		menu_File->addAction(actionSaveAs);
		menu_File->addSeparator();
		menu_Tools->addAction(actionTraceChilds);
		menu_Tools->addAction(actionClearChilds);
		menu_Tools->addSeparator();
		menu_Tools->addAction(menuQuickRun->menuAction());
		menu_Tools->addAction(actionSettings);
		menuQuickRun->addAction(actionQuickProcessSelect);
		menuQuickRun->addAction(actionQuickProcessCmd);
		menu_Help->addSeparator();
		menu_Help->addAction(actionAbout);

		retranslateUi(DebugWindow);

		QMetaObject::connectSlotsByName(DebugWindow);
	} // setupUi

	void retranslateUi(QMainWindow *DebugWindow)
	{
		DebugWindow->setWindowTitle(QCoreApplication::translate("DebugWindow", "MainWindow", nullptr));
		actionSaveAs->setText(QCoreApplication::translate("DebugWindow", "&Save as", nullptr));
		actionSettings->setText(QCoreApplication::translate("DebugWindow", "Settings", nullptr));
		actionAbout->setText(QCoreApplication::translate("DebugWindow", "&About", nullptr));
		actionGithub->setText(QCoreApplication::translate("DebugWindow", "Github", nullptr));
		actionTraceChilds->setText(QCoreApplication::translate("DebugWindow", "Also trace childs", nullptr));
		actionClearChilds->setText(QCoreApplication::translate("DebugWindow", "Clear childs", nullptr));
		actionQuickProcessSelect->setText(QCoreApplication::translate("DebugWindow", "Process Selector", nullptr));
		actionQuickProcessCmd->setText(QCoreApplication::translate("DebugWindow", "Process command", nullptr));
		buttonRun->setText(QCoreApplication::translate("DebugWindow", "Run", nullptr));
		buttonStop->setText(QCoreApplication::translate("DebugWindow", "Stop", nullptr));
		buttonClear->setText(QCoreApplication::translate("DebugWindow", "Clear", nullptr));
		buttonPause->setText(QCoreApplication::translate("DebugWindow", "Pause", nullptr));
		labelPID->setText(QCoreApplication::translate("DebugWindow", "PID: NA", nullptr));
		labelState->setText(QCoreApplication::translate("DebugWindow", "State: RUNNING", nullptr));
		processSelector->setHtml(QCoreApplication::translate("DebugWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
																			"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
																			"p, li { white-space: pre-wrap; }\n"
																			"</style></head><body style=\" font-family:'Noto Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
																			"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
		processSelector->setPlaceholderText(QCoreApplication::translate("DebugWindow", "Enter process name", nullptr));
		cmd->setPlaceholderText(QCoreApplication::translate("DebugWindow", "Enter command", nullptr));
		QTableWidgetItem *___qtablewidgetitem = logs->horizontalHeaderItem(0);
		___qtablewidgetitem->setText(QCoreApplication::translate("DebugWindow", "ID", nullptr));
		QTableWidgetItem *___qtablewidgetitem1 = logs->horizontalHeaderItem(1);
		___qtablewidgetitem1->setText(QCoreApplication::translate("DebugWindow", "args", nullptr));
		filter->setPlaceholderText(QCoreApplication::translate("DebugWindow", "Filter", nullptr));
		QTreeWidgetItem *___qtreewidgetitem = processTree->headerItem();
		___qtreewidgetitem->setText(0, QCoreApplication::translate("DebugWindow", "Process Tree", nullptr));

		const bool __sortingEnabled = processTree->isSortingEnabled();
		processTree->setSortingEnabled(false);
//		QTreeWidgetItem *___qtreewidgetitem1 = processTree->topLevelItem(0);
//		___qtreewidgetitem1->setText(0, QCoreApplication::translate("DebugWindow", "salut", nullptr));
//		QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
//		___qtreewidgetitem2->setText(0, QCoreApplication::translate("DebugWindow", "test", nullptr));
//		QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem1->child(1);
//		___qtreewidgetitem3->setText(0, QCoreApplication::translate("DebugWindow", "test2", nullptr));
		processTree->setSortingEnabled(__sortingEnabled);

		menu_File->setTitle(QCoreApplication::translate("DebugWindow", "&File", nullptr));
		menu_Tools->setTitle(QCoreApplication::translate("DebugWindow", "&Tools", nullptr));
		menuQuickRun->setTitle(QCoreApplication::translate("DebugWindow", "Quick Run", nullptr));
		menu_Help->setTitle(QCoreApplication::translate("DebugWindow", "&Help", nullptr));
	} // retranslateUi

};

namespace Ui {
	class DebugWindow: public Ui_DebugWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DEBUGGER_2D_5KLXPRL_H
