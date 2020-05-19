#ifndef MYOBJECT_H
#define MYOBJECT_H
#include <QProcess>
#include <QObject>
#include <QDebug>

class myObject : public QObject
{
    Q_OBJECT
public:
    explicit myObject(QObject *parent = 0);

signals:

public slots:
    void Out();
    void Out2();


};

#endif // MYOBJECT_H
