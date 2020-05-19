#include "wordinput.h"
#include "ui_wordinput.h"
#include <QMessageBox>
#include <ctime>
#include "widget.cpp"
using namespace std;
wordInput::wordInput(QString word[][num],int cnt) :
    QWidget(0),
    ui(new Ui::wordInput)
{
    ui->setupUi(this);
    for(int i=0;i<cnt;i++){
        wordtem[0][i]=word[0][i];
        for(int j=1;j<5;j++){
            for(int r=0;r<6;r++)
            wordtem[j][i*6+r]=word[j][i*6+r];
         }
    } cnttem=cnt;

    srand((unsigned)time(0));
    total=cnttem*5;
     for(int t=0;t<cnttem;t++){
         word_weight[t]=5;
     }

    show1();
}
double wordInput::distribution_function(int n){//n takes 0~cnttem-1
    int sum=0;
    for(int t=0;t<=n;t++)
        sum+=word_weight[t];
    return sum*1.0/total;
}
int wordInput::generate_random_number(){
   double tmp;
   for(int t=0;t<5;t++)
        tmp=(rand()%1000)*1.0/1000;
   for(int t=0;t<cnttem-1;t++){
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
void wordInput::renew(){
        randN[0][0]=generate_random_number();
        randN[1][0]=generate_random_number();
        for(int i=0;i<5;i++){
          randN[0][1]=rand()%4;
          randN[1][1]=rand()%4;
          randN[0][2]=rand()%6;
          randN[1][2]=rand()%6;
      }
        while(randN[0][0]==randN[1][0]){
            randN[1][0]=generate_random_number();
        }
}
QString tense(int n){

    if(n==0){
        return "présent";
    }
    if(n==1){
     return "passé composé";
   }
    if(n==2){
     return "futur simple";
    }
    if(n==3){
     return "imparfait";
    }
}
void wordInput::show1(){
    ui->textEdit->clear();
    ui->textEdit_2->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit->setFocus();
    renew();
    ui->textEdit->append(QString("%1").arg(tense(randN[0][1])));
    ui->textEdit->append(QString("%1:%2").arg(person(randN[0][2])).arg(wordtem[0][randN[0][0]]));
    ui->textEdit->append(QString("%1").arg(tense(randN[1][1])));
    ui->textEdit->append(QString("%1:%2").arg(person(randN[1][2])).arg(wordtem[0][randN[1][0]]));
}


QString wordInput::getRightAnswer(int n){
    return wordtem[randN[n][1]+1][6*randN[n][0]+randN[n][2]];
}

void wordInput::check(QString str,int n){
    //randN[n][1] is the tense,taking value 0,1,2,
    if(getRightAnswer(n)==str||getRightAnswer(n).contains(str+'/')){
        ui->textEdit_2->append(QString("input %1 is right!").arg(n+1));
        if(word_weight[randN[n][0]]>4){
         word_weight[randN[n][0]]-=4;
         total-=4;
       }
    }
    else{
        ui->textEdit_2->append(QString("input %1 is wrong!").arg(n+1));
        word_weight[randN[n][0]]+=20;
        total+=20;
   }
}

void wordInput::on_pushButton_clicked() //check button
{
     ui->textEdit_2->clear();
     QString checkString1 = ui->lineEdit->text();
     QString checkString2=ui->lineEdit_2->text();
     check(checkString1,0);
     check(checkString2,1);
}


void wordInput::on_pushButton_2_clicked()//right answer button
{
    ui->textEdit_2->append(getRightAnswer(0));
    ui->textEdit_2->append(getRightAnswer(1));
}

void wordInput::on_pushButton_3_clicked() //renew button
{
    show1();
}


void wordInput::on_pushButton_4_clicked()//revise button
{
    this->close();
}
