#include "wordinput.h"
#include "ui_wordinput.h"
#include <QMessageBox>
#include <cstdlib>
#include <ctime>
#include <QFile>
#include <QTextStream>
#include <QFont>
#include <QTextCodec>
#include <phonon/MediaObject>
bool EnterTime=0;
QString stem="";
QString infinitive="";
int currentWordWithAudio=-1;
using namespace std;


void wordInput::readData(QString str,int n,QString wordlist[]){
    int i=0;
    QFile file(str);
    file.open(QIODevice::ReadOnly| QIODevice::Text);
    QTextStream in(&file);
    while(!in.atEnd()){
        wordlist[i++]=in.readLine(75);
    }
    if(n==0)cnt=i;
    file.close();
}

void wordInput::loadTextFile()
 {
     readData("D:/QtTest/QtTest17/verbInfinitive2.txt",0,&word[0][0]);
     readData("D:/QtTest/QtTest17/verbPresentTense.txt",1,&word[1][0]);
     readData("D:/QtTest/QtTest17/verbParticiple.txt",2,&word[2][0]);
     readData("D:/QtTest/QtTest17/verbPastTense.txt",3,&word[3][0]);
     readData("D:/QtTest/QtTest17/audioAddress.txt",1,wordAudioAddress);
     readData("D:/QtTest/QtTest17/wordWithAudio.txt",1,wordWithAudio);
 }
wordInput::wordInput(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::wordInput)
{
    ui->setupUi(this);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    srand(time(0));
    loadTextFile();
    for(int i=0;i<cnt;i++)
        word_weight[i]=5;
    total=5*cnt;
    ui->textEdit_2->setReadOnly(1);
    ui->textEdit_2->setAlignment(Qt::AlignHCenter);
   // ui->textEdit_3->append(word[0][0]);
    ui->stackedWidget->setCurrentIndex(0);
    show1();
}
double wordInput::distribution_function(int n){//n takes 0~cnt-1
    int sum=0;
    for(int t=0;t<=n;t++)
        sum+=word_weight[t];
    return sum*1.0/total;
}
int wordInput::generate_random_number(int zahl){
   double tmp;
   for(int t=0;t<5;t++)
        tmp=(rand()%1000)*1.0/1000;
   for(int t=0;t<zahl-1;t++){
       if(tmp<=distribution_function(0))
          return 0;
       if((distribution_function(t)<tmp)&&(tmp<=distribution_function(t+1)))
          return t+1;
   }
}

wordInput::~wordInput()
{
    delete ui;
}
void wordInput::renew(){   //核心算法
        randN[0][0]=generate_random_number(cnt);
        for(int i=0;i<5;i++){
          randN[0][1]=rand()%3;
          randN[0][2]=rand()%6;
      }
}
QString tense(int n){
    if(n==0) return "现在时";
    if(n==1) return "完成时";
    if(n==2) return "过去时";
}
QString person(int n){
    if(n==0)
       return "Ich";
    if(n==1)
       return "du";
    if(n==2)
       return "er/sie/es";
    if(n==3)
       return "wir";
    if(n==4)
       return "ihr";
    if(n==5)
       return "sie/Sie";
}
void wordInput::show1(){
    ui->textEdit->clear();
    renew();
    ui->textEdit->append(QString("请输入%1的第三人称%2单数形式,").arg(word[0][randN[0][0]]).arg(tense(randN[0][1])));
    ui->textEdit->append("然后按Enter键确认");
 //    ui->textEdit->append(QString("%1:%2").arg(person(randN[0][2])).arg(word[0][randN[0][0]]));
}


QString wordInput::getRightAnswer(int n){
    return word[randN[n][1]+1][randN[n][0]];
}
void wordInput::dictation(QString str){
    if(str==wordWithAudio[currentWordWithAudio])
        ui->textEdit_3->append("恭喜！你的答案是正确的。");
    else
        ui->textEdit_3->append("很抱歉，你的答案有误。");
}

