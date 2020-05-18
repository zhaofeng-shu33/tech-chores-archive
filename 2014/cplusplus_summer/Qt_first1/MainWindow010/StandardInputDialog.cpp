#include "StandardInputDialog.h"
#include <QColorDialog>
#include <QFontDialog>
#include <QMessageBox>
StandardInputDialog::StandardInputDialog(){
    label1= new QLabel("Name");
    nameLabel=new QLabel;
    nameButton=new QPushButton("Name");
    label2= new QLabel("<font color=red> age </font>");
    //label2->setFont(QFontDialog::getFont(0,NULL));
    ageLabel=new QLabel;
    ageButton=new QPushButton("age");
    label3=new QLabel("sex");
    label3->setStyleSheet("color:blue");

    sexLabel=new QLabel;
    sexButton=new QPushButton("sex");
    QGridLayout* layout=new QGridLayout();//+this?
    layout->addWidget(label1,1,1);
    layout->addWidget(nameLabel,1,2);
    layout->addWidget(nameButton,1,3);
    layout->addWidget(label2,2,1);
    layout->addWidget(ageLabel,2,2);
    layout->addWidget(ageButton,2,3);
    layout->addWidget(label3,3,1);
    layout->addWidget(sexLabel,3,2);
    layout->addWidget(sexButton,3,3);
    setLayout(layout);
    connect(nameButton,SIGNAL(clicked()),this,SLOT(slotName()));
    connect(ageButton,SIGNAL(clicked()),this,SLOT(slotAge()));
    connect(sexButton,SIGNAL(clicked()),this,SLOT(slotSex()));
}
void StandardInputDialog::slotName(){
    bool ok;
    QString name=QInputDialog::getText(this,"user name","please input your name",QLineEdit::Normal,nameLabel->text(),&ok);
    if(ok&&!name.isEmpty())
        nameLabel->setText(name);
}
void StandardInputDialog::slotAge(){

    //QMessageBox::StandardButton r;
  /*  int r;
    r=QMessageBox::critical(this,"Warning:","Ich habe mein Studium vor kurzem beendet",QMessageBox::Abort,QMessageBox::Retry,QMessageBox::Ignore);
    if(r==QMessageBox::Abort)
       ageLabel->setText("Abort");
    else if(r==QMessageBox::Retry)
       ageLabel->setText("Retry");
    else
       ageLabel->setText("Ignore");
*/
      bool ok;
    //QFont f=QFontDialog::getFont(&ok,this);
   // QFontDialog f(this);
   // f.exec();

    int age=QInputDialog::getInteger(this,"user age","please input your age",100,0,140,1,&ok);
    if(ok)
        ageLabel->setText(QString("%1").arg(age));
 }
void StandardInputDialog::slotSex(){
    QStringList list;
    list<<"male"<<"female";
    bool ok;
    QString sex=QInputDialog::getItem(this,"user sex","please input your sex",list,0,false,&ok);
    if(ok)
        sexLabel->setText(sex);
}
