#include "PopupWord.h"

#include <QListView>
#include <QDockWidget>
#include <QStringListModel>

#include <QUndoStack>
#include <QUndoView>

#include "InsertCommand.h"

PopupWord::PopupWord(QWidget *parent)
    : QMainWindow(parent)
    , mListModel(new QStringListModel())
    , mListView(new QListView())
    , mUndoStack(new QUndoStack())
    , mUndoView(new QUndoView(mUndoStack))
    , mDockCommand(new QDockWidget(tr("Command List"), this))
{
    ui.setupUi(this);

    initModel();

    mListView->setModel(mListModel);

    setCentralWidget(mListView);

    mDockCommand->setWidget(mUndoView);
    addDockWidget(Qt::LeftDockWidgetArea, mDockCommand);

    createActions();
    createMenus();
    createToolBar();
}

PopupWord::~PopupWord()
{

}

void PopupWord::initModel()
{
    QStringList aStrings;

    for (int i = 0; i < 100; ++i)
    {
        aStrings << "test string for undo/redo " + QString::number(i);
    }

    mListModel->setStringList(aStrings);
}

void PopupWord::createActions()
{
    mExitAction = new QAction(tr("Exit"), this);
    connect(mExitAction, SIGNAL(triggered()), this, SLOT(close()));

    mUndoAction = mUndoStack->createUndoAction(this, tr("Undo"));
    mUndoAction->setShortcuts(QKeySequence::Undo);
    mUndoAction->setIcon(QIcon(":/Resources/undo.png"));

    mRedoAction = mUndoStack->createRedoAction(this, tr("Redo"));
    mRedoAction->setShortcuts(QKeySequence::Redo);
    mRedoAction->setIcon(QIcon(":/Resources/redo.png"));

    mInsertAction = new QAction(tr("Insert"), this);
    mInsertAction->setIcon(QIcon(":/Resources/add.png"));
    connect(mInsertAction, SIGNAL(triggered()), this, SLOT(insertString()));
}

void PopupWord::createMenus()
{
    QMenu* aFileMenu = ui.menuBar->addMenu(tr("File"));
    aFileMenu->addAction(mExitAction);

    QMenu* aEditMenu = ui.menuBar->addMenu(tr("Edit"));
    aEditMenu->addAction(mUndoAction);
    aEditMenu->addAction(mRedoAction);

    QMenu* aItemMenu = ui.menuBar->addMenu(tr("Item"));
    aItemMenu->addAction(mInsertAction);
}

void PopupWord::createToolBar()
{
    ui.mainToolBar->addAction(mUndoAction);
    ui.mainToolBar->addAction(mRedoAction);
    ui.mainToolBar->addSeparator();
    ui.mainToolBar->addAction(mInsertAction);
}

void PopupWord::insertString()
{
    QModelIndex aIndex = mListView->currentIndex();

    mUndoStack->push(new InsertCommand(aIndex, mListModel));
}
