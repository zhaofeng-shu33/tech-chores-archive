#include "adwidget.h"
#include "ui_adwidget.h"
#include <QDebug>
ADWidget::ADWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ADWidget)
{
    ui->setupUi(this);
    ui->pushButton->setText(QString::fromUtf8("打开串口"));
}

ADWidget::~ADWidget()
{
    delete ui;
}

void ADWidget::on_pushButton_clicked()
{
    if(ui->pushButton->isChecked()){
        ui->pushButton->setText(QString::fromUtf8("关闭串口"));
        struct PortSettings myComSetting = {BAUD1200,DATA_8,PAR_NONE,STOP_1,FLOW_OFF,
        500};
        myCom = new Win_QextSerialPort("com3",myComSetting,QextSerialBase::EventDriven);
        myCom->open(QIODevice::ReadWrite);
        connect(myCom,SIGNAL(readyRead()),this,SLOT(readMyCom()));
    }
    else {
        myCom->close();
        ui->pushButton->setText(QString::fromUtf8("打开串口"));
        //采用非实时计算的方法。当关闭串口时进行计算。
        QString dat=ui->textBrowser->toPlainText();
        QStringList lst=dat.split(" ");
        qDebug()<<"Length: "<<lst.length();
        for(int i=0;i<lst.length();i++){
            qDebug()<<"data "<<i<<" "<<lst[i];
            if(lst[i]<"10"){ok=true;previousData=i;}
            if(ok&&lst[i]>"30"){ok=false;qDebug()<<i-previousData;}
        }

    }

}
void ADWidget::readMyCom(){
    QByteArray byteArray=myCom->readAll();
    byteArray=byteArray.toHex();

   // if(byteArray.length()==1){
   // if(dat<"10"){myTime.restart();ok=true;}
   // if(ok&&dat>"30"){qDebug()<<myTime.elapsed();ok=false;}
    ui->textBrowser->textCursor().insertText(QString("%1 ").arg(QString::fromLocal8Bit(byteArray.data())));
    // ui->lcdNumber->display(byteArray.toInt(&ok,16));
    // }
  // qDebug()<<byteArray;//<<' '<<' '<<int(byteArray)<<ui->lcdNumber->intValue();
}
