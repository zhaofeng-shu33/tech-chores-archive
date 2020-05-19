#include <QtGui>
#include <QString>

#include<QDebug>
#include<QTextCodec>
#include<QFile>
#include<QVector>
#include <QDir>
#include <QtNetwork>
#include <QtGui/QApplication>
QTextStream cout(stdout);
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
   // cout.setCodec("ISO 8859-1");
    QUrl url("http://wordnetweb.princeton.edu/perl/webwn?s=woman");
    QEventLoop loop;
    QNetworkAccessManager manager;
    QNetworkReply* reply=manager.get(QNetworkRequest(url));
    QObject::connect(reply, SIGNAL(finished()),&loop,SLOT(quit()));
    loop.exec();
    QString code=reply->readAll();
    //cout<<code<<endl;
    QFile nounSource("D:/QtTest/consoleApp2/2.txt");
    nounSource.open(QFile::WriteOnly|QFile::Text);
    QTextStream out(&nounSource);
    out<<code;
    nounSource.close();
    QFile nounSource1("D:/QtTest/consoleApp2/2.txt");
    nounSource1.open(QFile::ReadOnly|QFile::Text);
    QTextStream out1(&nounSource1);
    while(!out1.atEnd()){
        QString str=out1.readLine();
        QRegExp rx("\\(n\\).+\\((.+)\\)");
        int pos;
        pos=rx.indexIn(str);
       if(pos!=-1)
          cout<<rx.cap(1)<<endl;
    }

/*    QFile nounAudioNumber("D:/QtTest/consoleApp2/nounAudioNumber.txt");
    nounAudioNumber.open(QFile::ReadOnly|QFile::Text);
    QTextStream out2(&nounAudioNumber);
    out2.setCodec("UTF-8");
    out1.setCodec("UTF-8");
    cout<<QDir::setCurrent("D:/QtTest/consoleApp2")<<'*';
    while(!out1.atEnd()){
       QString word=out1.readLine();
       word.replace(QString("ä"),"ae");
       word.replace(QString("ö"),"oe");
       word.replace(QString("ü"),"ue");
       word.replace(QString("ß"),"ss");
       QString pos=out2.readLine();
       QFile testFile(QString("D:/QtTest/GermanP/De-De-Langenscheidt-Vokabeln/muw%1.spx").arg(pos));


       cout<<word<<' '<<testFile.copy(QString("%1.spx").arg(word))<<pos<<endl<<flush;
    }*/
  // //  cout<<testFile.copy("3.txt");
    return 0;
}


