#include "mainwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QKeySequence>
#include <QToolBar>
#include <QMessageBox>
#include <QStatusBar>
#include "FindDialog.h"
#include "StandardInputDialog.h"
#include <QFileDialog>
#include <QColorDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    openAction1=new QAction("open1",this);
    openAction1->setShortcut(QKeySequence::Open);
    openAction1->setStatusTip("open a find dialog");
    openAction1->setIcon(QIcon(":/open.jpg"));
    connect(openAction1,SIGNAL(triggered()),this,SLOT(open1()));

    openAction2=new QAction("open2",this);
    openAction2->setStatusTip("open a standard input dialog");
    openAction2->setIcon(QIcon(":/open2.jpg"));
    connect(openAction2,SIGNAL(triggered()),this,SLOT(open2()));

    openAction3=new QAction("open3",this);
    openAction3->setStatusTip("open a file selection dialog");
    connect(openAction3,SIGNAL(triggered()),this,SLOT(open3()));

    openAction4=new QAction("open4",this);
    connect(openAction4,SIGNAL(triggered()),this,SLOT(open4()));

    QMenu *file=menuBar()->addMenu("&File");
    file->addAction(openAction1);
    file->addAction(openAction2);
    file->addAction(openAction3);
    file->addAction(openAction4);
    QToolBar *toolBar=addToolBar("&ToolBar1");
    toolBar->addAction(openAction1);
    toolBar->addAction(openAction2);
    toolBar->addAction(openAction3);

    label=new QLabel;
    label->setMinimumSize(label->sizeHint());
    label->setAlignment(Qt::AlignHCenter);
    statusBar()->addWidget(label);
    statusBar()->setStyleSheet(QString("QStatusBar::item{border: 0px}"));
    //    QMessageBox::information(this,"Hint","the size grip is enabled");
}

MainWindow::~MainWindow()
{

}
void MainWindow::open1(){
    FindDialog my;
    my.exec();
    //QMessageBox::information(this,"open","open a file");
}
void MainWindow::open2(){
    StandardInputDialog my;
    my.exec();
}
void MainWindow::open4(){
   /* QMessageBox mybox(QMessageBox::NoIcon,"Title","Content",QMessageBox::Yes|QMessageBox::No);
    mybox.setIconPixmap(QPixmap(":/cut.png"));
    if(mybox.exec()==QMessageBox::Yes)
        QMessageBox::aboutQt(NULL,"About Qt");
   */
    QMessageBox myBox;
    myBox.setText("content");
    QPushButton* myButton=myBox.addButton("Journalistin",QMessageBox::ActionRole);
    myBox.addButton(QMessageBox::Abort);
    myBox.exec();
    if(myBox.clickedButton()==myButton)
       open2();

}

void MainWindow::open3(){
   // QColor my = QColorDialog::getColor(Qt::white,this);
    //if(my.isValid())
    //    label->setAutoFillBackground(true);

    QStringList path = QFileDialog::getOpenFileNames(this,"Open Imag",".","Image Files(*.jpg);;Code Files(*.cpp)");
    if(path.length()==0)
        QMessageBox::information(this,"path","you didn't select any files.");
    else{
        for(int t=0;t<path.size();t++)
        QMessageBox::information(this,"path","you select"+path[t]);
    }
}
/*
   QFileDialog* f=new QFileDialog(this);
   f->setWindowTitle("Open Imag");
   f->setDirectory(".");
   f->setFilter("Image Files(*.jpg)");
   if(f->exec()==QFileDialog::Accepted){
       QStringList path= f->selectedFiles();
       int i=path.size();
       for(int t=0;t<i;t++)
       QMessageBox::information(this,"path","you select"+path[t]);
   }
   else
      QMessageBox::information(this,"path","you didn't select any files");
*/

