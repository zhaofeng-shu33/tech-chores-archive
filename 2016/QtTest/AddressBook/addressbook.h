#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <QWidget>
#include "zlib-1.2.8/zlib.h"
#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QStringList>
#include <QString>
#include <QMap>
#include <QPair>
#include <windows.h>
#include <QTextStream>
#include <QBuffer>
namespace Ui {
    class AddressBook;
}

class AddressBook : public QWidget
{
    Q_OBJECT

public:
    explicit AddressBook(QWidget *parent = 0);
    ~AddressBook();
private:
    Ui::AddressBook *ui;
    int ToInteger(QByteArray array);
    qint64 ToLongInteger(QByteArray array);
private slots:
    void LoadStart();
    void LoadProgress(int);
    //void LoadFinish();

};

#endif // ADDRESSBOOK_H
