#include <QSize>
#include <QDebug>
#include <QInputDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "frenchtry.h"
#include "wordinput.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setWindowIcon(QIcon(":/images/appearance.png"));
    ui->setupUi(this);
   // creatNewWin();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    FrenchTry* my_FrenchTry = new FrenchTry;
    my_FrenchTry->show();

}

void MainWindow::on_pushButton_2_clicked()
{
    wordInput* my_wordInput=new wordInput;
    my_wordInput->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    int factArg=QInputDialog::getInt(this,"Factorial Calculator","Factorial of: ",1);
    qDebug()<<factArg;
}
