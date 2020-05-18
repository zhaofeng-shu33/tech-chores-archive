#include "dialog007.h"
#include "ui_dialog007.h"

Dialog007::Dialog007(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog007)
{
    ui->setupUi(this);
    ui->groupBox_3->hide();
    ui->groupBox_5->hide();

}

Dialog007::~Dialog007()
{
    delete ui;
}

void Dialog007::on_pushButton_clicked()
{
    if(ui->groupBox_3->isHidden())
       ui->groupBox_3->show();
    else
       ui->groupBox_3->hide();

    if(ui->groupBox_5->isHidden())
       ui->groupBox_5->show();
    else
       ui->groupBox_5->hide();



}

void Dialog007::on_buttonBox_accepted()
{
}
