#ifndef BATTERYINDICATOR_H
#define BATTERYINDICATOR_H

#include <QDialog>

namespace Ui {
    class BatteryIndicator;
}

class BatteryIndicator : public QDialog
{
    Q_OBJECT

public:
    explicit BatteryIndicator(QWidget *parent = 0);
    ~BatteryIndicator();

private:
    Ui::BatteryIndicator *ui;
};

#endif // BATTERYINDICATOR_H
