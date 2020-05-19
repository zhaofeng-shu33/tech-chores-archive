#include "batteryindicator.h"
#include "ui_batteryindicator.h"

BatteryIndicator::BatteryIndicator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BatteryIndicator)
{
    ui->setupUi(this);
}

BatteryIndicator::~BatteryIndicator()
{
    delete ui;
}
