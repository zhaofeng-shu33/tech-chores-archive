#include "frenchtry.h"
#include "ui_frenchtry.h"
#include <cstdlib>
#include <ctime>

FrenchTry::FrenchTry(wordSource *parent) :
    wordSource(parent),
    ui(new Ui::FrenchTry)
{
    ui->setupUi(this);
    show1();
}

FrenchTry::~FrenchTry()
{
    delete ui;
}


void swap(int& a,int& b){
    int c=a;
    a=b;
    b=c;
}
void FrenchTry::renew(){   //核心算法

    for(int t=0;t<5;t++){
        ran[t]=generate_random_number();
          for(int j=0;j<t;j++){
            if(ran[j]==ran[t]){
               j=0;
               ran[t]=generate_random_number();
            }
        }
    //     ui->textEdit->append(QString("%1").arg(ran[t]));

    }
    for(int t=0;t<5;t++){
        ran2[t]=ran[t];
    }
    for(int j=0;j<5;j++){
        int r=rand()%(5-j);
        swap(ran2[j],ran2[j+r]);
    }
}


void FrenchTry::show1(){
    ui->textEdit->clear();
    ui->textEdit_2->clear();
    ui->textBrowser->clear();
    renew();
    for(int t=0;t<5;t++){
      ui->textEdit->append(QString("%1: %2").arg(t+1).arg(word[ran[t]]));
    }

    ui->textEdit->append(QString('\t'));
    for(int t=0;t<5;t++){
      ui->textEdit->append(QString("%1: %2").arg(char(t+97)).arg(word_2[ran2[t]]));

    }
    /*ui->textEdit_2->insertPlainText(QString("%1:%2%3").arg(0).arg(distribution_function(0)).arg(' '));
    for(int t=1;t<30;t++){
        ui->textEdit_2->insertPlainText(QString("%1:%2%3").arg(t).arg(distribution_function(t)-distribution_function(t-1)).arg(' '));
    }*/
}

void FrenchTry::on_checkButton_clicked()
{
     QString checkString = ui->lineEdit->text();
     ui->textBrowser->clear();
     ui->textBrowser->append("Your Answer Output:");
     for(int t=0;t<5;t++){
     ui->textBrowser->append(QString("%1->%2").arg(checkString[2*t]).arg(checkString[2*t+1]));
     }
     ui->textBrowser->append(QString('\n'));
     ui->lineEdit->clear();
     int r=0;
     for(int t=0;t<5;t++){//此处应根据回答结果修改单词权重
         if(ran2[checkString[2*t+1].toAscii()-97]==ran[t]){
           r++;
           if(word_weight[ran[t]]>4){
              word_weight[ran[t]]-=4;
              total-=4;
           }
         }
         else{
           word_weight[ran[t]]+=20;
           total+=20;
           ui->textBrowser->append(QString("%1->%2 is wrong!").arg(checkString[2*t]).arg(checkString[2*t+1]));
         }
     }

     ui->lcdNumber->display(r*1.0/5);
 }

void FrenchTry::on_pushButton_clicked()//show the right answer
{
  /*  for(int t=0;t<5;t++){
        ui->textEdit_2->append(QString("%1").arg(ran[t]));
    }
    for(int t=0;t<5;t++){
        ui->textEdit_2->append(QString("%1").arg(ran2[t]));
    }
*/ // ui->textEdit_2->clear();
    for(int t=0;t<5;t++){
        ui->textEdit_2->append(QString("%1: %2").arg(t+1).arg(word[ran[t]]));
        for(int j=0;j<5;j++){
            if(ran2[j]==ran[t]){
               ui->textEdit_2->append(QString("%1: %2").arg(char(j+97)).arg(word_2[ran2[j]]));
               break;}
        }
    }
}

void FrenchTry::on_renewButton_clicked()
{
    show1();
}
