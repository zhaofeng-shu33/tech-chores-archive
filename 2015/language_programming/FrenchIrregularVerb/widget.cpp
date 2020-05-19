#include "widget.h"
#include <QTime>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QTimer>
#include <ctime>
#include <QCloseEvent>
#include "ui_widget.h"
using namespace std;
wordN* head=NULL;
bool isSend=0;
int total_length=0;
Widget::Widget(QWidget *parent):
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    loadTextFile();
    currentState=1;
    wordInput* mywordInput=new wordInput(word,cnt);
    mywordInput->show();
    connect(mywordInput->ui->pushButton_4,SIGNAL(clicked()),this,SLOT(import()));
}

void Widget::readData(QString str,int n){
    int i=0;
    QFile file(str);
    file.open(QIODevice::ReadOnly| QIODevice::Text);
    QTextStream in(&file);
    while(!in.atEnd()){
        word[n][i++]=in.readLine(75);
    }
    if(n==0)cnt=i;
    file.close();
}

void Widget::loadTextFile()
 {
     readData(":/ConjugaisonInfinitive.txt",0);
     readData(":/ConjugaisonPresent.txt",1);
     readData(":/ConjugaisonPasse.txt",2);
     readData(":/ConjugaisonFuturSimple.txt",3);
     readData(":/ConjugaisonImparfait.txt",4);

 }




Widget::~Widget()
{
    delete ui;
}

QString Widget::getText()
{


    while(!isSend){
        if(currentState==0){
            isSend=1;
        }
    QEventLoop eventloop;
    QTimer::singleShot(100, &eventloop, SLOT(quit()));
        eventloop.exec();
        if(isSend==1)
        eventloop.exit(0);
    }

     ui->lineEdit->selectAll();
     QString myString = ui->lineEdit->text();
      if(myString=="0"){
       QMessageBox(QMessageBox::Information,"Info","You cancel the change!").exec();
       ui->lineEdit->clear();
       return 0;
     }
     ui->lineEdit->clear();
     isSend=0;
     return myString;
 }
QString person(int n){
    if(n==0)
       return "je";
    if(n==1)
       return "tu";
    if(n==2)
       return "il/elle";
    if(n==3)
       return "nous";
    if(n==4)
       return "vous";
    if(n==5)
       return "ils/elles";
}
void Widget::show1(){

  wordN* q=head;
  ui->textBrowser->clear();
  ui->textBrowser_2->clear();
  for(int i=1;q!=NULL;i++){
      ui->textBrowser->append(QString("%1:    %2").arg(i).arg(q->wordN1));
      ui->textBrowser->append("Person  Presént  Passé  Futur Imparfait");
      for(int r=0;r<6;r++){
          ui->textBrowser->append(QString("%1 %2 %3 %4 %5").arg(person(r)).arg(q->wordN2[0][r]).arg(q->wordN2[1][r]).arg(q->wordN2[2][r]).arg(q->wordN2[3][r]));
      }
      q=q->next;
  }
  ui->textBrowser_2->append(QString("total word: %1").arg(total_length));
}



void Widget::closeEvent(QCloseEvent *event){
    currentState=0;

    QMessageBox::StandardButton button;
        button = QMessageBox::question(this, tr("Exit Program"),
            QString(tr("exit?")),
            QMessageBox::Yes | QMessageBox::No);

        if (button == QMessageBox::No) {
            event->ignore();
        }
        else if (button == QMessageBox::Yes) {
            event->accept();
        }



}

QString Widget::Assemble(bool ok,QString str){
    if(ok==0){
      ui->textBrowser_2->append(str);
      ui->textBrowser_2->append("(Input 0 to cancel)");
      QString str1=getText();
      ui->textBrowser->append(str1);
      ui->textBrowser_2->clear();
      return str1;
    }
    else{
    return "500";
    }
}

void Widget::on_pushButton_4_clicked()//revise button
{
    isSend=0;
    ui->textBrowser_2->clear();
    int n1=Assemble(isSend,"give the number of the word you'd like to revise:").toInt();
    int n2=Assemble(isSend,"give the tense: (Enter 1 for infinitif, 2 for présent, 3 for composé,4 for futur,5 for imparfait").toInt()-2;
    int n3;
    if(n2!=-1&&n2<400){
      n3=Assemble(isSend,"give the person: (Enter 1 for je, 2 for tu, 3 for il/elle, 4 for nous, 5 for vous, 6 for ils/elles").toInt()-1;
    }
    QString Str;
    Str=Assemble(isSend,"Give the new form of the word:");
    wordN* p=new wordN;
    p=head;
    if(n1==0||n1>total_length||head==NULL||n2==-2||n3==-1)
        return;
    for(int i=0;i<n1-1;i++){
       p=p->next;
    }
    if(n2==-1&&n1!=0)
      p->wordN1=Str;
    if(n2>=0&&n2<=3&&n3>=0&&n3<=5){
        p->wordN2[n2][n3]=Str;
    }
    show1();
}

void Widget::on_pushButton_3_clicked()
{//delete button
    isSend=0;
    ui->textBrowser_2->clear();
    int n=Assemble(isSend,"give the number of the word you'd like to delete:").toInt();
  //  QMessageBox(QMessageBox::Information,"Info",QString("%1").arg(n)).exec();

    wordN* p=head,*q=NULL;
         if(n==1){
           head=p->next;
           delete p;

         }
         if(n>1&&n<400){
         for(int i=0;i<n-2;i++)
             p=p->next;
         q=p;
         q->next=p->next->next;
         }
    if(n!=0&&n<400)
    total_length--;
    show1();
}


void Widget::on_pushButton_5_clicked()//test button
{
    wordN* p=head;
    cnt=0;
    while(p!=NULL){
           word[0][cnt]=p->wordN1;
           for(int j=0;j<6;j++){
           for(int i=0;i<4;i++)
            word[i+1][6*cnt+j]=p->wordN2[i][j];
        }
        cnt++;
        p=p->next;
    }
    this->hide();
    wordInput* mywordInput=new wordInput(word,cnt);
    connect(mywordInput->ui->pushButton_4,SIGNAL(clicked()),this,SLOT(show()));
    mywordInput->show();

}


void Widget::import(){
//import words from word source library
     this->show();
    wordN *q=NULL,*p=NULL;
    while(total_length<cnt){
        p=new wordN;
        p->wordN1=word[0][total_length];
        for(int r=0;r<6;r++){
            for(int j=0;j<4;j++)
        p->wordN2[j][r]=word[j+1][total_length*6+r];
        }
        total_length++;
        if(q==NULL)
           head=p;
        else
           q->next=p;

        q=p;
          q->next=NULL;
       }
  //  QMessageBox(QMessageBox::Information,"Info",QString("import successfully,total words: %1").arg(total_length)).exec();
    show1();
   }



void Widget::on_lineEdit_returnPressed()
{
  isSend=1;
}
