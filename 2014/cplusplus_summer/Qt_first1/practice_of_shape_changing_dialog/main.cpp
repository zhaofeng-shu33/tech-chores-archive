#include <QtGui/QApplication>
#include "dialog007.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog007 w;
    w.show();

    return a.exec();
}
