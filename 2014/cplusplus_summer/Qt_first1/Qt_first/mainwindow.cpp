#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString str=ui->lineEdit_1->text();
    double b1=str.toDouble();
    ui->lcdNumber->display(b1);

}

void MainWindow::on_add_pressed()
{
   QString str1=ui->lineEdit_1->text();
   double b1=str1.toDouble();
   QString str2=ui->lineEdit_2->text();
   double b2=str2.toDouble();
   ui->lcdNumber->display(b1+b2);
}

void MainWindow::on_pushButton_2_clicked()
{

}
