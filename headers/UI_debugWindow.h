/********************************************************************************
** Form generated from reading UI file 'debugger-7sodHQY.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DEBUGGER_2D_7SODHQY_H
#define DEBUGGER_2D_7SODHQY_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
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
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeWidget>
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
	QGridLayout *gridLayout_4;
	QSplitter *splitter;
	QFrame *frame_2;
	QGridLayout *gridLayout_2;
	QSplitter *splitter_3;
	QTreeWidget *processTree;
	QFrame *frame;
	QGridLayout *gridLayout_3;
	QHBoxLayout *horizontalLayout;
	QPushButton *buttonRun;
	QPushButton *buttonFreeze;
	QPushButton *buttonStop;
	QSpacerItem *horizontalSpacer_3;
	QFrame *frame_infos;
	QGridLayout *gridLayout;
	QLabel *labelState;
	QLabel *labelPID;
	QHBoxLayout *horizontalLayout_2;
	QTextEdit *processSelector;
	QTextEdit *cmd;
	QSpacerItem *verticalSpacer;
	QTreeWidget *callLogs;
	QPushButton *buttonClearTable;
	QPushButton *buttonPauseTable;
	QTextEdit *filter;
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
		DebugWindow->resize(961, 671);
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
		actionQuickProcessSelect->setChecked(true);
		actionQuickProcessCmd = new QAction(DebugWindow);
		actionQuickProcessCmd->setObjectName(QString::fromUtf8("actionQuickProcessCmd"));
		actionQuickProcessCmd->setCheckable(true);
		actionQuickProcessCmd->setChecked(true);
		centralwidget = new QWidget(DebugWindow);
		centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
		gridLayout_4 = new QGridLayout(centralwidget);
		gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
		splitter = new QSplitter(centralwidget);
		splitter->setObjectName(QString::fromUtf8("splitter"));
		splitter->setMinimumSize(QSize(0, 0));
		splitter->setOrientation(Qt::Horizontal);
		splitter->setHandleWidth(15);
		frame_2 = new QFrame(splitter);
		frame_2->setObjectName(QString::fromUtf8("frame_2"));
		QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
		sizePolicy.setHorizontalStretch(0);
		sizePolicy.setVerticalStretch(0);
		sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
		frame_2->setSizePolicy(sizePolicy);
		frame_2->setMinimumSize(QSize(120, 0));
		frame_2->setBaseSize(QSize(125, 0));
		frame_2->setFrameShape(QFrame::NoFrame);
		frame_2->setFrameShadow(QFrame::Raised);
		gridLayout_2 = new QGridLayout(frame_2);
		gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
		splitter_3 = new QSplitter(frame_2);
		splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
		QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
		sizePolicy1.setHorizontalStretch(0);
		sizePolicy1.setVerticalStretch(0);
		sizePolicy1.setHeightForWidth(splitter_3->sizePolicy().hasHeightForWidth());
		splitter_3->setSizePolicy(sizePolicy1);
		splitter_3->setOrientation(Qt::Vertical);
		processTree = new QTreeWidget(splitter_3);
		new QTreeWidgetItem(processTree);
		processTree->setObjectName(QString::fromUtf8("processTree"));
		sizePolicy1.setHeightForWidth(processTree->sizePolicy().hasHeightForWidth());
		processTree->setSizePolicy(sizePolicy1);
		processTree->setBaseSize(QSize(0, 0));
		splitter_3->addWidget(processTree);

		gridLayout_2->addWidget(splitter_3, 0, 0, 1, 1);

		splitter->addWidget(frame_2);
		frame = new QFrame(splitter);
		frame->setObjectName(QString::fromUtf8("frame"));
		frame->setFrameShape(QFrame::StyledPanel);
		frame->setFrameShadow(QFrame::Raised);
		gridLayout_3 = new QGridLayout(frame);
		gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
		horizontalLayout = new QHBoxLayout();
		horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
		buttonRun = new QPushButton(frame);
		buttonRun->setObjectName(QString::fromUtf8("buttonRun"));
		QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
		sizePolicy2.setHorizontalStretch(0);
		sizePolicy2.setVerticalStretch(0);
		sizePolicy2.setHeightForWidth(buttonRun->sizePolicy().hasHeightForWidth());
		buttonRun->setSizePolicy(sizePolicy2);
		buttonRun->setMinimumSize(QSize(30, 0));
		buttonRun->setMaximumSize(QSize(16777215, 27));

		horizontalLayout->addWidget(buttonRun);

		buttonFreeze = new QPushButton(frame);
		buttonFreeze->setObjectName(QString::fromUtf8("buttonFreeze"));
		sizePolicy2.setHeightForWidth(buttonFreeze->sizePolicy().hasHeightForWidth());
		buttonFreeze->setSizePolicy(sizePolicy2);
		buttonFreeze->setMinimumSize(QSize(40, 0));
		buttonFreeze->setMaximumSize(QSize(16777215, 25));
		buttonFreeze->setCheckable(true);

		horizontalLayout->addWidget(buttonFreeze);

		buttonStop = new QPushButton(frame);
		buttonStop->setObjectName(QString::fromUtf8("buttonStop"));
		sizePolicy2.setHeightForWidth(buttonStop->sizePolicy().hasHeightForWidth());
		buttonStop->setSizePolicy(sizePolicy2);
		buttonStop->setMinimumSize(QSize(40, 0));
		buttonStop->setMaximumSize(QSize(16777215, 25));

		horizontalLayout->addWidget(buttonStop);

		horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

		horizontalLayout->addItem(horizontalSpacer_3);

		frame_infos = new QFrame(frame);
		frame_infos->setObjectName(QString::fromUtf8("frame_infos"));
		QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
		sizePolicy3.setHorizontalStretch(0);
		sizePolicy3.setVerticalStretch(0);
		sizePolicy3.setHeightForWidth(frame_infos->sizePolicy().hasHeightForWidth());
		frame_infos->setSizePolicy(sizePolicy3);
		frame_infos->setFrameShape(QFrame::StyledPanel);
		frame_infos->setFrameShadow(QFrame::Raised);
		gridLayout = new QGridLayout(frame_infos);
		gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
		labelState = new QLabel(frame_infos);
		labelState->setObjectName(QString::fromUtf8("labelState"));

		gridLayout->addWidget(labelState, 1, 0, 1, 1);

		labelPID = new QLabel(frame_infos);
		labelPID->setObjectName(QString::fromUtf8("labelPID"));

		gridLayout->addWidget(labelPID, 0, 0, 1, 1);


		horizontalLayout->addWidget(frame_infos);


		gridLayout_3->addLayout(horizontalLayout, 0, 0, 1, 3);

		horizontalLayout_2 = new QHBoxLayout();
		horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
		processSelector = new QTextEdit(frame);
		processSelector->setObjectName(QString::fromUtf8("processSelector"));
		processSelector->setEnabled(true);
		QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
		sizePolicy4.setHorizontalStretch(0);
		sizePolicy4.setVerticalStretch(0);
		sizePolicy4.setHeightForWidth(processSelector->sizePolicy().hasHeightForWidth());
		processSelector->setSizePolicy(sizePolicy4);
		processSelector->setMaximumSize(QSize(16777215, 30));

		horizontalLayout_2->addWidget(processSelector);

		cmd = new QTextEdit(frame);
		cmd->setObjectName(QString::fromUtf8("cmd"));
		sizePolicy4.setHeightForWidth(cmd->sizePolicy().hasHeightForWidth());
		cmd->setSizePolicy(sizePolicy4);
		cmd->setMaximumSize(QSize(16777215, 30));

		horizontalLayout_2->addWidget(cmd);


		gridLayout_3->addLayout(horizontalLayout_2, 1, 0, 1, 3);

		verticalSpacer = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Maximum);

		gridLayout_3->addItem(verticalSpacer, 2, 2, 1, 1);

		callLogs = new QTreeWidget(frame);
		new QTreeWidgetItem(callLogs);
		new QTreeWidgetItem(callLogs);
		new QTreeWidgetItem(callLogs);
		new QTreeWidgetItem(callLogs);
		new QTreeWidgetItem(callLogs);
		new QTreeWidgetItem(callLogs);
		new QTreeWidgetItem(callLogs);
		new QTreeWidgetItem(callLogs);
		new QTreeWidgetItem(callLogs);
		new QTreeWidgetItem(callLogs);
		new QTreeWidgetItem(callLogs);
		new QTreeWidgetItem(callLogs);
		new QTreeWidgetItem(callLogs);
		new QTreeWidgetItem(callLogs);
		new QTreeWidgetItem(callLogs);
		callLogs->setObjectName(QString::fromUtf8("callLogs"));
		QSizePolicy sizePolicy5(QSizePolicy::Ignored, QSizePolicy::Expanding);
		sizePolicy5.setHorizontalStretch(0);
		sizePolicy5.setVerticalStretch(0);
		sizePolicy5.setHeightForWidth(callLogs->sizePolicy().hasHeightForWidth());
		callLogs->setSizePolicy(sizePolicy5);
		callLogs->setMinimumSize(QSize(0, 0));

		gridLayout_3->addWidget(callLogs, 3, 0, 1, 3);

		buttonClearTable = new QPushButton(frame);
		buttonClearTable->setObjectName(QString::fromUtf8("buttonClearTable"));
		buttonClearTable->setMinimumSize(QSize(32, 0));
		QIcon icon;
		icon.addFile(QString::fromUtf8(":/imgs/clean.png"), QSize(), QIcon::Normal, QIcon::Off);
		buttonClearTable->setIcon(icon);

		gridLayout_3->addWidget(buttonClearTable, 4, 0, 1, 1);

		buttonPauseTable = new QPushButton(frame);
		buttonPauseTable->setObjectName(QString::fromUtf8("buttonPauseTable"));
		buttonPauseTable->setMinimumSize(QSize(32, 0));
		QIcon icon1;
		icon1.addFile(QString::fromUtf8(":/imgs/pause.png"), QSize(), QIcon::Normal, QIcon::Off);
		buttonPauseTable->setIcon(icon1);

		gridLayout_3->addWidget(buttonPauseTable, 4, 1, 1, 1);

		filter = new QTextEdit(frame);
		filter->setObjectName(QString::fromUtf8("filter"));
		filter->setMaximumSize(QSize(16777215, 30));

		gridLayout_3->addWidget(filter, 4, 2, 1, 1);

		splitter->addWidget(frame);

		gridLayout_4->addWidget(splitter, 0, 0, 1, 1);

		DebugWindow->setCentralWidget(centralwidget);
		menubar = new QMenuBar(DebugWindow);
		menubar->setObjectName(QString::fromUtf8("menubar"));
		menubar->setGeometry(QRect(0, 0, 961, 30));
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
		QTreeWidgetItem *___qtreewidgetitem = processTree->headerItem();
		___qtreewidgetitem->setText(0, QCoreApplication::translate("DebugWindow", "Process Tree", nullptr));

		const bool __sortingEnabled = processTree->isSortingEnabled();
		processTree->setSortingEnabled(false);
		QTreeWidgetItem *___qtreewidgetitem1 = processTree->topLevelItem(0);
		___qtreewidgetitem1->setText(0, QCoreApplication::translate("DebugWindow", "NA", nullptr));
		processTree->setSortingEnabled(__sortingEnabled);

		buttonRun->setText(QCoreApplication::translate("DebugWindow", "Run", nullptr));
		buttonFreeze->setText(QCoreApplication::translate("DebugWindow", "Freeze", nullptr));
		buttonStop->setText(QCoreApplication::translate("DebugWindow", "Stop", nullptr));
		labelState->setText(QCoreApplication::translate("DebugWindow", "State: RUNNING", nullptr));
		labelPID->setText(QCoreApplication::translate("DebugWindow", "PID: NA", nullptr));
		processSelector->setHtml(QCoreApplication::translate("DebugWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
																			"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
																			"p, li { white-space: pre-wrap; }\n"
																			"</style></head><body style=\" font-family:'Noto Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
																			"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
		processSelector->setPlaceholderText(QCoreApplication::translate("DebugWindow", "Enter process name", nullptr));
		cmd->setPlaceholderText(QCoreApplication::translate("DebugWindow", "Enter command", nullptr));
		QTreeWidgetItem *___qtreewidgetitem2 = callLogs->headerItem();
		___qtreewidgetitem2->setText(7, QCoreApplication::translate("DebugWindow", "result", nullptr));
		___qtreewidgetitem2->setText(6, QCoreApplication::translate("DebugWindow", "arg6", nullptr));
		___qtreewidgetitem2->setText(5, QCoreApplication::translate("DebugWindow", "arg5", nullptr));
		___qtreewidgetitem2->setText(4, QCoreApplication::translate("DebugWindow", "arg4", nullptr));
		___qtreewidgetitem2->setText(3, QCoreApplication::translate("DebugWindow", "arg3", nullptr));
		___qtreewidgetitem2->setText(2, QCoreApplication::translate("DebugWindow", "arg2", nullptr));
		___qtreewidgetitem2->setText(1, QCoreApplication::translate("DebugWindow", "arg1", nullptr));
		___qtreewidgetitem2->setText(0, QCoreApplication::translate("DebugWindow", "ID", nullptr));

		const bool __sortingEnabled1 = callLogs->isSortingEnabled();
		callLogs->setSortingEnabled(false);
		QTreeWidgetItem *___qtreewidgetitem3 = callLogs->topLevelItem(0);
		___qtreewidgetitem3->setText(7, QCoreApplication::translate("DebugWindow", "8192", nullptr));
		___qtreewidgetitem3->setText(6, QCoreApplication::translate("DebugWindow", "4294967296", nullptr));
		___qtreewidgetitem3->setText(5, QCoreApplication::translate("DebugWindow", "4294967296", nullptr));
		___qtreewidgetitem3->setText(4, QCoreApplication::translate("DebugWindow", "4294967296", nullptr));
		___qtreewidgetitem3->setText(3, QCoreApplication::translate("DebugWindow", "4294967296", nullptr));
		___qtreewidgetitem3->setText(2, QCoreApplication::translate("DebugWindow", "4294967296", nullptr));
		___qtreewidgetitem3->setText(1, QCoreApplication::translate("DebugWindow", "4294967296", nullptr));
		___qtreewidgetitem3->setText(0, QCoreApplication::translate("DebugWindow", "156", nullptr));
		QTreeWidgetItem *___qtreewidgetitem4 = callLogs->topLevelItem(1);
		___qtreewidgetitem4->setText(3, QCoreApplication::translate("DebugWindow", "4", nullptr));
		___qtreewidgetitem4->setText(2, QCoreApplication::translate("DebugWindow", "Salut!", nullptr));
		___qtreewidgetitem4->setText(1, QCoreApplication::translate("DebugWindow", "1", nullptr));
		___qtreewidgetitem4->setText(0, QCoreApplication::translate("DebugWindow", "write", nullptr));
		QTreeWidgetItem *___qtreewidgetitem5 = callLogs->topLevelItem(2);
		___qtreewidgetitem5->setText(7, QCoreApplication::translate("DebugWindow", "8192", nullptr));
		___qtreewidgetitem5->setText(6, QCoreApplication::translate("DebugWindow", "4294967296", nullptr));
		___qtreewidgetitem5->setText(5, QCoreApplication::translate("DebugWindow", "4294967296", nullptr));
		___qtreewidgetitem5->setText(4, QCoreApplication::translate("DebugWindow", "4294967296", nullptr));
		___qtreewidgetitem5->setText(3, QCoreApplication::translate("DebugWindow", "4294967296", nullptr));
		___qtreewidgetitem5->setText(2, QCoreApplication::translate("DebugWindow", "4294967296", nullptr));
		___qtreewidgetitem5->setText(1, QCoreApplication::translate("DebugWindow", "4294967296", nullptr));
		___qtreewidgetitem5->setText(0, QCoreApplication::translate("DebugWindow", "156", nullptr));
		QTreeWidgetItem *___qtreewidgetitem6 = callLogs->topLevelItem(3);
		___qtreewidgetitem6->setText(3, QCoreApplication::translate("DebugWindow", "4", nullptr));
		___qtreewidgetitem6->setText(2, QCoreApplication::translate("DebugWindow", "Salut!", nullptr));
		___qtreewidgetitem6->setText(1, QCoreApplication::translate("DebugWindow", "1", nullptr));
		___qtreewidgetitem6->setText(0, QCoreApplication::translate("DebugWindow", "write", nullptr));
		QTreeWidgetItem *___qtreewidgetitem7 = callLogs->topLevelItem(4);
		___qtreewidgetitem7->setText(7, QCoreApplication::translate("DebugWindow", "8192", nullptr));
		___qtreewidgetitem7->setText(6, QCoreApplication::translate("DebugWindow", "4294967296", nullptr));
		___qtreewidgetitem7->setText(5, QCoreApplication::translate("DebugWindow", "4294967296", nullptr));
		___qtreewidgetitem7->setText(4, QCoreApplication::translate("DebugWindow", "4294967296", nullptr));
		___qtreewidgetitem7->setText(3, QCoreApplication::translate("DebugWindow", "4294967296", nullptr));
		___qtreewidgetitem7->setText(2, QCoreApplication::translate("DebugWindow", "4294967296", nullptr));
		___qtreewidgetitem7->setText(1, QCoreApplication::translate("DebugWindow", "4294967296", nullptr));
		___qtreewidgetitem7->setText(0, QCoreApplication::translate("DebugWindow", "156", nullptr));
		QTreeWidgetItem *___qtreewidgetitem8 = callLogs->topLevelItem(5);
		___qtreewidgetitem8->setText(3, QCoreApplication::translate("DebugWindow", "4", nullptr));
		___qtreewidgetitem8->setText(2, QCoreApplication::translate("DebugWindow", "Salut!", nullptr));
		___qtreewidgetitem8->setText(1, QCoreApplication::translate("DebugWindow", "1", nullptr));
		___qtreewidgetitem8->setText(0, QCoreApplication::translate("DebugWindow", "write", nullptr));
		QTreeWidgetItem *___qtreewidgetitem9 = callLogs->topLevelItem(6);
		___qtreewidgetitem9->setText(7, QCoreApplication::translate("DebugWindow", "8192", nullptr));
		___qtreewidgetitem9->setText(6, QCoreApplication::translate("DebugWindow", "4294967296", nullptr));
		___qtreewidgetitem9->setText(5, QCoreApplication::translate("DebugWindow", "4294967296", nullptr));
		___qtreewidgetitem9->setText(4, QCoreApplication::translate("DebugWindow", "4294967296", nullptr));
		___qtreewidgetitem9->setText(3, QCoreApplication::translate("DebugWindow", "4294967296", nullptr));
		___qtreewidgetitem9->setText(2, QCoreApplication::translate("DebugWindow", "4294967296", nullptr));
		___qtreewidgetitem9->setText(1, QCoreApplication::translate("DebugWindow", "4294967296", nullptr));
		___qtreewidgetitem9->setText(0, QCoreApplication::translate("DebugWindow", "156", nullptr));
		QTreeWidgetItem *___qtreewidgetitem10 = callLogs->topLevelItem(7);
		___qtreewidgetitem10->setText(3, QCoreApplication::translate("DebugWindow", "4", nullptr));
		___qtreewidgetitem10->setText(2, QCoreApplication::translate("DebugWindow", "Salut!", nullptr));
		___qtreewidgetitem10->setText(1, QCoreApplication::translate("DebugWindow", "1", nullptr));
		___qtreewidgetitem10->setText(0, QCoreApplication::translate("DebugWindow", "write", nullptr));
		QTreeWidgetItem *___qtreewidgetitem11 = callLogs->topLevelItem(8);
		___qtreewidgetitem11->setText(7, QCoreApplication::translate("DebugWindow", "8192", nullptr));
		___qtreewidgetitem11->setText(6, QCoreApplication::translate("DebugWindow", "4294967296", nullptr));
		___qtreewidgetitem11->setText(5, QCoreApplication::translate("DebugWindow", "4294967296", nullptr));
		___qtreewidgetitem11->setText(4, QCoreApplication::translate("DebugWindow", "4294967296", nullptr));
		___qtreewidgetitem11->setText(3, QCoreApplication::translate("DebugWindow", "4294967296", nullptr));
		___qtreewidgetitem11->setText(2, QCoreApplication::translate("DebugWindow", "4294967296", nullptr));
		___qtreewidgetitem11->setText(1, QCoreApplication::translate("DebugWindow", "4294967296", nullptr));
		___qtreewidgetitem11->setText(0, QCoreApplication::translate("DebugWindow", "156", nullptr));
		QTreeWidgetItem *___qtreewidgetitem12 = callLogs->topLevelItem(9);
		___qtreewidgetitem12->setText(3, QCoreApplication::translate("DebugWindow", "4", nullptr));
		___qtreewidgetitem12->setText(2, QCoreApplication::translate("DebugWindow", "Salut!", nullptr));
		___qtreewidgetitem12->setText(1, QCoreApplication::translate("DebugWindow", "1", nullptr));
		___qtreewidgetitem12->setText(0, QCoreApplication::translate("DebugWindow", "write", nullptr));
		QTreeWidgetItem *___qtreewidgetitem13 = callLogs->topLevelItem(10);
		___qtreewidgetitem13->setText(7, QCoreApplication::translate("DebugWindow", "8192", nullptr));
		___qtreewidgetitem13->setText(6, QCoreApplication::translate("DebugWindow", "4294967296", nullptr));
		___qtreewidgetitem13->setText(5, QCoreApplication::translate("DebugWindow", "4294967296", nullptr));
		___qtreewidgetitem13->setText(4, QCoreApplication::translate("DebugWindow", "4294967296", nullptr));
		___qtreewidgetitem13->setText(3, QCoreApplication::translate("DebugWindow", "4294967296", nullptr));
		___qtreewidgetitem13->setText(2, QCoreApplication::translate("DebugWindow", "4294967296", nullptr));
		___qtreewidgetitem13->setText(1, QCoreApplication::translate("DebugWindow", "4294967296", nullptr));
		___qtreewidgetitem13->setText(0, QCoreApplication::translate("DebugWindow", "156", nullptr));
		QTreeWidgetItem *___qtreewidgetitem14 = callLogs->topLevelItem(11);
		___qtreewidgetitem14->setText(3, QCoreApplication::translate("DebugWindow", "4", nullptr));
		___qtreewidgetitem14->setText(2, QCoreApplication::translate("DebugWindow", "Salut!", nullptr));
		___qtreewidgetitem14->setText(1, QCoreApplication::translate("DebugWindow", "1", nullptr));
		___qtreewidgetitem14->setText(0, QCoreApplication::translate("DebugWindow", "write", nullptr));
		QTreeWidgetItem *___qtreewidgetitem15 = callLogs->topLevelItem(12);
		___qtreewidgetitem15->setText(7, QCoreApplication::translate("DebugWindow", "8192", nullptr));
		___qtreewidgetitem15->setText(6, QCoreApplication::translate("DebugWindow", "4294967296", nullptr));
		___qtreewidgetitem15->setText(5, QCoreApplication::translate("DebugWindow", "4294967296", nullptr));
		___qtreewidgetitem15->setText(4, QCoreApplication::translate("DebugWindow", "4294967296", nullptr));
		___qtreewidgetitem15->setText(3, QCoreApplication::translate("DebugWindow", "4294967296", nullptr));
		___qtreewidgetitem15->setText(2, QCoreApplication::translate("DebugWindow", "4294967296", nullptr));
		___qtreewidgetitem15->setText(1, QCoreApplication::translate("DebugWindow", "4294967296", nullptr));
		___qtreewidgetitem15->setText(0, QCoreApplication::translate("DebugWindow", "156", nullptr));
		QTreeWidgetItem *___qtreewidgetitem16 = callLogs->topLevelItem(13);
		___qtreewidgetitem16->setText(3, QCoreApplication::translate("DebugWindow", "4", nullptr));
		___qtreewidgetitem16->setText(2, QCoreApplication::translate("DebugWindow", "Salut!", nullptr));
		___qtreewidgetitem16->setText(1, QCoreApplication::translate("DebugWindow", "1", nullptr));
		___qtreewidgetitem16->setText(0, QCoreApplication::translate("DebugWindow", "write", nullptr));
		QTreeWidgetItem *___qtreewidgetitem17 = callLogs->topLevelItem(14);
		___qtreewidgetitem17->setText(4, QCoreApplication::translate("DebugWindow", "25", nullptr));
		___qtreewidgetitem17->setText(3, QCoreApplication::translate("DebugWindow", "85", nullptr));
		___qtreewidgetitem17->setText(2, QCoreApplication::translate("DebugWindow", "65", nullptr));
		___qtreewidgetitem17->setText(1, QCoreApplication::translate("DebugWindow", "45", nullptr));
		___qtreewidgetitem17->setText(0, QCoreApplication::translate("DebugWindow", "56", nullptr));
		callLogs->setSortingEnabled(__sortingEnabled1);

		buttonClearTable->setText(QString());
		buttonPauseTable->setText(QString());
		filter->setPlaceholderText(QCoreApplication::translate("DebugWindow", "Filter", nullptr));
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

#endif // DEBUGGER_2D_7SODHQY_H
