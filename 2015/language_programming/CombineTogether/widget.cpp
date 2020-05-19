#include "widget.h"
#include <QTime>
#include <QMessageBox>
#include <iostream>
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <QTextCodec>
#include <QTimer>
#include "mainwindow.h"
#include "ui_widget.h"
using namespace std;
word* head=NULL;
bool isSend=0;
int total_length=0;
QTime t;
QTextCodec * codec =QTextCodec::codecForName("GB18030");
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->verticalLayoutWidget->hide();
    connect(ui->lineEdit,SIGNAL(editingFinished()),this,SLOT(user_input()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(Create()));
}

Widget::~Widget()
{
    delete ui;
}
QString Widget::getText()
{


    while(!isSend){
     /*   QEventLoop eventloop;
        QTimer::singleShot(100, &eventloop, SLOT(quit()));
        eventloop.exec();*/
        t.start();
        while(t.elapsed()<1000)
        QCoreApplication::processEvents();
    }
   ui->lineEdit->selectAll();
     QString myString = ui->lineEdit->text();
  //   ui->textBrowser->append(myString);
   //  ui->textBrowser->append(codec->toUnicode("Ê¼¤Þ¤ë"));
     ui->lineEdit->clear();
//     cout<<"È¡¤ë"<<endl;
     isSend=0;
     return myString;
 }

void Widget::Create(){
    if(head==NULL){
  word* p=NULL,*q=NULL;
  ui->textBrowser_2->append("Add new word to the word list: ");
  QString tem;
  tem=getText();
  total_length=0;
  for(;tem!="0";){
    ui->textBrowser->append(tem);
    p=new word;
    p->word1=tem;
     ui->textBrowser_2->clear();
     ui->textBrowser_2->append("give the meaning of the word you have added: ");
    p->meaning=getText();
    ui->textBrowser->append(p->meaning);
    if(head==NULL)
       head=p;
    else
       q->next=p;

    q=p;
    q->next=NULL;
    total_length++;
    ui->textBrowser_2->clear();
    ui->textBrowser_2->append("Add new word to the word list: (press 0 to stop)");
    tem=getText();
  }
  ui->textBrowser->clear();
  }
  ui->pushButton->deleteLater();
  ui->textBrowser_2->setGeometry(30,140,71,151);cout<<"Change Size!";
  ui->verticalLayoutWidget->show();
}
void Widget::show1(){
  word* q=head;

  ui->textBrowser->clear();
  ui->textBrowser_2->clear();
 // ui->textBrowser->append("word list:");
  int i=1;
 //  if(head==NULL)
  //   ui->textBrowser->append("NONE");
  for(i=1;q!=NULL;i++){
      ui->textBrowser->append(q->meaning);
      ui->textBrowser->append("");
      ui->textBrowser->append("");
      ui->textBrowser->append("");
      ui->textBrowser->append("");
      ui->textBrowser->append("");
      //   ui->textBrowser->append(QString("%1: %2  %3").arg(i).arg(q->word1).arg(q->meaning));
      q=q->next;
  }
  total_length=i-1;
  cout<<"Total words: "<<i-1<<' '<<total_length<<endl;
  }



void Widget::on_pushButton_clicked()
{
    Create();
    show1();
}
void Widget::user_input(){
    if(ui->lineEdit->text().length()!=0)
    isSend=1;
}

void Widget::on_pushButton_2_clicked()//insert button
{
    ui->textBrowser_2->clear();
    word* q=new word;
    ui->textBrowser_2->append("Add new word to the word list: ");
    q->word1=getText();
    ui->textBrowser->append(q->word1);
        ui->textBrowser_2->append("give the meaning of the word you have added: ");
    q->meaning=getText();
    ui->textBrowser->append(q->meaning);
    if(head==NULL){
      cout<<"Èë¤ë";
      return;
    }

    q->next=head;
    head=q;
    total_length++;
    show1();
}

void Widget::on_pushButton_3_clicked()
{//delete button
    ui->textBrowser_2->clear();
    ui->textBrowser_2->append("give the number of the word you'd like to delete:");
    int n=getText().toInt();
    word* p=head,*q=NULL;
         if(n==1){
           head=p->next;
           delete p;

         }
         if(n>1){
         for(int i=0;i<n-2;i++)
             p=p->next;
         q=p;
         q->next=p->next->next;
         }
    total_length--;
    show1();
}



void Widget::on_pushButton_4_clicked()//revise button
{
    ui->textBrowser_2->clear();
    ui->textBrowser_2->append("give the number of the word you'd like to replace:");
    int n=getText().toInt();
    cout<<n<<endl;
    word* p=head,*q=new word;
    ui->textBrowser_2->append("Add new word to the word list: ");
    q->word1=getText();
    ui->textBrowser->append(q->word1);
    ui->textBrowser_2->clear();
    ui->textBrowser_2->append("give the meaning of the word you have added: ");
    q->meaning=getText();
    ui->textBrowser->append(q->meaning);

    if(n==0||n>total_length||head==NULL)
        return;
    if(n==1){
        q->next=head->next;
        head=q;
        delete p;
         }
    else{
         for(int i=0;i<n-2;i++)
             p=p->next;
         word* q1=p->next;
         q->next=p->next->next;
         p->next=q;
         delete q1;

    }
    show1();

}



void Widget::on_pushButton_5_clicked()//test button
{
    MainWindow* w2=new MainWindow;
    w2->show();
}

void Widget::on_pushButton_6_clicked()//export button
{
    QFile outputFile1("../CombineTogether/words1.txt");
    QFile outputFile2("../CombineTogether/words.txt");
    QTextStream out1(&outputFile1);
    QTextStream out2(&outputFile2);

    outputFile1.open(QFile::Append|QIODevice::Text);
    outputFile2.open(QFile::Append|QIODevice::Text);
    word* q=head;

    while(q!=NULL){
        out1<<q->word1<<flush<<endl;
        out2<<q->meaning<<flush<<endl;
        q=q->next;
    }
    outputFile1.close();
    outputFile2.close();
    QMessageBox(QMessageBox::Information,"Info","export successfully").exec();

}

void Widget::on_pushButton_7_clicked()//import words from word source library
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));

    QFile inputFile1("../CombineTogether/Conjugaison.txt");
    QFile inputFile2("../CombineTogether/words.txt");//translation
    QTextStream in1(&inputFile1);
    QTextStream in2(&inputFile2);

    inputFile1.open(QFile::ReadOnly|QIODevice::Text);
    inputFile2.open(QFile::ReadOnly|QIODevice::Text);
    word *q=NULL,*p=NULL;
    QString line1,line2;
    total_length=0;
    while(!inputFile1.atEnd()){
        line1=inputFile1.readLine(75);
        line2=inputFile2.readLine(75);
        total_length++;
        p=new word;
        p->word1=line1;
        p->meaning=line2;
        if(q==NULL)
           head=p;
        else
           q->next=p;

        q=p;
          q->next=NULL;
       }



    inputFile1.close();
    inputFile2.close();
    QMessageBox(QMessageBox::Information,"Info",QString("import successfully,total words: %1 %2").arg(total_length).arg(head->word1)).exec();
    show1();
}
