#include <QtCore/QCoreApplication>
#include <QTextStream>
#include<QObject>
#include<QString>
#include<QList>
#include<QDir>
#include<QFile>
QTextStream cout(stdout);
class Person: public QObject{
public:
    explicit Person(QString name,QObject* parent=0): QObject(parent){
        QObject::setObjectName(name);
        cout<<QString("Constructing Person: %1").arg(QObject::objectName())<<endl;
        }
    virtual ~Person(){
        cout<<QString("Destroying Person: %1").arg(QObject::objectName())<<endl;
    }
};
int main(int argc, char *argv[])
{
     QCoreApplication a(argc,argv);
     QDir dir;
     cout<<dir.currentPath()<<endl<<flush;//QString("%1/debug/t.txt").arg(dir.currentPath())
     QFile myFile("./r.txt");
     cout<<myFile.exists(QString("%1/r.txt").arg(QDir::currentPath()))<<endl;
     cout<<myFile.fileName()<<endl<<flush;
     cout<<myFile.rename("t.txt")<<endl<<flush;
     myFile.close();
    return a.exec();
}
