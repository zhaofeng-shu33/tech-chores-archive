#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralWidget->setMouseTracking(true);
    qDebug()<<"hasMouseTracking"<<' '<<this->hasMouseTracking();

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::mouseMoveEvent(QMouseEvent *event){
    qDebug()<<event->globalPos();
    QPoint p=event->pos();
    ui->statusBar->setToolTip(QString("%1,%2").arg(p.x()).arg(p.y()));
}
