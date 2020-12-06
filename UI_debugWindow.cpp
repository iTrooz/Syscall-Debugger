/********************************************************************************
** Form generated from reading UI file 'debugger-4SqORth.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DEBUGGER_2D_4SQORTH_H
#define DEBUGGER_2D_4SQORTH_H

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
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QTreeWidget *subProcessView;
    QVBoxLayout *verticalLayout;
    QFrame *ProcessMenu;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *buttonRun;
    QPushButton *buttonStop;
    QPushButton *buttonClear;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *buttonPause;
    QGridLayout *ProcessSelect;
    QLabel *PID;
    QTextEdit *cmd;
    QFrame *Viewer;
    QGridLayout *gridLayout;
    QTableWidget *TableView;
    QTextEdit *Filter;
    QMenuBar *menubar;
    QMenu *menu_File;
    QMenu *menu_Tools;
    QMenu *menu_Help;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DebugWindow)
    {
        if (DebugWindow->objectName().isEmpty())
            DebugWindow->setObjectName(QString::fromUtf8("DebugWindow"));
        DebugWindow->resize(868, 678);
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
        actionClearChilds = new QAction(DebugWindow);
        actionClearChilds->setObjectName(QString::fromUtf8("actionClearChilds"));
        actionClearChilds->setEnabled(false);
        centralwidget = new QWidget(DebugWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        subProcessView = new QTreeWidget(centralwidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(subProcessView);
        new QTreeWidgetItem(__qtreewidgetitem);
        subProcessView->setObjectName(QString::fromUtf8("subProcessView"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(subProcessView->sizePolicy().hasHeightForWidth());
        subProcessView->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(subProcessView);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        ProcessMenu = new QFrame(centralwidget);
        ProcessMenu->setObjectName(QString::fromUtf8("ProcessMenu"));
        ProcessMenu->setFrameShape(QFrame::StyledPanel);
        ProcessMenu->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(ProcessMenu);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 0, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        buttonRun = new QPushButton(ProcessMenu);
        buttonRun->setObjectName(QString::fromUtf8("buttonRun"));

        horizontalLayout->addWidget(buttonRun);

        buttonStop = new QPushButton(ProcessMenu);
        buttonStop->setObjectName(QString::fromUtf8("buttonStop"));

        horizontalLayout->addWidget(buttonStop);

        buttonClear = new QPushButton(ProcessMenu);
        buttonClear->setObjectName(QString::fromUtf8("buttonClear"));

        horizontalLayout->addWidget(buttonClear);


        horizontalLayout_3->addLayout(horizontalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        buttonPause = new QPushButton(ProcessMenu);
        buttonPause->setObjectName(QString::fromUtf8("buttonPause"));
        buttonPause->setCheckable(true);

        horizontalLayout_2->addWidget(buttonPause);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        gridLayout_3->addLayout(horizontalLayout_3, 0, 0, 1, 1);


        verticalLayout->addWidget(ProcessMenu);

        ProcessSelect = new QGridLayout();
        ProcessSelect->setObjectName(QString::fromUtf8("ProcessSelect"));
        PID = new QLabel(centralwidget);
        PID->setObjectName(QString::fromUtf8("PID"));

        ProcessSelect->addWidget(PID, 0, 1, 1, 1);

        cmd = new QTextEdit(centralwidget);
        cmd->setObjectName(QString::fromUtf8("cmd"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cmd->sizePolicy().hasHeightForWidth());
        cmd->setSizePolicy(sizePolicy1);
        cmd->setMaximumSize(QSize(16777215, 30));

        ProcessSelect->addWidget(cmd, 0, 0, 1, 1);


        verticalLayout->addLayout(ProcessSelect);

        Viewer = new QFrame(centralwidget);
        Viewer->setObjectName(QString::fromUtf8("Viewer"));
        Viewer->setFrameShape(QFrame::StyledPanel);
        Viewer->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(Viewer);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        TableView = new QTableWidget(Viewer);
        if (TableView->columnCount() < 2)
            TableView->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        TableView->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        TableView->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        TableView->setObjectName(QString::fromUtf8("TableView"));

        gridLayout->addWidget(TableView, 1, 0, 1, 1);

        Filter = new QTextEdit(Viewer);
        Filter->setObjectName(QString::fromUtf8("Filter"));
        Filter->setMaximumSize(QSize(16777215, 30));

        gridLayout->addWidget(Filter, 0, 0, 1, 1);


        verticalLayout->addWidget(Viewer);


        horizontalLayout_4->addLayout(verticalLayout);


        gridLayout_2->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        DebugWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DebugWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 868, 30));
        menu_File = new QMenu(menubar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        menu_Tools = new QMenu(menubar);
        menu_Tools->setObjectName(QString::fromUtf8("menu_Tools"));
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
        menu_Tools->addAction(actionSettings);
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
        QTreeWidgetItem *___qtreewidgetitem = subProcessView->headerItem();
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("DebugWindow", "Data", nullptr));

        const bool __sortingEnabled = subProcessView->isSortingEnabled();
        subProcessView->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = subProcessView->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QCoreApplication::translate("DebugWindow", "salut", nullptr));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(0, QCoreApplication::translate("DebugWindow", "test", nullptr));
        subProcessView->setSortingEnabled(__sortingEnabled);

        buttonRun->setText(QCoreApplication::translate("DebugWindow", "Rerun", nullptr));
        buttonStop->setText(QCoreApplication::translate("DebugWindow", "Stop", nullptr));
        buttonClear->setText(QCoreApplication::translate("DebugWindow", "Clear", nullptr));
        buttonPause->setText(QCoreApplication::translate("DebugWindow", "Pause", nullptr));
        PID->setText(QCoreApplication::translate("DebugWindow", "No PID", nullptr));
        cmd->setPlaceholderText(QCoreApplication::translate("DebugWindow", "Enter command", nullptr));
        QTableWidgetItem *___qtablewidgetitem = TableView->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("DebugWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = TableView->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("DebugWindow", "args", nullptr));
        Filter->setPlaceholderText(QCoreApplication::translate("DebugWindow", "Filter", nullptr));
        menu_File->setTitle(QCoreApplication::translate("DebugWindow", "&File", nullptr));
        menu_Tools->setTitle(QCoreApplication::translate("DebugWindow", "&Tools", nullptr));
        menu_Help->setTitle(QCoreApplication::translate("DebugWindow", "&Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DebugWindow: public Ui_DebugWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DEBUGGER_2D_4SQORTH_H
