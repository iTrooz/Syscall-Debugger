/********************************************************************************
** Form generated from reading UI file 'debugger-3VZpBwn.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DEBUGGER_2D_3VZPBWN_H
#define DEBUGGER_2D_3VZPBWN_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DebugWindow
{
public:
    QAction *actionSave_as;
    QAction *actionSettings;
    QAction *actionAbout;
    QAction *actionGithub;
    QAction *Childs_Windows;
    QAction *actionNew;
    QWidget *centralwidget;
    QGridLayout *gridLayout_4;
    QFrame *ProcessMenu;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *Run;
    QPushButton *Stop;
    QPushButton *Clear;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *Pause;
    QPushButton *Freeze;
    QGridLayout *ProcessSelect;
    QTextEdit *Cmd;
    QLabel *PID;
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
        actionSave_as = new QAction(DebugWindow);
        actionSave_as->setObjectName(QString::fromUtf8("actionSave_as"));
        actionSettings = new QAction(DebugWindow);
        actionSettings->setObjectName(QString::fromUtf8("actionSettings"));
        actionAbout = new QAction(DebugWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionGithub = new QAction(DebugWindow);
        actionGithub->setObjectName(QString::fromUtf8("actionGithub"));
        Childs_Windows = new QAction(DebugWindow);
        Childs_Windows->setObjectName(QString::fromUtf8("Childs_Windows"));
        Childs_Windows->setCheckable(true);
        actionNew = new QAction(DebugWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        centralwidget = new QWidget(DebugWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_4 = new QGridLayout(centralwidget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
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
        Run = new QPushButton(ProcessMenu);
        Run->setObjectName(QString::fromUtf8("Run"));

        horizontalLayout->addWidget(Run);

        Stop = new QPushButton(ProcessMenu);
        Stop->setObjectName(QString::fromUtf8("Stop"));

        horizontalLayout->addWidget(Stop);

        Clear = new QPushButton(ProcessMenu);
        Clear->setObjectName(QString::fromUtf8("Clear"));

        horizontalLayout->addWidget(Clear);


        horizontalLayout_3->addLayout(horizontalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        Pause = new QPushButton(ProcessMenu);
        Pause->setObjectName(QString::fromUtf8("Pause"));

        horizontalLayout_2->addWidget(Pause);

        Freeze = new QPushButton(ProcessMenu);
        Freeze->setObjectName(QString::fromUtf8("Freeze"));

        horizontalLayout_2->addWidget(Freeze);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        gridLayout_3->addLayout(horizontalLayout_3, 0, 0, 1, 1);


        gridLayout_4->addWidget(ProcessMenu, 0, 0, 1, 1);

        ProcessSelect = new QGridLayout();
        ProcessSelect->setObjectName(QString::fromUtf8("ProcessSelect"));
        Cmd = new QTextEdit(centralwidget);
        Cmd->setObjectName(QString::fromUtf8("Cmd"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Cmd->sizePolicy().hasHeightForWidth());
        Cmd->setSizePolicy(sizePolicy);
        Cmd->setMaximumSize(QSize(16777215, 30));

        ProcessSelect->addWidget(Cmd, 0, 0, 1, 1);

        PID = new QLabel(centralwidget);
        PID->setObjectName(QString::fromUtf8("PID"));

        ProcessSelect->addWidget(PID, 0, 1, 1, 1);


        gridLayout_4->addLayout(ProcessSelect, 1, 0, 1, 1);

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


        gridLayout_4->addWidget(Viewer, 2, 0, 1, 1);

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
        menu_File->addAction(actionNew);
        menu_File->addAction(actionSave_as);
        menu_File->addSeparator();
        menu_Tools->addAction(Childs_Windows);
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
        actionSave_as->setText(QCoreApplication::translate("DebugWindow", "&Save", nullptr));
        actionSettings->setText(QCoreApplication::translate("DebugWindow", "Settings", nullptr));
        actionAbout->setText(QCoreApplication::translate("DebugWindow", "&About", nullptr));
        actionGithub->setText(QCoreApplication::translate("DebugWindow", "Github", nullptr));
        Childs_Windows->setText(QCoreApplication::translate("DebugWindow", "Open childs in new windows", nullptr));
        actionNew->setText(QCoreApplication::translate("DebugWindow", "&New window", nullptr));
        Run->setText(QCoreApplication::translate("DebugWindow", "Rerun", nullptr));
        Stop->setText(QCoreApplication::translate("DebugWindow", "Stop", nullptr));
        Clear->setText(QCoreApplication::translate("DebugWindow", "Clear", nullptr));
        Pause->setText(QCoreApplication::translate("DebugWindow", "Pause", nullptr));
        Freeze->setText(QCoreApplication::translate("DebugWindow", "Freeze", nullptr));
        Cmd->setPlaceholderText(QCoreApplication::translate("DebugWindow", "Enter command", nullptr));
        PID->setText(QCoreApplication::translate("DebugWindow", "No PID", nullptr));
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

#endif // DEBUGGER_2D_3VZPBWN_H
