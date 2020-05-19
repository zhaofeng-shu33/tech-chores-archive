#include "widget.h"
#include "ui_widget.h"
#include <QtMultimedia/QAudioFormat>
#include <QtMultimedia/QAudioOutput>
#include <QtMultimedia/QAudioDeviceInfo>
#include <QFile>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPixmap>
#include <QRegExp>
QString fractionCheck[2];
bool CheckFractionFormat(QString str){ //for 1(1) the right answer is (1)\(g(\epsilon)=\frac{4\pi V(2m)^\frac{3}{2}}{h^3}\)
    QRegExp rexp("\\\\frac\\{(.+)\\}\\{(.+)\\}");
    int pos=rexp.indexIn(str);
    fractionCheck[0]=rexp.cap(1);
    fractionCheck[1]=rexp.cap(2);
    if(pos>-1)
        return true;
    else
        return false;

}
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QGraphicsScene* scene=new QGraphicsScene;
    scene->addPixmap(QPixmap(":/Pro01.jpg"));
    QPixmap pixmap(":/Pro01E.jpg");
    QGraphicsItem* item=scene->addPixmap(pixmap);//get the pointer of the added item
    item->setPos(0,scene->height());
    ui->graphicsView->setScene(scene);
   // QString test="(1)\(g(";
    //(1)\(g(\epsilon)=\frac{4\pi V(2m)^\frac{3}{2}}{h^3}\)";
   // ui->textBrowser->append(QString("%1").arg(test.length()));
   }

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
  /*  QFile inputFile;     // class member
    QAudioOutput* audio; // class membe
    inputFile.setFileName("D:/QtTest/QtTest16/test.mp3");
    inputFile.open(QIODevice::ReadOnly);
     QAudioFormat format;
    // Set up the format, eg.
     format.setFrequency(8000);
     format.setChannels(1);
     format.setSampleSize(8);
     format.setCodec("audio/pcm");
     format.setByteOrder(QAudioFormat::LittleEndian);
     format.setSampleType(QAudioFormat::UnSignedInt);

     QAudioDeviceInfo info(QAudioDeviceInfo::defaultOutputDevice());
     if (!info.isFormatSupported(format)) {
         ui->textBrowser->append("Fail");
         return;
     }

     audio = new QAudioOutput(format, this);
     connect(audio,SIGNAL(stateChanged(QAudio::State)),SLOT(finishedPlaying(QAudio::State)));
     audio->start(&inputFile);
*/
}

void Widget::on_CheckButton_clicked()
{
   QString inputAnswer=ui->lineEdit->text();
   QRegExp rexp("(.+)=(.+)\\\\[)]");
   int pos=rexp.indexIn(inputAnswer);
   if(pos>-1){
   QString str1 = rexp.cap(1);
   QString str2 = rexp.cap(2);
   ui->textBrowser->append(inputAnswer);
   ui->textBrowser->append(str1);
   ui->textBrowser->append(str2);
   QRegExp rexp01("([(]\\d[)]).*\\\\[(]");
   //ui->textBrowser->append(QString("%1").arg(rexp01.isValid()));
   int pos1=rexp01.indexIn(str1);
   if(pos1>-1){
      QRegExp rexp02("(g[(]\\\\epsilon[)])");
           int pos2=rexp02.indexIn(str1);
      if(pos2>-1){
          QRegExp rexp10("\\\\frac\\{(.+)\\}\\{(.+)\\}");
          int pos3=rexp10.indexIn(str2);
          ui->textBrowser->append(QString("%1,%2").arg("fraction").arg(rexp01.isValid()));
          if(pos3>-1){
              QString str3=rexp10.cap(1);
              QString str4=rexp10.cap(2);
              ui->textBrowser->append(str3);
              ui->textBrowser->append(str4);
              QRegExp rexp04("((?:\\w)\\^3)");
              int pos4=rexp04.indexIn(str4);
              if(pos4>-1){
                  QRegExp rexp05(".*(\\\\pi).*");
                  QRegExp rexp06(".*(m).*");
                  QRegExp rexp07(".*(V).*");
                  int pos5=rexp05.indexIn(str3);
                  int pos6=rexp06.indexIn(str3);
                  int pos7=rexp07.indexIn(str3);
                  if(pos5>-1&&pos6>-1&&pos7>-1&&CheckFractionFormat(str3)){
                     QRegExp rexp08(".*[(]2\\s?m[)]\\^.*");
                     int pos8=rexp08.indexIn(str3);
                     QRegExp rexp09(".*m\\^.*");
                     int pos9=rexp09.indexIn(str3);
                     if((pos8>-1)&&(fractionCheck[0]=="3")&&(fractionCheck[1]=="2")&&(QRegExp(".*4.*").indexIn(str3)>-1)){
                         ui->textBrowser->append("Right Answer!");
                         return;
                     }
                     if((pos9>-1)&&(QRegExp(".*7.*").indexIn(str3)>-1)){
                         QRegExp r("[2]");
                          int ct = 0;
                          int p=r.indexIn(str3);
                          while (p>=0) {
                              ui->textEdit->append(QString("%1").arg(p));
                              p=r.indexIn(str3,p+1);
                              ++ct;
                          }
                          ui->textBrowser->append(str3);
                          ui->textBrowser->append(QString("%1").arg(ct));

                         if(ct==3)
                         ui->textBrowser->append("Right Answer");
                         else
                            ui->textBrowser->append("Please check your numerator carefully or simplify some constant terms to get the right answer");
                      }

                  } // ui->textBrowser->append(QString("%1,%2,%3,%4,%5").arg(rexp05.cap(1)).arg(rexp06.cap(1)).arg(rexp07.cap(1)).arg(fractionCheck[0]).arg(fractionCheck[1]));

                  else  ui->textBrowser->append("The term about pi or m or V or the fraction format of the exponential position is wrong");
              }
              else
                  ui->textBrowser->append("the term about the Plank constant is wrong");
          }
          else  ui->textBrowser->append("The format of the fraction after the equality is wrong");
      }
      else
          ui->textBrowser->append("The name of the distribution function before the equality is wrong");
  }
   else{
       ui->textBrowser->append("The format of the sub-number of the problem or the math input format before the equality is wrong");
   }

    }
   else{

       ui->textBrowser->append("The equality has wrong format");
   }

}
