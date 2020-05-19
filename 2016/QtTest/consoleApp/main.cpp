#include <QTextStream>
#include <QString>
#include <windows.h>
#include "hellowadd.h"
#include "QCoreApplication"
#include "QStringList"
#include <QLibrary>
#include <QDir>
QTextStream cout(stdout);
int main(int argc, char *argv[])
{
    QCoreApplication::addLibraryPath("./Header");
    QDir dir=QDir::current();
    cout<<dir.exists()<<endl;
    cout<<dir.absolutePath()<<endl;
    dir.cd("Search");
    cout<<dir.absolutePath()<<endl;
    dir.setSearchPaths("txt",QStringList("D:/QtTest/consoleApp-build-desktop/Search"));
    QFile file(dir.filePath("output1.txt"));
    if(file.open(QIODevice::ReadOnly))cout<<file.read(30)<<endl;
    else cout<<file.errorString()<<endl;
    //cout<<r<<endl;
    foreach(QString path,QCoreApplication::libraryPaths())
        cout<<path<<endl;
    cout<<"Bitte geben Sie eine Eingabe: "<<flush<<endl;
    HellowAdd *h=new HellowAdd();
    int n=h->Add(7,6);
   // int m=Sub(6,13);
    cout<<QLocale::system().name()<<n<<flush<<endl;
    system("pause");
    return 0;
}

