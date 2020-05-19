#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    QString str1 = ui->lineEdit1->text();
    QString str2 = ui->lineEdit2->text();
    bool b = false;
    double d1 = str1.toDouble(&b);
    if (b) {
        double d2 = str2.toDouble(&b);
        if (b) {
            ui->lcdNumber->display(d1 + d2);
            return;
        }
    }
    ui->lcdNumber->display("Error");
}

void MainWindow::on_lineEdit1_textChanged(QString str)
{
    //this->on_pushButton_clicked();
}

void MainWindow::on_lineEdit2_textChanged(QString )
{
    //this->on_pushButton_clicked();
}

void MainWindow::on_lineEdit1_editingFinished()
{
    this->on_pushButton_clicked();
}

void MainWindow::on_lineEdit2_editingFinished()
{
    this->on_pushButton_clicked();
}
