#include "widget.h"

ThreadDialog::ThreadDialog(QWidget *parent) : QDialog(parent){
    //threadA.setMessage("A");
    //threadB.setMessage("B");

    threadAButton=new QPushButton("Start A",this);
    threadAButton->setGeometry(10, 30, 80, 30);
    threadBButton=new QPushButton("start B",this);
    threadBButton->setGeometry(110, 30, 80, 30);
    quitButton = new QPushButton(tr("Quit"), this);
    quitButton->setGeometry(210, 30, 80, 30);
    quitButton->setDefault(true);//press enter and the app quits.

   // connect(threadAButton,SIGNAL(clicked()),this,SLOT(startOrStopThreadA()));
   // connect(threadBButton,SIGNAL(clicked()),this,SLOT(startOrStopThreadB()));
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));

}
/*void ThreadDialog::startOrStopThreadA(){
    if(threadA.isRunning()){
        threadA.stop();
        threadAButton->setText("Start A");
    }
    else
    {
        threadA.start();
        threadAButton->setText("Stop A");
    }
}
void ThreadDialog::startOrStopThreadB(){
    if(threadB.isRunning()){
        threadB.stop();
        threadBButton->setText("Start B");
    }
    else
    {
        threadB.start();
        threadBButton->setText("Stop B");
    }
}
*/
void ThreadDialog::closeEvent(QCloseEvent *event){
    event->accept();
}
void ThreadDialog::close(){
   exit(0);
}
