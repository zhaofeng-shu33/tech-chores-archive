#include <QCoreApplication>
#include <QStringList>
#include <QProcessEnvironment>
#include "myobject.h"
#include "windows.h"
int main(int argc, char *argv[]){
    QCoreApplication a(argc, argv);
    QProcess myprocess;
  //  QProcessEnvironment en(QProcessEnvironment::systemEnvironment());
  //  en.insert("PATH",en.value("Path")+"D:/QtTest/consoleApp");
  //  myprocess.setProcessEnvironment(en);
    myObject obj;
    QObject::connect(&myprocess,SIGNAL(started()),&obj,SLOT(Out()));
    myprocess.start("D:/consoleApp.bat");
    //en=myprocess.processEnvironment();
    // myprocess.kill();
    QObject::connect(&myprocess,SIGNAL(finished(int)),&a,SLOT(quit()));
    //qDebug()<<myprocess.state()<<endl;
    return a.exec();
}
