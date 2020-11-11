#include "creatorDialog/dialog.h"
#include "debugWindow/window.h"
#include "debugWindow/actiontriggers.h"

#include <QAction>
#include <QCheckBox>
#include <QWidgetAction>
#include <QFileDialog>
#include <QMenuBar>

DebugWindow::DebugWindow() : QMainWindow()
{

    setWindowTitle(tr("Syscall debugger"));

    QMenu *menu = menuBar()->addMenu(tr("&File"));

    QAction *act = new QAction(tr("New"), this);
    menu->addAction(act);
    connect(act, &QAction::triggered, this, &CreatorDialog::CreatorDialog);



    act = new QAction(tr("&Save As..."), this);
    menu->addAction(act);
    connect(act, &QAction::triggered, this, &ActionTriggers::saveFile);

    menu->addSeparator();

    act = new QAction(tr("E&xit"), this);
    menu->addAction(act);
    connect(act, &QAction::triggered, this, &QWidget::close);

    QMenu *toolMenu = menuBar()->addMenu(tr("&Tools"));

    QAction *addAct = new QAction(tr("&Add Entry..."), this);
    toolMenu->addAction(addAct);
    connect(addAct, &QAction::triggered,
            addressWidget, &AddressWidget::showAddEntryDialog);

    editAct = new QAction(tr("Open childs in a new window"), this);
    editAct->setCheckable(true);
    toolMenu->addAction(editAct);

    toolMenu->addSeparator();

    removeAct = new QAction(tr("&Remove Entry"), this);
    removeAct->setEnabled(false);
    toolMenu->addAction(removeAct);
    connect(removeAct, &QAction::triggered, addressWidget, &AddressWidget::removeEntry);

    connect(addressWidget, &AddressWidget::selectionChanged,
        this, &DebugWindow::updateActions);
}
//! [1b]

//! [2]
void DebugWindow::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    if (!fileName.isEmpty())
        addressWidget->readFromFile(fileName);
}
//! [2]

//! [3]
void DebugWindow::saveFile()
{
    QString fileName = QFileDialog::getSaveFileName(this);
    if (!fileName.isEmpty())
        addressWidget->writeToFile(fileName);
}
//! [3]

//! [4]
void DebugWindow::updateActions(const QItemSelection &selection)
{
    QModelIndexList indexes = selection.indexes();

    if (!indexes.isEmpty()) {
        removeAct->setEnabled(true);
        editAct->setEnabled(true);
    } else {
        removeAct->setEnabled(false);
        editAct->setEnabled(false);
    }
}
//! [4]
