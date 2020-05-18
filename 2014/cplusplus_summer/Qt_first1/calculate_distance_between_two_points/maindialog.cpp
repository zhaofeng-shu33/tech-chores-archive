#include "maindialog.h"
#include "ui_maindialog.h"
#include "Point2D.h"
MainDialog::MainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainDialog)
{   editState=0;
    ui->setupUi(this);
    ui->pushButton->setEnabled(false);
    ui->label->setBuddy(ui->lineEdit);
    ui->label_2->setBuddy(ui->lineEdit_3);
    connect(ui->lineEdit,SIGNAL(textChanged(QString)),this,SLOT(try_enable_pushButton()));
    connect(ui->lineEdit_2,SIGNAL(textChanged(QString)),this,SLOT(try_enable_pushButton()));
    connect(ui->lineEdit_3,SIGNAL(textChanged(QString)),this,SLOT(try_enable_pushButton()));
    connect(ui->lineEdit_4,SIGNAL(textChanged(QString)),this,SLOT(try_enable_pushButton()));


}

MainDialog::~MainDialog()
{
    delete ui;
}

void MainDialog::on_pushButton_clicked(){
   ui->label_5->setText(QString("%1").arg(distance));
}
void MainDialog::try_enable_pushButton(){
    bool b1,b2,b3,b4;
           double tem1=ui->lineEdit->text().toDouble(&b1);
           double tem2=ui->lineEdit_2->text().toDouble(&b2);
           double tem3=ui->lineEdit_3->text().toDouble(&b3);
           double tem4=ui->lineEdit_4->text().toDouble(&b4);
           int b5=(int)(b1+b2+b3+b4);
           if(b5==4){
           Point2D P1(tem1,tem2);
           Point2D P2(tem3,tem4);
           distance=distance_1(P1,P2);
           ui->pushButton->setEnabled(true);
           }
           else
           ui->pushButton->setEnabled(false);
}
