#include <QApplication>
#include <QPushButton>
#include <QTranslator>
#include <QByteArray>
#include <QTextCodec>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

 //   QTranslator translator;
 //   translator.load("hellotr_la.qm");
  //  app.installTranslator(&translator);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));

    QPushButton hello(QPushButton::tr("Hello"));
    hello.resize(100, 30);

    hello.show();
    return app.exec();
}

