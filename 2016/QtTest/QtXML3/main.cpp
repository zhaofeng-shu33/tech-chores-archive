#include <QtGui/QApplication>
#include "dialog.h"
#include <QtXml/QtXml>
#include <QTextStream>
#include <QFile>
#include <QIODevice>
#include <QTextBrowser>
QTextStream cout(stdout);
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.resize(QSize(200,200));
    QTextBrowser browser(&w);
    browser.append("Test");
    w.show();
    QFile file("D:/ComputerAided/archives/Text5-1.txt");
    if(!file.open(QFile::ReadOnly|QFile::Text)){cout<<"Error";}
    else{
        QByteArray line = file.readLine();
        cout<<line;
    }

    QDomDocument doc;
    if(!doc.setContent(&file)){cout<<"Error2";}
    else{
        QDomElement root=doc.documentElement();
        QString root_tag_name=root.tagName();
        cout<<endl<<root_tag_name<<endl;
        QDomNodeList nodeList=root.childNodes();
        int cnt=nodeList.count();
        for(int i=0;i<cnt;i++){
            QDomNode node=nodeList.at(i);
            QDomElement element=node.toElement();
            cout<<element.tagName()<<'*'<<endl;
            /*QString id=element.attribute("id");
            QDomNamedNodeMap map=element.attributes();
            browser.append(QString("%1").arg(map.item(0).nodeType()));
            for(int j=0;j<map.count();j++)
               cout<<endl<<' '<<map.item(j).nodeName()<<':'<<map.item(j).nodeValue();
            */QDomNodeList childList=element.childNodes();
            int child_cnt=childList.count();
            if(child_cnt==0)cout<<' '<<element.text();
            for(int j=0;j<child_cnt;j++){
                QDomElement childElement=childList.at(j).toElement();
                cout<<endl<<childElement.tagName()<<' '<<childElement.text();
            }
        }
/*        QDomElement another_person=doc.createElement("person");
        another_person.setAttribute("id","3");
        root.appendChild(another_person);
*/

    }
 //   cout<<QDir::currentPath();

    return a.exec();
}
