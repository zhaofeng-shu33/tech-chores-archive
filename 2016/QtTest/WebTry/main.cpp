#include <QWebFrame>
#include <QWebView>
#include <QApplication>
#include <QXmlQuery>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWebView webview;
    QString out;
    QXmlQuery query(QXmlQuery::XSLT20);
    query.setFocus(QUrl("D:\\ProjectNote\\GermaData\\DicTest\\Wort\\1.xml"));
    query.setQuery(QUrl("D:\\ProjectNote\\GermaData\\DicTest\\Wort\\NounRenderTemplate.xslt"));
    query.evaluateTo(&out);
    webview.setHtml(out);
    //view.load(QUrl("D:\\QtTest\\AddressBook-build-desktop\\example.html"));
    webview.show();

    return a.exec();
}
