#include "wordinput.h"
#include "ui_wordinput.h"
#include <cstdlib>
#include <QMessageBox>
#include <ctime>
#include <string.h>
#include <iostream>
using namespace std;
wordInput::wordInput(wordSource *parent) :
    wordSource(parent),
    ui(new Ui::wordInput)
{
    ui->setupUi(this);
    show1();
}

wordInput::~wordInput()
{
    delete ui;
}
void wordInput::renew(){   //ºËĞÄËã·¨

        rand1=generate_random_number();
        rand2=generate_random_number();


        while(rand1==rand2){
            cout<<rand1<<' '<<rand2<<endl;
            rand2=generate_random_number();
        }
}
void wordInput::show1(){
    ui->textEdit->clear();
    ui->textEdit_2->clear();

    renew();
      ui->textEdit->append(QString("%1:%2").arg(1).arg(word_2[rand1]));
      ui->textEdit->append(QString("%1:%2").arg(2).arg(word_2[rand2]));
}




void wordInput::on_pushButton_clicked() //check button
{
     ui->textEdit_2->clear();
     QString checkString1 = ui->lineEdit->text();
     QString checkString2=ui->lineEdit_2->text();

      if(checkString1==word[rand1]||(word[rand1].contains(checkString1+'/'))){
        ui->textEdit_2->append("input 1 is right!");

       if(word_weight[rand1]>4){
        word_weight[rand1]-=4;
        total-=4;
       }
      }

     else{
        ui->textEdit_2->append("input 1 is wrong!");
        word_weight[rand1]+=20;
        total+=20;
     }



     if(checkString2==word[rand2]||(word[rand2].contains(checkString2+'/'))){
        ui->textEdit_2->append("input 2 is right!");
        if(word_weight[rand2]>4){
         word_weight[rand2]-=4;
         total-=4;
        }
      }
      else{
         ui->textEdit_2->append("input 2 is wrong!");
         word_weight[rand2]+=20;
         total+=20;
        }
}

void wordInput::on_pushButton_2_clicked()//right answer button
{
    ui->textEdit_2->append(QString("%1").arg(word[rand1]));
    ui->textEdit_2->append(QString("%1").arg(word[rand2]));
}

void wordInput::on_pushButton_3_clicked() //renew button
{
    show1();
}

void wordInput::on_lineEdit_editingFinished()
{
    ui->lineEdit->selectAll();
}

void wordInput::on_lineEdit_2_editingFinished()
{
    ui->lineEdit_2->selectAll();
}
