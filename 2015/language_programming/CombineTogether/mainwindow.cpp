#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSize>
#include "frenchtry.h"
#include "wordinput.h"
#include "conjugaison.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
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

void MainWindow::on_pushButton_3_clicked()//Conjugaison Button
{
    Conjugaison* my_Conjugaison=new Conjugaison;
    my_Conjugaison->show();
}
