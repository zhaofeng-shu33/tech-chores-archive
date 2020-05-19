#ifndef DICTIONARYWIDGET_H
#define DICTIONARYWIDGET_H

#include <QWidget>
class QStringListModel;
class QUndoStack;
namespace Ui {
    class dictionarywidget;
}

class dictionarywidget : public QWidget
{
    Q_OBJECT

public:
    explicit dictionarywidget(QWidget *parent = 0);
    ~dictionarywidget();
private slots:
    void setData();
private:
    Ui::dictionarywidget *ui;
    QStringListModel* ListModel;
    QUndoStack* mUndoStack;
    QAction* mUndoAction;
    QAction* mRedoAction;
};

#endif // DICTIONARYWIDGET_H
