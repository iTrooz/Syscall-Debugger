/********************************************************************************
** Form generated from reading UI file 'debuggeryqfrDh.ui_build'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DEBUGGERYQFRDH_H
#define DEBUGGERYQFRDH_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
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
	QTreeWidget *processTree;
	QFrame *frame;
	QGridLayout *gridLayout_3;
	QHBoxLayout *horizontalLayout;
	QPushButton *bRun;
	QPushButton *bFreeze;
	QPushButton *bStop;
	QSpacerItem *horizontalSpacer_3;
	QFrame *frame_infos;
	QGridLayout *gridLayout;
	QLabel *labelState;
	QLabel *labelPID;
	QSplitter *splitter_2;
	QLineEdit *cmd;
	QWidget *layoutWidget;
	QGridLayout *gridLayout_5;
	QLineEdit *processSelect;
	QPushButton *bProcessSelect;
	QSpacerItem *verticalSpacer;
	QTableWidget *callLogs;
	QPushButton *bClearCallLogs;
	QPushButton *bPlayPauseTable;
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
		DebugWindow->resize(961, 658);
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
		frame_2->setEnabled(true);
		QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
		sizePolicy.setHorizontalStretch(0);
		sizePolicy.setVerticalStretch(0);
		sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
		frame_2->setSizePolicy(sizePolicy);
		frame_2->setMinimumSize(QSize(120, 0));
		frame_2->setMaximumSize(QSize(250, 16777215));
		frame_2->setBaseSize(QSize(0, 0));
		frame_2->setFrameShape(QFrame::NoFrame);
		frame_2->setFrameShadow(QFrame::Raised);
		gridLayout_2 = new QGridLayout(frame_2);
		gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
		gridLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
		processTree = new QTreeWidget(frame_2);
		new QTreeWidgetItem(processTree);
		processTree->setObjectName(QString::fromUtf8("processTree"));
		QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
		sizePolicy1.setHorizontalStretch(0);
		sizePolicy1.setVerticalStretch(0);
		sizePolicy1.setHeightForWidth(processTree->sizePolicy().hasHeightForWidth());
		processTree->setSizePolicy(sizePolicy1);
		processTree->setMaximumSize(QSize(16777215, 16777215));
		processTree->setBaseSize(QSize(0, 0));

		gridLayout_2->addWidget(processTree, 0, 0, 1, 1);

		splitter->addWidget(frame_2);
		frame = new QFrame(splitter);
		frame->setObjectName(QString::fromUtf8("frame"));
		frame->setFrameShape(QFrame::StyledPanel);
		frame->setFrameShadow(QFrame::Raised);
		gridLayout_3 = new QGridLayout(frame);
		gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
		horizontalLayout = new QHBoxLayout();
		horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
		bRun = new QPushButton(frame);
		bRun->setObjectName(QString::fromUtf8("bRun"));
		QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
		sizePolicy2.setHorizontalStretch(0);
		sizePolicy2.setVerticalStretch(0);
		sizePolicy2.setHeightForWidth(bRun->sizePolicy().hasHeightForWidth());
		bRun->setSizePolicy(sizePolicy2);
		bRun->setMinimumSize(QSize(30, 0));
		bRun->setMaximumSize(QSize(16777215, 27));

		horizontalLayout->addWidget(bRun);

		bFreeze = new QPushButton(frame);
		bFreeze->setObjectName(QString::fromUtf8("bFreeze"));
		sizePolicy2.setHeightForWidth(bFreeze->sizePolicy().hasHeightForWidth());
		bFreeze->setSizePolicy(sizePolicy2);
		bFreeze->setMinimumSize(QSize(40, 0));
		bFreeze->setMaximumSize(QSize(16777215, 25));
		bFreeze->setCheckable(true);

		horizontalLayout->addWidget(bFreeze);

		bStop = new QPushButton(frame);
		bStop->setObjectName(QString::fromUtf8("bStop"));
		sizePolicy2.setHeightForWidth(bStop->sizePolicy().hasHeightForWidth());
		bStop->setSizePolicy(sizePolicy2);
		bStop->setMinimumSize(QSize(40, 0));
		bStop->setMaximumSize(QSize(16777215, 25));

		horizontalLayout->addWidget(bStop);

		horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

		horizontalLayout->addItem(horizontalSpacer_3);

		frame_infos = new QFrame(frame);
		frame_infos->setObjectName(QString::fromUtf8("frame_infos"));
		sizePolicy.setHeightForWidth(frame_infos->sizePolicy().hasHeightForWidth());
		frame_infos->setSizePolicy(sizePolicy);
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

		splitter_2 = new QSplitter(frame);
		splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
		splitter_2->setOrientation(Qt::Horizontal);
		splitter_2->setHandleWidth(12);
		cmd = new QLineEdit(splitter_2);
		cmd->setObjectName(QString::fromUtf8("cmd"));
		splitter_2->addWidget(cmd);
		layoutWidget = new QWidget(splitter_2);
		layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
		gridLayout_5 = new QGridLayout(layoutWidget);
		gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
		gridLayout_5->setContentsMargins(0, 0, 0, 0);
		processSelect = new QLineEdit(layoutWidget);
		processSelect->setObjectName(QString::fromUtf8("processSelect"));
		processSelect->setEnabled(false);

		gridLayout_5->addWidget(processSelect, 0, 0, 1, 1);

		bProcessSelect = new QPushButton(layoutWidget);
		bProcessSelect->setObjectName(QString::fromUtf8("bProcessSelect"));
		bProcessSelect->setMinimumSize(QSize(32, 0));
		QIcon icon;
		icon.addFile(QString::fromUtf8(":/images/processSelect.png"), QSize(), QIcon::Normal, QIcon::Off);
		bProcessSelect->setIcon(icon);

		gridLayout_5->addWidget(bProcessSelect, 0, 1, 1, 1);

		splitter_2->addWidget(layoutWidget);

		gridLayout_3->addWidget(splitter_2, 1, 0, 1, 3);

		verticalSpacer = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Maximum);

		gridLayout_3->addItem(verticalSpacer, 2, 2, 1, 1);

		callLogs = new QTableWidget(frame);
		if (callLogs->columnCount() < 8)
			callLogs->setColumnCount(8);
		QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
		callLogs->setHorizontalHeaderItem(0, __qtablewidgetitem);
		QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
		callLogs->setHorizontalHeaderItem(1, __qtablewidgetitem1);
		QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
		callLogs->setHorizontalHeaderItem(2, __qtablewidgetitem2);
		QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
		callLogs->setHorizontalHeaderItem(3, __qtablewidgetitem3);
		QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
		callLogs->setHorizontalHeaderItem(4, __qtablewidgetitem4);
		QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
		callLogs->setHorizontalHeaderItem(5, __qtablewidgetitem5);
		QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
		callLogs->setHorizontalHeaderItem(6, __qtablewidgetitem6);
		QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
		callLogs->setHorizontalHeaderItem(7, __qtablewidgetitem7);
		callLogs->setObjectName(QString::fromUtf8("callLogs"));
		QSizePolicy sizePolicy3(QSizePolicy::Ignored, QSizePolicy::Expanding);
		sizePolicy3.setHorizontalStretch(0);
		sizePolicy3.setVerticalStretch(0);
		sizePolicy3.setHeightForWidth(callLogs->sizePolicy().hasHeightForWidth());
		callLogs->setSizePolicy(sizePolicy3);
		callLogs->setMinimumSize(QSize(0, 0));
		callLogs->setAlternatingRowColors(false);
		callLogs->horizontalHeader()->setCascadingSectionResizes(false);
		callLogs->horizontalHeader()->setMinimumSectionSize(50);
		callLogs->horizontalHeader()->setDefaultSectionSize(80);
		callLogs->horizontalHeader()->setHighlightSections(true);
		callLogs->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
		callLogs->horizontalHeader()->setStretchLastSection(false);
		callLogs->verticalHeader()->setVisible(false);

		gridLayout_3->addWidget(callLogs, 3, 0, 1, 3);

		bClearCallLogs = new QPushButton(frame);
		bClearCallLogs->setObjectName(QString::fromUtf8("bClearCallLogs"));
		bClearCallLogs->setMinimumSize(QSize(32, 0));
		QIcon icon1;
		icon1.addFile(QString::fromUtf8(":/images/clean.png"), QSize(), QIcon::Normal, QIcon::Off);
		bClearCallLogs->setIcon(icon1);

		gridLayout_3->addWidget(bClearCallLogs, 4, 0, 1, 1);

		bPlayPauseTable = new QPushButton(frame);
		bPlayPauseTable->setObjectName(QString::fromUtf8("bPlayPauseTable"));
		bPlayPauseTable->setMinimumSize(QSize(32, 0));
		QIcon icon2;
		icon2.addFile(QString::fromUtf8(":/images/pause.png"), QSize(), QIcon::Normal, QIcon::Off);
		bPlayPauseTable->setIcon(icon2);

		gridLayout_3->addWidget(bPlayPauseTable, 4, 1, 1, 1);

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
		DebugWindow->setWindowTitle(QCoreApplication::translate("DebugWindow", "Syscall Debugger", nullptr));
#if QT_CONFIG(accessibility)
		DebugWindow->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
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

		bRun->setText(QCoreApplication::translate("DebugWindow", "Run", nullptr));
		bFreeze->setText(QCoreApplication::translate("DebugWindow", "Freeze", nullptr));
		bStop->setText(QCoreApplication::translate("DebugWindow", "Stop", nullptr));
		labelState->setText(QCoreApplication::translate("DebugWindow", "State: RUNNING", nullptr));
		labelPID->setText(QCoreApplication::translate("DebugWindow", "PID: NA", nullptr));
		cmd->setPlaceholderText(QCoreApplication::translate("DebugWindow", "Enter command", nullptr));
		processSelect->setText(QString());
		processSelect->setPlaceholderText(QCoreApplication::translate("DebugWindow", "Choose running process", nullptr));
		bProcessSelect->setText(QString());
		QTableWidgetItem *___qtablewidgetitem = callLogs->horizontalHeaderItem(0);
		___qtablewidgetitem->setText(QCoreApplication::translate("DebugWindow", "ID", nullptr));
		QTableWidgetItem *___qtablewidgetitem1 = callLogs->horizontalHeaderItem(1);
		___qtablewidgetitem1->setText(QCoreApplication::translate("DebugWindow", "arg1", nullptr));
		QTableWidgetItem *___qtablewidgetitem2 = callLogs->horizontalHeaderItem(2);
		___qtablewidgetitem2->setText(QCoreApplication::translate("DebugWindow", "arg2", nullptr));
		QTableWidgetItem *___qtablewidgetitem3 = callLogs->horizontalHeaderItem(3);
		___qtablewidgetitem3->setText(QCoreApplication::translate("DebugWindow", "arg3", nullptr));
		QTableWidgetItem *___qtablewidgetitem4 = callLogs->horizontalHeaderItem(4);
		___qtablewidgetitem4->setText(QCoreApplication::translate("DebugWindow", "arg4", nullptr));
		QTableWidgetItem *___qtablewidgetitem5 = callLogs->horizontalHeaderItem(5);
		___qtablewidgetitem5->setText(QCoreApplication::translate("DebugWindow", "arg5", nullptr));
		QTableWidgetItem *___qtablewidgetitem6 = callLogs->horizontalHeaderItem(6);
		___qtablewidgetitem6->setText(QCoreApplication::translate("DebugWindow", "arg6", nullptr));
		QTableWidgetItem *___qtablewidgetitem7 = callLogs->horizontalHeaderItem(7);
		___qtablewidgetitem7->setText(QCoreApplication::translate("DebugWindow", "result", nullptr));
		bClearCallLogs->setText(QString());
		bPlayPauseTable->setText(QString());
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

#endif // DEBUGGERYQFRDH_H
