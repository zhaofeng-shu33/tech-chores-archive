#include "myobject.h"

myObject::myObject(QObject *parent) :
    QObject(parent)
{
    qDebug()<<"Created";
}
void myObject::Out(){
    qDebug()<<"started";
}
void myObject::Out2(){
    qDebug()<<"state changed";
}
