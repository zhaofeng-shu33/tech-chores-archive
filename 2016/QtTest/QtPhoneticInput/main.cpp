#include <QtGui>
#include <QtSql>
#include <phonon/MediaObject>
#include <QWidget>
#include "mydialog.h"
int main(int argc, char *argv[])
{
    QApplication app(argc,argv);

    /*    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
    QSqlQuery query(db);
    QString dsn=QString("DRIVER={Microsoft Access Driver (*.mdb)};FIL={MS Access};DBQ=D:/QtTest/ODBC/germanWord.mdb");
    db.setDatabaseName(dsn);
    if(!db.open()){
        qDebug()<<"Error: "<<db.lastError();
        return 1;
    }*/

    QDir dir("D:/QtTest/consoleApp2-build-desktop");
    dir.setFilter(QDir::Files|QDir::NoSymLinks);
    QFileInfoList list=dir.entryInfoList();
    int num=list.count();
    qDebug()<<'*'<<num<<'*'<<endl<<flush;
    for(int i=0;i<num;i++){
        if(list.at(i).fileName().contains("(s)")){
        QString str=list.at(i).absoluteFilePath();
        QFile file(str);
        file.rename(str.replace("\W_","\V_"));
        qDebug()<<'*'<<file.rename(str.replace("/W_","/V_"))<<'*'<<str<<endl<<flush;
        }
    }
    Phonon::MediaObject *music =
             Phonon::createPlayer(Phonon::MusicCategory,
                                  Phonon::MediaSource("D:/QtTest/ODBC/phonetic/W_Wagge(s).mp3"));
    music->play();
    MyDialog my_dialog;
    return app.exec();

    }
