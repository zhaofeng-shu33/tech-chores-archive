#include <QApplication>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>
#include <QPushButton>
#include "graph.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget*w=new QWidget();
    w->setWindowTitle("Enter your Age");
    QSpinBox *spinBox=new QSpinBox;
    QSlider *slider=new QSlider(Qt::Horizontal);
    spinBox->setRange(0,130);
    slider->setRange(0,130);
    QObject::connect(spinBox,SIGNAL(valueChanged(int)),slider,SLOT(setValue(int)));
    QObject::connect(slider,SIGNAL(valueChanged(int)),spinBox,SLOT(setValue(int)));
    spinBox->setValue(21);
    QHBoxLayout* layout=new QHBoxLayout;
    layout->addWidget(spinBox);
    layout->addWidget(slider);
    w->setLayout(layout);
    w->show();

    Graph myGraph;
    myGraph.insertVertex('C');
    myGraph.insertVertex('H');
    myGraph.insertVertex('H');
    myGraph.insertVertex('H');
    myGraph.insertVertex('H');
    myGraph.insertEdge(0,1);
    myGraph.insertEdge(0,2);
    myGraph.insertEdge(0,3);
    myGraph.insertEdge(0,4);
    myGraph.printAdjoiningMatrix();
    for(int i=0;i<5;i++)
       qDebug()<<myGraph.getValue(i);
    qDebug()<<myGraph.getDegree(0);
    return a.exec();
}
