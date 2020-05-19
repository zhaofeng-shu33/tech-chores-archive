#include<QDebug>
#include<QObject>
#include<QString>
#include<QList>
#include<QApplication>
class Person: public QObject{
public:
    explicit Person(QString name,QObject* parent=0): QObject(parent){
        QObject::setObjectName(name);
        qDebug()<<QString("Constructing Person: %1").arg(QObject::objectName())<<endl;
        }
    virtual ~Person(){
        qDebug()<<QString("Destroying Person: %1").arg(QObject::objectName())<<endl;
    }
};
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QObject myObject;
    Person* myPerson=new Person("Denny",&myObject);
    Person* yourPerson=new Person("FreeWind",&myObject);
    myObject.dumpObjectTree();
    return app.exec();
}
