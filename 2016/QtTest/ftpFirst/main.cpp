#include <QtCore/QCoreApplication>
#include <QDir>
#include "ftpget.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cout<<a.libraryPaths().size()<<' '<<a.libraryPaths()[0].toStdString()<<endl;
    cout<<QDir::currentPath().toStdString()<<endl;
    FtpGet getter;
     if(!getter.getFile(QUrl("ftp://ftp.cis.upenn.edu/dist/gradsim.tar.Z")))return -1;
    QObject::connect(&getter,SIGNAL(done()),&a,SLOT(quit()));

    return a.exec();
}
