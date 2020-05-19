#include <QtCore/QCoreApplication>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QDir>
#include <QTextCodec>
int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QCoreApplication a(argc, argv);
    for(int i=1;i<=9;i++){
        QString filename=QString("D:/QtTest/ODBC-build-desktop/NounEntryFormat00%1.txt").arg(i);
    QFile myFile(filename);
    if(myFile.exists()){
       filename.replace("txt","xml");
       qDebug()<<myFile.rename(filename);
    }
    }
    return 0;
}
