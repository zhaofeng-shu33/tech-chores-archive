#include <QtGui/QApplication>
#include "widget.h"
#include <QLabel>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w1;
    w1.show();
   // QLabel* label=new QLabel("Guten Tag!");
   // label->show();
   // MainWindow w2;
   // w2.show();

    return a.exec();
}
