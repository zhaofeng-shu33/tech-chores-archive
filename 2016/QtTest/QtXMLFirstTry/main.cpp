#include <QDebug>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QtXml>
QTextStream cout(stdout);
int main()
{
    QFile file("SimpleXML.xml");
    cout<<file.exists();
    if(!file.open(QFile::ReadOnly|QFile::Text)){cout<<"Error";}
    else{
        QByteArray line = file.readLine();
        cout<<line;
    }
    file.seek(0);
    QDomDocument doc;
    if(!doc.setContent(&file)){cout<<"Error2";}
    else{
        QDomElement root=doc.documentElement();
        QString root_tag_name=root.tagName();
        cout<<endl<<root_tag_name;
    }
 //   cout<<QDir::currentPath();
    return 0;
}

