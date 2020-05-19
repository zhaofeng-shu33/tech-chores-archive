#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore/QFile>
#include <QtCore/QTextStream>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    QFile data("output.txt");
     if (data.open(QFile::WriteOnly | QFile::Truncate)) {
         QTextStream out(&data);
         out << "Result: " << qSetFieldWidth(10) << left << 3.14 << 2.7;
    }
    delete ui;
}
