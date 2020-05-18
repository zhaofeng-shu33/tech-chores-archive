#include <QtGui/QApplication>
#include "qmmainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMMainWindow w;

    w.show();

    return a.exec();
}
