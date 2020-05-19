#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QTextStream>
#include <QUrl>
#include <phonon/VideoWidget>
#include <phonon/AudioDataOutput>
QUrl url("D:/QtTest/QtTest15/test.wmv");

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->textEdit->append("Test");
    QStringList list1;
  //  list1<<"love"<<"Liebe"<<"Amour";
    QFile input("D:/QtTest/QtTest15/test02.txt");
    input.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&input);
    while(!in.atEnd()){
       list1<<in.readAll().split(QRegExp("\\W+"));
    }
    int total1=list1.count();
    list1.sort();
    QStringList result;
    result=list1.filter(QRegExp("\\b([Tt]he)\\b"));
    list1.removeDuplicates();
    int total2=list1.count();
    for(int i=0;i<=total2-1;i++){
    ui->textEdit->append(list1[i]);
    //ui->textEdit->append("");
    }
    ui->textEdit->append(QString("%1").arg(result.count()));
    ui->textEdit->append(QString("%1").arg(total1));
    ui->textEdit->append(QString("%1").arg(total2));

    vwidget = new Phonon::VideoWidget(ui->widget);
    player =new Phonon::VideoPlayer(Phonon::VideoCategory,vwidget);

    QRegExp r("[2]");
     int ct = 0;
     QString st("1+2+2+2=4+2+2,2+1");
     int p=r.indexIn(st);
     while (p>=0) {
         ui->textEdit->append(QString("%1").arg(p));
         p=r.indexIn(st,p+1);
         ++ct;
     }
   /* QString str = "offsets: 1.23 .50 71.00 6.00";
      QRegExp rx("\\d*\\.\\d+");    // primitive floating point matching
      int count = 0;
      int pos = 0;
      while ((pos = rx.indexIn(str, pos)) != -1) {
          ++count;
          pos += rx.matchedLength();
      }*/
    ui->textEdit->append(QString("%1").arg(ct));



  /*  QFile output("D:/QtTest/QtTest15/test03.txt");
    output.open(QIODevice::WriteOnly);
    QDataStream out(&output);
    out<<list1;

    QRegExp rxlen("([a-z]+)");
     QRegExp rxlen("([A-Za-z_]*=[\\d+])");
    int pos=0;
    while(pos>-1) {
         pos=rxlen.indexIn("a=b,a=3,c=4",pos);
         QString str1 = rxlen.cap(1);
         ui->textEdit->append(str1);
         pos+=rxlen.matchedLength();
         //ui->textEdit->append(str3);


     }
   QString str4="a=b,a=100,a=5";
   str4.replace(QRegExp("a"),"c");
   ui->textEdit->append(str4);
     QRegExp rx("(\\w+)");
    QString str = "Offsets: 121 or not 14 99 231 7";
    QString list[10];
    int pos = 0,i=0;

    while ((pos = rx.indexIn(str, pos)) != -1) {
         list[i]=rx.cap(1);
         pos += rx.matchedLength();
         i++;
     }
   for(int j=0;j<i;j++)
       ui->textEdit->append(list[j]);*/
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    Phonon::MediaObject *music =
             Phonon::createPlayer(Phonon::MusicCategory,
                                  Phonon::MediaSource("D:/QtTest/QtTest15/1cour.wma"));
         music->play();
}

void Widget::on_pushButton_2_clicked()
{
    vwidget->resize(150,150);
    player->resize(150,150);
    player->play(url);
//    vwidget->setScaleMode(Phonon::VideoWidget::ScaleAndCrop);
//    vwidget->setAspectRatio(Phonon::VideoWidget::AspectRatio4_3);
    vwidget->show();
}

void Widget::on_pushButton_3_clicked()
{
    ui->textEdit->append(QString("%1").arg(player->totalTime()));

}
