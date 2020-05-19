#include <QtGui/QApplication>
#include "adwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ADWidget w;
    w.show();

    return a.exec();
}
