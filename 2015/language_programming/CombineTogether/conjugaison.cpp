#include "conjugaison.h"
#include "ui_conjugaison.h"
#include <cstdlib>
#include <QTextCodec>
#include <QMessageBox>
#include <ctime>
#include <string.h>
#include <iostream>
using namespace std;
Conjugaison::Conjugaison(wordSource2 *parent) :
    wordSource2(parent),
    ui(new Ui::Conjugaison)
{
    ui->setupUi(this);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));

    show1();
}

Conjugaison::~Conjugaison()
{
    delete ui;
}
void Conjugaison::renew(){   //核心算法

        rand1[0]=generate_random_number();
        rand2[0]=generate_random_number();
        for(int i=0;i<5;i++){
          rand1[2]=rand()%6;
          rand2[2]=rand()%6;//随机人称
          rand1[1]=rand()%2;
          rand2[1]=rand()%2;//随机时态
      }
        while(rand1[0]==rand2[0]){
            rand2[0]=generate_random_number();
        }
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
QString tense(int n){

    if(n==0){
        return "présent";
    }
    if(n==1){
     return "passé composé";
   }
}

void Conjugaison::show1(){
    ui->textEdit->clear();
    ui->textEdit_2->clear();

    renew();
      ui->textEdit->append(QString("%1").arg(tense(rand1[1])));
      ui->textEdit->append(QString("%1:%2").arg(person(rand1[2])).arg(word_2[rand1[0]]));
      ui->textEdit->append(QString("%1").arg(tense(rand2[1])));
      ui->textEdit->append(QString("%1:%2").arg(person(rand2[2])).arg(word_2[rand2[0]]));
}




void Conjugaison::on_pushButton_clicked() //check button
{
     ui->textEdit_2->clear();
     QString checkString1 = ui->lineEdit->text();
     QString checkString2=ui->lineEdit_2->text();
     cout<<rand1[0]*6+rand1[2]<<endl;
     cout<<rand2[0]*6+rand2[2]<<endl;
      if((rand1[1]==0&&checkString1==word[rand1[0]*6+rand1[2]])||(rand1[1]==1&&checkString1==wordp[rand1[0]*6+rand1[2]])){
        ui->textEdit_2->append("input 1 is right!");

       if(word_weight[rand1[0]]>4){
        word_weight[rand1[0]]-=4;
        total-=4;
       }
      }

     else{
        ui->textEdit_2->append("input 1 is wrong!");
        word_weight[rand1[0]]+=20;
        total+=20;
     }



     if((rand2[1]==0&&checkString2==word[rand2[0]*6+rand2[2]])||(rand2[1]==1&&checkString2==wordp[rand2[0]*6+rand2[2]])){
        ui->textEdit_2->append("input 2 is right!");
        if(word_weight[rand2[0]]>4){
         word_weight[rand2[0]]-=4;
         total-=4;
        }
      }
      else{
         ui->textEdit_2->append("input 2 is wrong!");
         word_weight[rand2[0]]+=20;
         total+=20;
        }
}

void Conjugaison::on_pushButton_2_clicked()//right answer button
{
    if(rand1[1]==0)
    ui->textEdit_2->append(QString("%1").arg(word[rand1[0]*6+rand1[2]]));
    if(rand1[1]==1)
    ui->textEdit_2->append(QString("%1").arg(wordp[rand1[0]*6+rand1[2]]));
    if(rand2[1]==0)
    ui->textEdit_2->append(QString("%1").arg(word[rand2[0]*6+rand2[2]]));
    if(rand2[1]==1)
    ui->textEdit_2->append(QString("%1").arg(wordp[rand2[0]*6+rand2[2]]));

}

void Conjugaison::on_pushButton_3_clicked() //renew button
{
    show1();
}

