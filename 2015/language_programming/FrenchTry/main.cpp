#include <QtGui/QApplication>
#include "frenchtry.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FrenchTry w;
    w.show();
    return a.exec();

}
