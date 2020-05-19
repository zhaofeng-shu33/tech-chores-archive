#include <QtGui>
#include <QTextCodec>
#include <math.h>
#include "rectangledialog.h"
RectangleDialog::RectangleDialog(QWidget *parent):QDialog(parent){
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));

    lengthLabel=new QLabel("&Rectangle Length",this);
    lengthEdit=new QLineEdit(this);
    QRegExp regExp("^[0-9]+(\\.[0-9]+)?$");
    lengthEdit->setValidator(new QRegExpValidator(regExp,this));
    lengthLabel->setBuddy(lengthEdit);

    widthLabel=new QLabel("&Rectangle Width",this);
    widthEdit=new QLineEdit(this);
    widthEdit->setValidator(new QRegExpValidator(regExp,this));
    widthLabel->setBuddy(widthEdit);

    rectangleAreaLabel=new QLabel("Rectangle Area",this);
    rectangleAreaEdit=new QLineEdit(this);
    calculateButton=new QPushButton("Calculate the area of rectangle",this);
    calculateButton->setDefault(true);
    calculateButton->setEnabled(false);
    closeButton=new QPushButton("Close",this);
    connect(lengthEdit,SIGNAL(textChanged(QString)),this,SLOT(enableCalculateButton()));
    connect(widthEdit,SIGNAL(textChanged(QString)),this,SLOT(enableCalculateButton()));
    connect(calculateButton,SIGNAL(clicked()),this,SLOT(calculateClicked()));
    connect(this,SIGNAL(rectangleLengthWidth(QString,QString)),this,SLOT(rectangleAreaCalculate(QString,QString)));
    connect(closeButton,SIGNAL(clicked()),this,SLOT(close()));

    QHBoxLayout *topLeftLayout=new QHBoxLayout;
    topLeftLayout->addWidget(this->lengthLabel);
    topLeftLayout->addWidget(this->lengthEdit);
    QHBoxLayout *middleLeftLayout=new QHBoxLayout;
    middleLeftLayout->addWidget(this->widthLabel);
    middleLeftLayout->addWidget(this->widthEdit);
    QHBoxLayout *bottomLeftLayout=new QHBoxLayout;
    bottomLeftLayout->addWidget(this->rectangleAreaLabel);
    bottomLeftLayout->addWidget(this->rectangleAreaEdit);
    QVBoxLayout* leftLayout=new QVBoxLayout;
    leftLayout->addLayout(topLeftLayout);
    leftLayout->addLayout(middleLeftLayout);
    leftLayout->addLayout(bottomLeftLayout);
    QVBoxLayout* rightLayout=new QVBoxLayout;
    rightLayout->addWidget(this->calculateButton);
    rightLayout->addWidget(this->closeButton);
    rightLayout->addStretch();
    QHBoxLayout* mainLayout=new QHBoxLayout;
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);
    setLayout(mainLayout);
    setWindowTitle("Calculate the area of rectangle");
    setFixedHeight(sizeHint().height());
}
void RectangleDialog::calculateClicked(){
    QString lengthString=lengthEdit->text();
    QString widthString=widthEdit->text();
    emit rectangleLengthWidth(lengthString,widthString);
}
void RectangleDialog::rectangleAreaCalculate(const QString &lengthString, const QString &widthString){
    double length=lengthString.toDouble();
    double width=widthString.toDouble();
    double result=length*width;
    rectangleAreaEdit->setText(QString::number(result,'f',3));
}
void RectangleDialog::enableCalculateButton(){
    calculateButton->setEnabled(!lengthEdit->text().isEmpty()&&(!widthEdit->text().isEmpty()));
}

