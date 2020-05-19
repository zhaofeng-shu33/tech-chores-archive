#include <QTextCodec>
#include <phonon/MediaObject>
#include <phonon/VideoPlayer>
#include <phonon/VideoWidget>
#include <QDebug>
#include <QDate>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <iostream>
#include <fstream>
#include "wordinput.h"
#include "ui_wordinput.h"
using namespace std;
bool AudioMode=1;
wordInput::wordInput(wordSource *parent) :
    wordSource(parent),
    ui(new Ui::wordInput)
{
    ui->setupUi(this);
    show1();
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
}

wordInput::~wordInput()
{
    delete ui;
}
void wordInput::renew(){   //核心算法
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit->setFocus();
        rand1=generate_random_number();
        rand2=generate_random_number();
        ifstream fin("D:/C++/language programming/FrenchIntegrated/hiragana.txt");

        for(int i=0;i<num;i++){
          string tmp;
          fin>>tmp;
          cout<<tmp<<' '<<word_weight[i]<<' ';
        }
        cout<<endl;
        fin.close();
        while(rand1==rand2)
               rand2=generate_random_number();
}
void wordInput::show1(){
    ui->textEdit->clear();
    ui->textEdit_2->clear();
    renew();
    ui->textEdit->append(QString("%1:%2").arg(1).arg(word[rand1]));
    ui->textEdit->append(QString("%1:%2").arg(1).arg(word_2[rand1]));
    ui->textEdit->append(QString("%1:%2").arg(1).arg(word[rand2]));
    ui->textEdit->append(QString("%1:%2").arg(2).arg(word_2[rand2]));
      ChoiceOfAudioResource(rand1,rand2);
  }




void wordInput::on_pushButton_clicked()
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

void wordInput::on_pushButton_2_clicked()
{
    ui->textEdit_2->append(QString("%1").arg(word[rand1]));
    ui->textEdit_2->append(QString("%1").arg(word[rand2]));
}

void wordInput::on_pushButton_3_clicked()
{
    show1();
}
void wordInput::ChoiceOfAudioResource(int rand){
        Phonon::MediaObject *music =
                 Phonon::createPlayer(Phonon::MusicCategory,
                                      Phonon::MediaSource(wordAudioAddress[rand]));
             music->play();
}

void wordInput::ChoiceOfAudioResource(int rand1,int rand2){
        Phonon::MediaObject *music =
                 Phonon::createPlayer(Phonon::MusicCategory,
                                      Phonon::MediaSource(wordAudioAddress[rand1]));
       music->enqueue(wordAudioAddress[rand2]);
       music->play();
     //  music->deleteLater();
   }
void wordInput::on_AudioOneButton_clicked()
{
    ChoiceOfAudioResource(rand1);
}

void wordInput::on_AudioTwoButton_clicked()
{
    ChoiceOfAudioResource(rand2);
}
