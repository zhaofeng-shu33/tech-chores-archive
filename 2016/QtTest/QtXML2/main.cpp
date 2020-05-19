#include <QDebug>
#include <QFile>
#include <QDir>
#include <QTextStream>

#include <QtXmlPatterns>
#include <QStringList>
#include <QCoreApplication>
QTextStream cout(stdout);
int main(int argc, char *argv[])
{
    QCoreApplication a(argc,argv);
    QString fileName="D:/QtTest/QtXMLFirstTry-build-desktop/SimpleXML.txt";
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))cout<<"file not opened";
    else cout<<"opened"<<flush;
    QXmlQuery query;
    query.setFocus(&file);
    query.setQuery("//person[1]/*");
    QString res;
    query.evaluateTo(&res);
    cout<<"Result String "<<res<<endl;
    QXmlResultItems result;
    cout<<"isValid "<<query.isValid()<<endl;
    if(query.isValid()){
    query.evaluateTo(&result);
       QXmlItem item(result.next());
       cout<<"isNode "<<item.isNode()<<endl;
       if(item.isNode()){
           QXmlNodeModelIndex index=item.toNodeModelIndex();
           cout<<index.data()<<' '<<index.additionalData()<<endl<<flush;

       }
   }

    else cout<<"query failed"<<endl<<flush;
    return a.exec();

}



