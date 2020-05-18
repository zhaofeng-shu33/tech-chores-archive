#include "qmmainwindow.h"
#include "ui_qmmainwindow.h"
#include <string>
#include <iostream>
using namespace std;
enum position{chaser,beater,keeper,seeker};
struct player{
  string name;
  int hit_target;
  int endurance;
  int  nimble;
  position special_pos;
  double general_factor;
  //double special_fac;
};player p[7];double max1=0;int order[3];
void swap(int& a,int& b){
    int t=a;
    a=b;
    b=t;
}
void judge(int b[]){
  double tem;//b[0],b[1],b[2];beater beater seeker;
  p[b[0]].general_factor=0.5*p[b[0]].hit_target+2*p[b[0]].endurance+0.5*p[b[0]].nimble;
  p[b[1]].general_factor=0.5*p[b[1]].hit_target+2*p[b[1]].endurance+0.5*p[b[1]].nimble;
  p[b[2]].general_factor=0.5*p[b[0]].hit_target+0.5*p[b[0]].endurance+2*p[b[0]].nimble;
  tem=( p[b[0]].general_factor+p[b[1]].general_factor ) * p[b[2]].general_factor;
  if(tem>max1){
  max1=tem;
  order[0]=b[0];order[1]=b[1];order[2]=b[2];
  }
}
void Perm(int k,int n,int r,int a[]){
    if(r==0){
       for(int i=0;i<k;i++)
           judge(a);

    return;
  }

    for(int i=k;i<n;i++){
      swap(a[i],a[k]);
      Perm(k+1,n,r-1,a);
      swap(a[i],a[k]);
    }
}

QMMainWindow::QMMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QMMainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setEnabled(false);
    connect(ui->lineEdit,SIGNAL(textChanged(QString)),this,SLOT(try_enable_PushButton()));
    connect(ui->lineEdit_5,SIGNAL(textChanged(QString)),this,SLOT(try_enable_PushButton()));
    connect(ui->lineEdit_13,SIGNAL(textChanged(QString)),this,SLOT(try_enable_PushButton()));
    connect(ui->lineEdit_14,SIGNAL(textChanged(QString)),this,SLOT(try_enable_PushButton()));
    connect(ui->lineEdit_29,SIGNAL(textChanged(QString)),this,SLOT(try_enable_PushButton()));
    connect(ui->lineEdit_30,SIGNAL(textChanged(QString)),this,SLOT(try_enable_PushButton()));
    connect(ui->lineEdit_22,SIGNAL(textChanged(QString)),this,SLOT(try_enable_PushButton()));
    connect(ui->lineEdit_2,SIGNAL(textChanged(QString)),this,SLOT(try_enable_PushButton()));
    connect(ui->lineEdit_6,SIGNAL(textChanged(QString)),this,SLOT(try_enable_PushButton()));
    connect(ui->lineEdit_9,SIGNAL(textChanged(QString)),this,SLOT(try_enable_PushButton()));
    connect(ui->lineEdit_11,SIGNAL(textChanged(QString)),this,SLOT(try_enable_PushButton()));
    connect(ui->lineEdit_25,SIGNAL(textChanged(QString)),this,SLOT(try_enable_PushButton()));
    connect(ui->lineEdit_27,SIGNAL(textChanged(QString)),this,SLOT(try_enable_PushButton()));
    connect(ui->lineEdit_19,SIGNAL(textChanged(QString)),this,SLOT(try_enable_PushButton()));
    connect(ui->lineEdit_3,SIGNAL(textChanged(QString)),this,SLOT(try_enable_PushButton()));
    connect(ui->lineEdit_7,SIGNAL(textChanged(QString)),this,SLOT(try_enable_PushButton()));
    connect(ui->lineEdit_15,SIGNAL(textChanged(QString)),this,SLOT(try_enable_PushButton()));
    connect(ui->lineEdit_12,SIGNAL(textChanged(QString)),this,SLOT(try_enable_PushButton()));
    connect(ui->lineEdit_28,SIGNAL(textChanged(QString)),this,SLOT(try_enable_PushButton()));
    connect(ui->lineEdit_31,SIGNAL(textChanged(QString)),this,SLOT(try_enable_PushButton()));
    connect(ui->lineEdit_20,SIGNAL(textChanged(QString)),this,SLOT(try_enable_PushButton()));
    connect(ui->lineEdit_4,SIGNAL(textChanged(QString)),this,SLOT(try_enable_PushButton()));
    connect(ui->lineEdit_8,SIGNAL(textChanged(QString)),this,SLOT(try_enable_PushButton()));
    connect(ui->lineEdit_10,SIGNAL(textChanged(QString)),this,SLOT(try_enable_PushButton()));
    connect(ui->lineEdit_16,SIGNAL(textChanged(QString)),this,SLOT(try_enable_PushButton()));
    connect(ui->lineEdit_26,SIGNAL(textChanged(QString)),this,SLOT(try_enable_PushButton()));
    connect(ui->lineEdit_32,SIGNAL(textChanged(QString)),this,SLOT(try_enable_PushButton()));
    connect(ui->lineEdit_24,SIGNAL(textChanged(QString)),this,SLOT(try_enable_PushButton()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(begin_output()));

}

