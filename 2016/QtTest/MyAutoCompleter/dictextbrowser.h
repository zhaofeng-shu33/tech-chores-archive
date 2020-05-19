#ifndef DICTEXTBROWSER_H
#define DICTEXTBROWSER_H

#include <QTextBrowser>
#include <QDomDocument>
class QDomNode;
class DicTextBrowser : public QTextBrowser
{
    Q_OBJECT
public:
    explicit DicTextBrowser(QTextBrowser *parent = 0);
    QDomDocument doc;

signals:

public slots:
private:
    void appendNode(QDomNode n);

};

#endif // DICTEXTBROWSER_H
