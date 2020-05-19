#include "widget.h"
#include "ui_widget.h"
#include <QColor>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    myLed=new LedWidget(this);
    myLed->setColor(Qt::red);
}

Widget::~Widget()
{
    delete ui;
}
