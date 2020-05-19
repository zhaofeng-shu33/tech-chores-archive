#include <QtGui/QApplication>
#include "batteryindicator.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BatteryIndicator w;
    w.show();

    return a.exec();
}
