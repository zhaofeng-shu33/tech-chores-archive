#ifndef THREAD_H
#define THREAD_H
#include <QThread>
class Thread: public QThread
{
    Q_OBJECT
public:
    Thread();
    void setMessage(QString message);
    void stop();
protected:
    void run();
    void printMessage();
private:
    QString messageStr;
    volatile bool stopped;

};


#endif // THREAD_H
