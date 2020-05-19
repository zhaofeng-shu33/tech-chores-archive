#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QGridLayout>
#include <QPushButton>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    list.append("ich 1 s");
    list.append("du 2 s");
    list.append("er 3 s der");
    list.append("sie 3 s die");
    list.append("es 3 s das");
    //list.append("man 3");
    list.append("wir 1 p");
    list.append("ihr 2 p");
    list.append("sie 3 p");
    list.append("Sie 2 Respekt");
    for(int i=0;i<list.size();i++){
        button[i]=new QPushButton(list[i].split(" ")[0]);
        button[i]->setCheckable(true);
    }
    QFile file("../SubjectPronoun/data.txt");
    file.open(QFile::ReadOnly);
    QTextStream fout(&file);
    QString selectInstruction=fout.readLine();
    QStringList rightAnswerList=fout.readLine().split(" ");//random selection from datafile
    ui->label->setText(QString("select %1").arg(selectInstruction));
    for(int i=0;i<list.size();i++)
        RightAnswer[i]=(rightAnswerList[i]=="1");
    QGridLayout *gridLayout=new QGridLayout;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            gridLayout->addWidget(button[3*i+j],i,j);//random arrangement
    ui->groupBox->setLayout(gridLayout);
    connect(ui->submitBtn,SIGNAL(clicked()),this,SLOT(ProcessingSubmit()));
}

Widget::~Widget()
{
    delete ui;
}
void Widget::ProcessingSubmit(){
    for(int i=0;i<list.size();i++)
        if((button[i]->isChecked())!=RightAnswer[i]){
        QMessageBox::information(this,"Hint","Wrong Answer"); //diagnostic information
        return;                                               //should be provided;
    }
    QMessageBox::information(this,"Hint","Right Answer");
}
