#include <QMessageBox>
#include <QDebug>
#include "timercalculator.h"
#include "ui_timercalculator.h"

TimerCalculator::TimerCalculator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TimerCalculator)
{
    ui->setupUi(this);
    ui->comboBox->setCurrentIndex(1);
    ui->lcdNumberH->setMode(QLCDNumber::Hex);
    ui->lcdNumberL->setMode(QLCDNumber::Hex);

}

TimerCalculator::~TimerCalculator()
{
    delete ui;
}


void TimerCalculator::on_doubleSpinBox_editingFinished()
{
   int working_method=ui->comboBox->currentIndex();
   double user_time=ui->doubleSpinBox->value();
   ui->doubleSpinBox->setValue(0.00);
   switch (working_method){
   case 1:{
           if(user_time>=65.536){
               QMessageBox::warning(this,"Warning","the maximal timing limit is 65.536");
               return;
           }
           int initial_value=65536-int(user_time*1000);
           ui->lcdNumberH->display(initial_value/256);
           ui->lcdNumberL->display(initial_value%256);
           break;
       }
   case 2: {
           if(user_time>=0.256)
           {
            QMessageBox::warning(this,"Warning","the maximal timing limit is 65.536");
            return;
           }
            int initial_value=256-int(user_time*1000);
            ui->lcdNumberH->display(initial_value);
            ui->lcdNumberL->display(initial_value);
            break;
       }
   default:break;
   }
}
