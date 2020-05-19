#ifndef POPUPWORD_H
#define POPUPWORD_H

#include <QMainWindow>
#include "ui_Popupword.h"

class QStringListModel;
class QListView;
class QUndoView;
class QUndoStack;

class PopupWord : public QMainWindow
{
    Q_OBJECT

public:
    PopupWord(QWidget *parent = 0);
    ~PopupWord();

protected:
    void initModel(void);
    void createActions(void);
    void createMenus(void);
    void createToolBar(void);

private slots:
    void insertString(void);

private:
    Ui::PopupWordClass ui;

    QDockWidget* mDockCommand;

    QStringListModel* mListModel;

    QUndoStack* mUndoStack;

    QListView* mListView;
    QUndoView* mUndoView;

    QAction* mExitAction;
    QAction* mUndoAction;
    QAction* mRedoAction;
    QAction* mInsertAction;
};

#endif // UNDOTEST_H
