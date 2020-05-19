#include <QApplication>
#include <QTextCodec>
#include <QDialog>
#include "ui_scalabledialog.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    Ui::ScalableDialog ui;
    QDialog* dialog=new QDialog;
    ui.setupUi(dialog);
    dialog->show();
    return a.exec();
}


