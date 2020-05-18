#include "FindDialog.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FindDialog my;
    my.show();
    return a.exec();
}