QMMainWindow::~QMMainWindow()
{
    delete ui;
}
void QMMainWindow::try_enable_PushButton(){

    name[0]=ui->lineEdit->text();
    name[1]=ui->lineEdit_5->text();
    name[2]=ui->lineEdit_13->text();
    name[3]=ui->lineEdit_14->text();
    name[4]=ui->lineEdit_29->text();
    name[5]=ui->lineEdit_30->text();
    name[6]=ui->lineEdit_22->text();
    for(int i=0;i<7;i++)
        if(name[i].size()==0)
            return;
     bool ok;
    hit_target_factor[0]=ui->lineEdit_2->text().toInt(&ok);
    hit_target_factor[1]=ui->lineEdit_6->text().toInt(&ok);
    hit_target_factor[2]=ui->lineEdit_9->text().toInt(&ok);
    hit_target_factor[3]=ui->lineEdit_11->text().toInt(&ok);
    hit_target_factor[4]=ui->lineEdit_25->text().toInt(&ok);
    hit_target_factor[5]=ui->lineEdit_27->text().toInt(&ok);
    hit_target_factor[6]=ui->lineEdit_19->text().toInt(&ok);
    if(!ok)
       return;
    endurance[0]=ui->lineEdit_3->text().toInt(&ok);
    endurance[1]=ui->lineEdit_7->text().toInt(&ok);
    endurance[2]=ui->lineEdit_15->text().toInt(&ok);
    endurance[3]=ui->lineEdit_12->text().toInt(&ok);
    endurance[4]=ui->lineEdit_28->text().toInt(&ok);
    endurance[5]=ui->lineEdit_31->text().toInt(&ok);
    endurance[6]=ui->lineEdit_20->text().toInt(&ok);
    if(!ok)
       return;
    nimble[0]=ui->lineEdit_4->text().toInt(&ok);
    nimble[1]=ui->lineEdit_8->text().toInt(&ok);
    nimble[2]=ui->lineEdit_10->text().toInt(&ok);
    nimble[3]=ui->lineEdit_16->text().toInt(&ok);
    nimble[4]=ui->lineEdit_26->text().toInt(&ok);
    nimble[5]=ui->lineEdit_32->text().toInt(&ok);
    nimble[6]=ui->lineEdit_24->text().toInt(&ok);
    if(ok)
       ui->pushButton->setEnabled(true);

}
void QMMainWindow::begin_output(){
    ui->label_18->setText(name[0]);
    ui->label_4->setText(name[1]);
    ui->label_6->setText(name[2]);
    ui->label_9->setText(name[3]);
    ui->label_10->setText(name[4]);
    ui->label_13->setText(name[5]);
    ui->label_14->setText(name[6]);
    //The following codes is copied from related cpp file.


     for(int i=0;i<7;i++){
          p[i].hit_target=hit_target_factor[i];
          p[i].endurance=endurance[i];
          p[i].nimble=nimble[i];
      }

      int a[]={0,1,2,3,4,5,6};
      Perm(0,7,3,a);
      p[order[0]].special_pos=beater;
      p[order[1]].special_pos=beater;
      p[order[2]].special_pos=seeker;


      double tem_gf=0;
      int fix_keeper=0;
      for(int i=0;i<7 ;i++){
         if(i==order[0]||i==order[1]||i==order[2])
            continue;
          p[i].general_factor=p[i].hit_target+p[i].endurance+p[i].nimble;
          if(p[i].general_factor>tem_gf)
            fix_keeper=i;tem_gf=p[i].general_factor;
      }
      p[fix_keeper].special_pos=keeper;
      for(int i=0;i!=fix_keeper&&i!=order[0]&&i!=order[1]&&i!=order[2]&&i<7;i++)
          p[i].special_pos=chaser;
      QLabel* ptr[7];
      QLabel* pts[7];
      ptr[0]=ui->label_22;
      ptr[1]=ui->label_23;
      ptr[2]=ui->label_24;
      ptr[3]=ui->label_25;
      ptr[4]=ui->label_26;
      ptr[5]=ui->label_27;
      ptr[6]=ui->label_28;
      pts[0]=ui->label_5;
      pts[1]=ui->label_20;
      pts[2]=ui->label_7;
      pts[3]=ui->label_8;
      pts[4]=ui->label_11;
      pts[5]=ui->label_12;
      pts[6]=ui->label_15;


      for(int i=0;i<7;i++){
           if(p[i].special_pos==3){
              ptr[i]->setText("seeker");
              pts[i]->setText(QString("%1").arg(0.5*hit_target_factor[i]+0.5*endurance[i]+2*nimble[i]));
          }if(p[i].special_pos==1){
              ptr[i]->setText("beater");
              pts[i]->setText(QString("%1").arg(0.5*hit_target_factor[i]+2*endurance[i]+0.5*nimble[i]));
          }
           if(p[i].special_pos==0){
              ptr[i]->setText("chaser");
              pts[i]->setText(QString("%1").arg(2*hit_target_factor[i]+0.5*endurance[i]+0.5*nimble[i]));
          }
           if(p[i].special_pos==2){
              ptr[i]->setText("keeper");
              pts[i]->setText(QString("%1").arg(hit_target_factor[i]+endurance[i]+nimble[i]));
          }
        }
}
