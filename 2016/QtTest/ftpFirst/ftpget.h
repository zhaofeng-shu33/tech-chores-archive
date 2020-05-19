#ifndef FTPGET_H
#define FTPGET_H
#include <QObject>
#include <QFtp>
#include <QFile>
#include <iostream>
#include <QUrl>
#include <QFileInfo>
using namespace std;
class FtpGet : public QObject
{
    Q_OBJECT
public:
    FtpGet(QObject *parent=0);
    bool getFile(QUrl url);

signals:
    void done();
private slots:
    void ftpDone(bool error);
    void ftpCommandStarted(int id);

private:
    QFtp ftp;
    QFile file;
    int connectedId;
    int loginId;
    int getId;
    int closeId;
};

#endif // FTPGET_H
