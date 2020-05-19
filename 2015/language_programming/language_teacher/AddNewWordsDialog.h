#ifndef __H_ADD_NEW_WORD_DIALOG__
#define __H_ADD_NEW_WORD_DIALOG__


#include "Document.h"
#include "ui_AddNewWordsDialog.h"
#include <QDialog>
#include <QString>


class QCloseEvent;


class AddNewWordsDialog : public QDialog, private Ui::AddNewWordDialog
{
    Q_OBJECT
public:
    AddNewWordsDialog(QWidget * parent = 0, Qt::WindowFlags f = 0);
    virtual ~AddNewWordsDialog();

protected:

    QString m_wordsFilePath;

    QAction* m_pDeleteSetAction;
    QAction* m_pDeleteWordAction;

    void resizeEvent(QResizeEvent * event);

    void connectSignals();
    void addWordsToPreview();
    void readWordsToPreview();

    void createActions();

protected slots:
    void onAddReadRadioBtnClicked();
    void onBrowseBtnClicked();
    void onAddBtnClicked();
    void onAddSetBtnClicked();
    void onSaveBtnClicked();
    void onAutosavingCheckBoxStateChanged(int state);

    void showContextMenu(const QPoint &);
    void onDeleteSet();
    void onDeleteWord();
    void reject();
};


#endif // __H_ADD_NEW_WORD_DIALOG__
