#include<QApplication>
#include"ui_wordInputAndCheck.h"
#include <QDialog>
#include<QByteArray>
#include<QFile>
#include<QTextCodec>
 #include <QLatin1String>
int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    Ui::ForeignLanguage ui;
    QDialog* dialog=new QDialog();
    ui.setupUi(dialog);
    ui.textBrowser_3->append("ÄãºÃ");
  /*  QByteArray ba("Hello");
    QFile file("out.txt");
    file.open(QIODevice::Text);
    QTextStream out(&file);
    out<<"present";*/
    ui.textBrowser_3->append("pres¨¦nt");

    dialog->show();

    //QStackedWidget
    return a.exec();
}

