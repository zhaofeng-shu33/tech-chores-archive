#include "dialog008.h"
#include "ui_dialog008.h"

Dialog008::Dialog008(QWidget *parent,Complex n) :
    QDialog(parent),
    d(n),
    ui(new Ui::Dialog008)
{
    ui->setupUi(this);
}

Dialog008::~Dialog008()
{
    delete ui;
}
void Dialog008::on_buttonBox_accepted(){
    d=Complex(ui->lineEdit1->text().toDouble(),ui->lineEdit2->text().toDouble());
}
void Dialog008::on_buttonBox_rejected(){}
