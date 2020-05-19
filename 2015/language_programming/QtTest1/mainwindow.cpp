#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QTextCodec>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFile File("\words.txt");
    File.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream out(&File);

    QTextCodec * codec =QTextCodec::codecForName("GB18030");
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));

    QString line=out.read(10);
    QMessageBox msBox;
    msBox.setText(QString(line));
    msBox.exec();

 /* QFile File("\words.txt");
    File.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream out(&File);
    QString line=out.read(75);
    QMessageBox msBox;
    msBox.setText(QString(line));
    msBox.exec();*/
}

MainWindow::~MainWindow()
{
    delete ui;
}
