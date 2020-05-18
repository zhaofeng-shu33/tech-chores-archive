#include "mainwindow008.h"
#include "ui_mainwindow008.h"
#include "dialog008.h"
MainWindow008::MainWindow008(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow008)
{
    ui->setupUi(this);
    }

MainWindow008::~MainWindow008()
{
    delete ui;
}
void MainWindow008::on_pushButton1_clicked(){
    Dialog008 my_dialog1(this,n1);
    my_dialog1.exec();
    n1=my_dialog1.d; //?
    ui->label_1->setText(n1.display());

}
void MainWindow008::on_pushButton2_clicked(){
    Dialog008 my_dialog2(this,n2);
    my_dialog2.exec();
    n2=my_dialog2.d;
    ui->label_2->setText(n2.display());

}
void MainWindow008::on_pushButton3_clicked(){
    Complex tem=n1+n2;
    ui->label_3->setText(tem.display());

}



