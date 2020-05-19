#include "wordinput.h"
#include "ui_wordinput.h"
#include <QMessageBox>
#include <ctime>
#include <QFont>
#include <QTextCodec>
#include <phonon/MediaObject>
#include <QDebug>
#include <QtSql>
using namespace std;
bool EnterTime=0;
void wordInput::loadTextFile()
 {
    cnt=0;
    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
    QString dsn=QString("DRIVER={Microsoft Access Driver (*.mdb)};FIL={MS Access};DBQ=D:/QtTest/JpWord/Jp.mdb");
    db.setDatabaseName(dsn);
    if(!db.open()){
        qDebug()<<"Error: "<<db.lastError();
        return;
    }
    QSqlQuery query(db);
    if(!query.exec("select Unit_16 from Wort")){
        qDebug()<<query.lastError();
        return;
    }
    while(query.next()){
        word[cnt++]=query.value(0).toString();
    }
    qDebug()<<cnt;
    for(int i=0;i<cnt;i++)
        wordAudioAddress[i]=QString("D:/QtTest/JpWord/audio/%1.mp3").arg(i+1);
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
    ui->lineEdit->setFocus();
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
        random=generate_random_number(cnt);
        Phonon::MediaObject* music =
                 Phonon::createPlayer(Phonon::MusicCategory,
                                      Phonon::MediaSource(wordAudioAddress[random]));
             music->play();
}
void wordInput::show1(){
    ui->textEdit_3->clear();
    ui->textEdit_3->append(QString("请根据听到的单词读音写出单词的词型："));
    ui->textEdit_3->append("然后按Enter键确认");
    renew();
}

void wordInput::on_lineEdit_editingFinished()
{
    if(!EnterTime){EnterTime=1;show1();return;}
    QString checkString1 = ui->lineEdit->text();
    if(checkString1.length()==0){
       ui->lineEdit->setFocus();
       return;
    }
    {
    if(checkString1==word[random]){
        if(word_weight[random]>=4)word_weight[random]-=4;
        ui->textEdit_3->append("恭喜！你的答案是正确的。");
    }
    else{
        word_weight[random]+=10;
        ui->textEdit_3->append("很抱歉，你的答案有误。");
    }
    }
    ui->textEdit_3->append(QString("正确答案是 <font size=6> %1 <font>").arg(word[random]));
    ui->textEdit_3->append("请按Enter键继续");
    ui->lineEdit->clear();
    ui->lineEdit->setFocus();
    EnterTime=0;
    return;
}
