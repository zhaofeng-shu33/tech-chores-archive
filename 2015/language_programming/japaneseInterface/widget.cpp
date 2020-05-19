#include "widget.h"
#include <QTime>
#include <iostream>
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <QTextCodec>
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
    cout<<"こんにちは"<<endl;
    connect(ui->lineEdit,SIGNAL(editingFinished()),this,SLOT(user_input()));
    ui->textBrowser_2->append(codec->toUnicode("正"));
}

Widget::~Widget()
{
    delete ui;
}
QString Widget::getText()
{

    while(!isSend){
        t.start();
        while(t.elapsed()<1000)
        QCoreApplication::processEvents();
    }
   ui->lineEdit->selectAll();
     QString myString = ui->lineEdit->text();
  //   ui->textBrowser->append(myString);
   //  ui->textBrowser->append(codec->toUnicode("始まる"));
     ui->lineEdit->clear();
     cout<<"取る"<<endl;
     isSend=0;
     return myString;
 }

void Widget::Create(){
  word* p=NULL,*q=NULL;
  ui->textBrowser_2->append("Add new verb to the verb list: ");
  QString tem;
  tem=getText();
  for(;tem!="0";){
    ui->textBrowser->append(tem);
    p=new word;
    p->verb=tem;
     ui->textBrowser_2->clear();
     ui->textBrowser_2->append("give the first continuative form of the verb you have added: ");
    p->first_continuative_form=getText();
    ui->textBrowser->append(p->first_continuative_form);
    if(head==NULL)
       head=p;
    else
       q->next=p;

    q=p;
    q->next=NULL;
    ui->textBrowser_2->clear();
    ui->textBrowser_2->append("Add new verb to the verb list: (press 0 to stop)");
    tem=getText();
  }
  ui->textBrowser->clear();
  ui->pushButton->deleteLater();
  ui->textBrowser_2->setGeometry(30,140,71,151);
  ui->verticalLayoutWidget->show();
}
void Widget::show1(){
  word* q=head;

  QFile outputFile("wordExport.txt");
  QTextStream out(&outputFile);
  outputFile.open(QFile::WriteOnly|QFile::Truncate|QIODevice::Text);
  ui->textBrowser->clear();
  ui->textBrowser_2->clear();
  ui->textBrowser->append("word list:");
  int i=1;
  if(head==NULL)
     ui->textBrowser->append("NONE");
  for(i=1;q!=NULL;i++){
      out<<QString("%1: %2  %3").arg(i).arg(q->verb).arg(q->first_continuative_form)<<flush;
      out<<endl;
      ui->textBrowser->append(QString("%1: %2  %3").arg(i).arg(q->verb).arg(q->first_continuative_form));
      q=q->next;
  }
  total_length=i-1;
  cout<<"Total verbs: "<<i-1<<endl;
  outputFile.close();
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
    word* q=new word;
    ui->textBrowser_2->append("Add new verb to the verb list: ");
    q->verb=getText();
    ui->textBrowser->append(q->verb);
    ui->textBrowser_2->clear();
    ui->textBrowser_2->append("give the first continuative form of the verb you have added: ");
    q->first_continuative_form=getText();
    ui->textBrowser->append(q->first_continuative_form);
    if(head==NULL){
      cout<<"入る";
      return;
    }

    q->next=head;
    head=q;
    total_length++;
    show1();
}

void Widget::on_pushButton_3_clicked()
{//delete button
    ui->textBrowser_2->append("give the number of the word you'd like to delete:");
    int n=getText().toInt();
    word* p=head,*q=NULL;
         if(n==0||n>total_length||head==NULL)
           return;
         if(n==1){
           head=p->next;
           delete p;
         return;
         }
         for(int i=0;i<=n-2;i++)
             p=p->next;
         q=p;
         q->next=p->next->next;
    total_length--;
    show1();
}



void Widget::on_pushButton_4_clicked()//revise button
{
    ui->textBrowser_2->append("give the number of the word you'd like to replace:");
    int n=getText().toInt();
    cout<<n<<endl;
    word* p=head,*q=new word;
    ui->textBrowser_2->clear();
    ui->textBrowser_2->append("Add new verb to the verb list: ");
    q->verb=getText();
    ui->textBrowser->append(q->verb);
    ui->textBrowser_2->clear();
    ui->textBrowser_2->append("give the first continuative form of the verb you have added: ");
    q->first_continuative_form=getText();
    ui->textBrowser->append(q->first_continuative_form);

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

void Widget::my_export(){


}

