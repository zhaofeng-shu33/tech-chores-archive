#include <QtGui>
#include "rectangledialog.h"
RectangleDialog::RectangleDialog(QWidget *parent):QDialog(parent){
    setupUi(this);
    QRegExp regExp("^[0-9]+(\\.[0-9]+)?$");
    lengthEdit->setValidator(new QRegExpValidator(regExp,this));
    widthEdit->setValidator(new QRegExpValidator(regExp,this));

    connect(lengthEdit,SIGNAL(textChanged(QString)),this,SLOT(enableCalculateButton()));
    connect(widthEdit,SIGNAL(textChanged(QString)),this,SLOT(enableCalculateButton()));
    connect(calculateButton,SIGNAL(clicked()),this,SLOT(calculateClicked()));
    connect(this,SIGNAL(rectangleLengthWidth(QString,QString)),this,SLOT(rectangleAreaCalculate(QString,QString)));
    connect(closeButton,SIGNAL(clicked()),this,SLOT(close()));
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


