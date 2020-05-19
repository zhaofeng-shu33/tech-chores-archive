#include <QApplication>
#include <QLineEdit>
#include <QDebug>
#include <QTextCodec>
#include <QGridLayout>
#include "inputmethod.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget* w1=new QWidget;
    QGridLayout *layout = new QGridLayout;
    QLineEdit* labelOne = new QLineEdit("eins",w1);
    QLineEdit* labelTwo=new QLineEdit("zwei",w1);
    layout->addWidget(labelOne, 0, 0);
    layout->addWidget(labelTwo,1,0);
    w1->setLayout(layout);
    w1->show();
    QObject::connect(&app,SIGNAL(focusChanged(QWidget *, QWidget *)),&app,SLOT(quit()));



    return app.exec();
}

