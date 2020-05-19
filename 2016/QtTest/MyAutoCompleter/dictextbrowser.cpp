#include <QtXml>
#include <QFile>


#include "dictextbrowser.h"

DicTextBrowser::DicTextBrowser(QTextBrowser *parent) :
    QTextBrowser(parent)
{
    QFile file("D:\\QtTest\\ODBC-build-desktop\\NounEntryFormat011.xml");
     if (!file.open(QIODevice::ReadOnly))
         return ;
     if (!doc.setContent(&file)) {
         file.close();
         return ;
     }
     file.close();

    QDomElement docElem=doc.documentElement();
    QDomNode n=docElem.firstChild();
    appendNode(n);
}
void DicTextBrowser::appendNode(QDomNode n){
    if(n.isNull())return;
    if(n.isElement())
         append(QString("ElementName: %1").arg(n.nodeName()));

        if(n.isText())
           append(n.toText().data());
        else if(!n.isNull()){
            appendNode(n.firstChild());
        }

        if(!n.isNull())appendNode(n.nextSibling());


 /*   if(!n.nextSibling().isNull()){
       n=n.nextSibling();
       appendNode(n);
    }*/
}
