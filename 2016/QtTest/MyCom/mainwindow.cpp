#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->closeMyComBtn->setEnabled(false);
    ui->sendMsgBtn->setEnabled(false);
    ui->selectSerialPortBtn->setEnabled(false);
    ui->HexBtn->setChecked(true);

    myMessageWindow = new MessageWindow(this);
    myMessageWindow->setGeometry(120,60,250,200);
    connect(ui->AsciiBtn,SIGNAL(clicked()),this,SLOT(setTextMode()));
    connect(ui->HexBtn,SIGNAL(clicked()),this,SLOT(setTextMode()));
    qDebug("Hello");
}
void MainWindow::setTextMode(){
    if(ui->AsciiBtn->isChecked())
        AsciiMode=true;
    else
        AsciiMode=false;
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::readMyCom(){

    QByteArray byteArray=myCom->readAll();
    qDebug(byteArray.toHex());
    if(byteArray.length()==4){
    QString curText=ui->sendMsgLineEdit->text();
    switch(byteArray[2])//判断第三个数码值
    {
    case 0x0c:curText=QString("%1%2").arg(curText).arg(1);break;//1 显示相应的按键值
    case 0x18:curText=QString("%1%2").arg(curText).arg(2);break;//2
    case 0x5e:curText=QString("%1%2").arg(curText).arg(3);break;//3
    case 0x08:curText=QString("%1%2").arg(curText).arg(4);break;//4
    case 0x1c:curText=QString("%1%2").arg(curText).arg(5);break;//5
    case 0x5a:curText=QString("%1%2").arg(curText).arg(6);break;//6
    case 0x42:curText=QString("%1%2").arg(curText).arg(7);break;//7
    case 0x52:curText=QString("%1%2").arg(curText).arg(8);break;//8
    case 0x4a:curText=QString("%1%2").arg(curText).arg(9);break;//9
    case 0x16:curText=QString("%1%2").arg(curText).arg(0);break;//0
    default:break;
    }
    ui->sendMsgLineEdit->setText(curText);
    if(!AsciiMode)byteArray=byteArray.toHex();
    qDebug(byteArray+' ');
    }
    else qDebug("Error!");

 }

void MainWindow::on_openMyComBtn_clicked(QString comName)
{
    struct PortSettings myComSetting = {BAUD9600,DATA_8,PAR_NONE,STOP_1,FLOW_OFF,
    500};
    myCom = new Win_QextSerialPort(comName,myComSetting,QextSerialBase::EventDriven);
    myCom->open(QIODevice::ReadWrite);
    connect(myCom,SIGNAL(readyRead()),this,SLOT(readMyCom()));
    ui->openMyComBtn->setDisabled(true);
    ui->closeMyComBtn->setEnabled(true);
    ui->sendMsgBtn->setEnabled(true);
    ui->selectSerialPortBtn->setEnabled(true);
}

void MainWindow::on_closeMyComBtn_clicked()
{
    myCom->close();
    ui->openMyComBtn->setEnabled(true);
    ui->sendMsgBtn->setEnabled(false);
    ui->closeMyComBtn->setEnabled(false);
    ui->selectSerialPortBtn->setEnabled(false);
}

void MainWindow::on_sendMsgBtn_clicked()
{
    myCom->write(ui->sendMsgLineEdit->text().toAscii());
}


void MainWindow::on_selectSerialPortBtn_currentIndexChanged(const QString & text)
{
   myCom->close();
   on_openMyComBtn_clicked(text);
}


void MainWindow::on_sendMsgLineEdit_returnPressed()
{
    on_sendMsgBtn_clicked();
}
