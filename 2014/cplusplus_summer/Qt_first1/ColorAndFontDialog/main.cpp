#include <QtGui/QApplication>
#include "cafdialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CAFDialog w;
    w.show();

    return a.exec();
}