void wordInput::check(QString str,int n){
    //randN[n][1] is the tense,taking value 0,1,2,
    if(getRightAnswer(n)==str||getRightAnswer(n).contains(str+'/')){
        ui->textEdit->append("恭喜！你的答案是正确的。");
        if(word_weight[randN[n][0]]>4){
         word_weight[randN[n][0]]-=4;
         total-=4;
       }
    }
    else{
        ui->textEdit->append("很抱歉，你的答案有误。");
        word_weight[randN[n][0]]+=20;
        total+=20;
   }
}
void wordInput::on_lineEdit_editingFinished()
{
    QString checkString1 = ui->lineEdit->text();
    if(checkString1.length()==0){
       ui->lineEdit->setFocus();
       return;
    }
    if(ui->stackedWidget->currentIndex()==1){
        seek(checkString1);
        return;
    }
    if(!EnterTime){
    if(ui->stackedWidget->currentIndex()==2){
        dictation(checkString1);
        ui->textEdit_3->append(QString("正确答案是 <font size=6> %1 <font>").arg(wordWithAudio[currentWordWithAudio]));
        ui->textEdit_3->append("请按Enter键继续");
        EnterTime=1;
        ui->lineEdit->setFocus();
        return;
    }
    ui->textEdit->clear();
    check(checkString1,0);
    ui->textEdit->append(QString("正确答案是 <font size=6> %1 <font>").arg(getRightAnswer(0)));
    ui->textEdit->append("请按Enter键继续");
    EnterTime=1;
    ui->lineEdit->setFocus();
    }
    else{
        ui->lineEdit->clear();
        ui->lineEdit->setFocus();
        EnterTime=0;
        if(ui->stackedWidget->currentIndex()==2){
            ui->textEdit_3->clear();
            currentWordWithAudio=rand()%11;
            ChoiceOfAudioResource(currentWordWithAudio);
            return;
        }
        show1();
    }
    return;
}

void ReviseStem(QString inf){
     stem="";
     if (inf[inf.length()-2]=='e')
        for(int i=0; i<=inf.length()-3;i++)
            stem=stem+inf[i];
     return;
}
QString getInf(){return infinitive;}
QString getIch_prasens(){
    return stem+'e';
}
QString getDu_prasens(){if ((stem[stem.length()-1]=='t')||(stem[stem.length()-1]=='d')||((stem[stem.length()-3]=='f')&&(stem[stem.length()-2]=='f')&&(stem[stem.length()-1]=='n'))
                           ||((stem[stem.length()-3]=='c')&&(stem[stem.length()-2]=='h')&&(stem[stem.length()-1]=='n'))
                           ||((stem[stem.length()-2]=='g')&&(stem[stem.length()-1]=='n'))) return stem+"est";
    if ((stem[stem.length()-1]=='s')||(QString(stem[stem.length()-1])==QString::fromUtf8("\u00DF")||((stem[stem.length()-2]=='s')&&(stem[stem.length()-1]=='s'))||(stem[stem.length()-1]=='z')||((stem[stem.length()-2]=='t')&&(stem[stem.length()-1]=='z')))) return stem+'t';
                        return stem+"st";}
 QString getEr_prasens(){if ((stem[stem.length()-1]=='t')||(stem[stem.length()-1]=='d')||((stem[stem.length()-3]=='f')&&(stem[stem.length()-2]=='f')&&(stem[stem.length()-1]=='n'))
                           ||((stem[stem.length()-3]=='c')&&(stem[stem.length()-2]=='h')&&(stem[stem.length()-1]=='n'))
                           ||((stem[stem.length()-2]=='g')&&(stem[stem.length()-1]=='n'))) return stem+"et";
                        return stem+'t';}
 QString getIhr_prasens(){return getEr_prasens();}
void wordInput::seek(QString str){
    ReviseStem(str);
    ui->textEdit_2->append(QString("不定式: %1").arg(str));
    ui->textEdit_2->append(QString("ich: %1").arg(getIch_prasens()));
    ui->textEdit_2->append(QString("du: <font color='red'> %1 </font>").arg(getDu_prasens()));
    ui->textEdit_2->append(QString("er/sie/es: %1").arg(getEr_prasens()));
    ui->textEdit_2->append(QString("wir: %1").arg(str));
    ui->textEdit_2->append(QString("ihr: %1").arg(getIhr_prasens()));
    ui->textEdit_2->append(QString("sie/Sie: %1").arg(str));
    ui->textEdit_2->find(str);
    ui->lineEdit->clear();
}
void wordInput::ChoiceOfAudioResource(int rand){
        Phonon::MediaObject *music =
                 Phonon::createPlayer(Phonon::MusicCategory,
                                      Phonon::MediaSource(wordAudioAddress[rand]));
             music->play();
}

void wordInput::on_comboBox_currentIndexChanged(int index)
{
    ui->stackedWidget->setCurrentIndex(index);
    if(index==2){
        currentWordWithAudio=rand()%11;
        ChoiceOfAudioResource(currentWordWithAudio);
    }
}
