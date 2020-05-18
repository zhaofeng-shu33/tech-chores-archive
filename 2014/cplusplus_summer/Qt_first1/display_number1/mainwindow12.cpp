#include "mainwindow12.h"
#include "ui_mainwindow12.h"

MainWindow12::MainWindow12(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow12)
{
    ui->setupUi(this);
    //connect(ui->lineEdit_1,SIGNAL(editingFinished()),this,SLOT(trigger_lineEdit_1()));
    //connect(ui->lineEdit_2,SIGNAL(editingFinished()),this,SLOT(trigger_lineEdit_2()));

}

MainWindow12::~MainWindow12()
{
    delete ui;
}
void MainWindow12::show_in_lcdNumber(){
   QString str1=ui->lineEdit_1->text();
   bool b=false;
   double d1=str1.toDouble(&b);
   QString str2=ui->lineEdit_2->text();
   if(b){ double d2=str2.toDouble(&b);
       if(b)
   ui->lcdNumber->display(d1+d2);
   }
   else
       ui->lcdNumber->display("Error");
   ui->textEdit->display("OK");
}



void MainWindow12::on_lineEdit_1_editingFinished()
{
    this->show_in_lcdNumber();

}

void MainWindow12::on_lineEdit_2_editingFinished()
{
    this->show_in_lcdNumber();
}
