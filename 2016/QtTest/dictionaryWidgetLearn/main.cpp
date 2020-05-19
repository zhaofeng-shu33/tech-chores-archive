#include <QtGui/QApplication>
#include "dictionarywidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    dictionarywidget w;
    w.show();

    return a.exec();
}
