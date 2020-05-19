#include <QApplication>
#include <QTextCodec>
#include "scalabledialog.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    scalabledialog* dialog=new scalabledialog;
      dialog->show();
    return a.exec();
}


