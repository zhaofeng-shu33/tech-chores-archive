#include <QtGui/QApplication>
#include "mbdialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MBDialog w;
    w.show();

    return a.exec();
}
