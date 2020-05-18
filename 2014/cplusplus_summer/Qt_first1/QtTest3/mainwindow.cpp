#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"

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

void MainWindow::on_pushButton1_clicked()
{
    Dialog d(this, c1);
    d.exec();
    c1 = d.c;
    ui->label1->setText(c1.display());
}

void MainWindow::on_pushButton2_clicked()
{
    Dialog d(this, c2);
    d.exec();
    c2 = d.c;
    ui->label2->setText(c2.display());
}

void MainWindow::on_pushButton3_clicked()
{
    Complex c = c1 + c2;
    ui->label3->setText(c.display());
}
