#include "widget.h"
#include "ui_widget.h"
#include <iostream>
#include <QFile>
#include <QTextStream>
#include<QStringList>
#include<QTextCodec>
#include <ctime>
Widget::Widget(QWidget *parent,int total_weight) :
    QWidget(parent),total_weight(0),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    srand((unsigned)time(0));
    QFile nounData(":/NounSource.txt");
    nounData.open(QIODevice::ReadOnly);
    QTextStream out(&nounData);
    int tmp=1;
    while(!out.atEnd()){
    QString str=out.readLine(75);
    QStringList strList=str.split("\t");
    Nounlist.push_back(Noun(strList.first()," ",tmp,strList[1]));
    for(int i=2;i<strList.size();i++)
        Nounlist[tmp-1].set_example_sentence(strList[i]);
    this->set_total_weight(this->get_total_weight()+Nounlist[tmp-1].get_weight());
    tmp++;
    }
    ui->lineEdit->setFocus();

}

Widget::~Widget()
{
    delete ui;
}
int Widget::renew(){
    int n=generate_random_number();
    ui->textBrowser->append(QString("Das ist ___ %1.").arg(Nounlist[n-1].get_spell()));
    return n;
}

double Widget::distribution_function(int n){//n takes 1 ~ maximum length of Nounlist
    int sum=0;
    for(int t=1;t<=n;t++)
        sum+=Nounlist[t-1].get_weight();
    return sum*1.0/get_total_weight();
}
int Widget::generate_random_number(){  //generate random number from 1 to total_weight
   double tmp;
   for(int t=0;t<5;t++)
        tmp=(rand()%1000)*1.0/1000;//a random number generated from interval 0 to 1
   for(int t=1;t<get_total_weight();t++){
       if(tmp<distribution_function(1))
          return 1;
       if((distribution_function(t)<=tmp)&&(tmp<distribution_function(t+1)))
          return t+1;
   }
}

void Widget::on_lineEdit_editingFinished()
{
    QString checkString= ui->lineEdit->text();
    if(checkString.length()==0){
       ui->textBrowser->clear();
       set_current_random_number(renew());
       ui->lineEdit->setFocus();
       return;
    }
    ui->lineEdit->clear();
    int n=get_current_random_number();
    QString current_gender=Nounlist[n-1].get_gender();
    int current_weight=Nounlist[n-1].get_weight();
    if(((current_gender=="das"||current_gender=="der")&&checkString=="ein")||(current_gender=="die"&&checkString=="eine")){
        ui->textBrowser->append("Congratulations,your Answer is right!");
        if(current_weight>=10){
         Nounlist[n-1].set_weight(current_weight-10);
         set_total_weight(get_total_weight()-10);
       }
    }
    else{
        ui->textBrowser->append("Sorry,your answer is wrong.");
        Nounlist[n-1].set_weight(current_weight+20);
        set_total_weight(get_total_weight()+20);
        }
    if(Nounlist[n-1].whether_have_example_sentence())
    ui->textBrowser->append(QString("An example sentence:<font color='red'> %1 <font>").arg(Nounlist[n-1].get_example_sentence_randomly()));

    ui->textBrowser->append("Press Enter to continue");
    return;
}

