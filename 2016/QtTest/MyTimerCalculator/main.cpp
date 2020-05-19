#include <QtGui/QApplication>
#include "timercalculator.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TimerCalculator w;
    w.show();

    return a.exec();
}
