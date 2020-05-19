#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent, Complex c0) :
    QDialog(parent),
    ui(new Ui::Dialog), c(c0)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{
    c = Complex(ui->lineEdit1->text().toDouble(), ui->lineEdit2->text().toDouble());
}

void Dialog::on_buttonBox_rejected()
{

}
