#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include <QDialog>
#include <QStringListModel>
#include <QListView>
#include <QDialogButtonBox>

class Widget : public QDialog
{
    Q_OBJECT

public:
    Widget(QStringList words,QDialog *parent = 0);
   // void SetValue(int);
    ~Widget();
private:
    QStringListModel *model;
    QListView *listView;
    QDialogButtonBox *buttonBox;
private slots:
    void insert();
    void del();

};

#endif // WIDGET_H
