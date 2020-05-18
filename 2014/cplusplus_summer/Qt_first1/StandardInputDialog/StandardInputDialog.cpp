#include "StandardInputDialog.h"
#include <QColorDialog>
StandardInputDialog::StandardInputDialog(){
   // label1= new QLabel("Name");
    nameLabel=new QLabel;
    nameButton=new QPushButton("&Name");
  //  label2= new QLabel("age");
    ageLabel=new QLabel;
    ageButton=new QPushButton("&age");
 //   label3=new QLabel("sex");
    sexLabel=new QLabel;
    sexButton=new QPushButton("&sex");
    statureLabel=new QLabel;
    statureButton=new QPushButton("&stature");
    QFormLayout* layout=new QFormLayout();//+this?
    layout->addRow(nameButton,nameLabel);
    layout->addRow(ageButton,ageLabel);
    layout->addRow(sexButton,sexLabel);
    layout->addRow(statureButton,statureLabel);
    setLayout(layout);
    connect(nameButton,SIGNAL(clicked()),this,SLOT(slotName()));
    connect(ageButton,SIGNAL(clicked()),this,SLOT(slotAge()));
    connect(sexButton,SIGNAL(clicked()),this,SLOT(slotSex()));
    connect(statureButton,SIGNAL(clicked()),this,SLOT(slotStatue()));
}
void StandardInputDialog::slotName(){
    bool ok;
    QString name=QInputDialog::getText(this,"user name","please input your name",QLineEdit::Normal,nameLabel->text(),&ok);
    if(ok&&!name.isEmpty())
        nameLabel->setText(name);
}
void StandardInputDialog::slotAge(){
    bool ok;
    int n=QInputDialog::getInteger(this,"user age","please input your age",0,0,140,1,&ok);
    if(ok)
    ageLabel->setText(QString("%1").arg(n));
}
void StandardInputDialog::slotSex(){
    QStringList list;
    list.append("male");
    list.append("female");
   // list<<"male"<<"female";
    bool ok;
    QString sex=QInputDialog::getItem(this,"user sex","please input your sex",list,0,false,&ok);
    if(ok)
        sexLabel->setText(sex);
}
void StandardInputDialog::slotStatue(){
    bool ok;
    double n=QInputDialog::getDouble(this,"user stature","please input yout stature",0,0,280,1,&ok);
    if(ok)
        statureLabel->setText(QString("%1").arg(n));
}
