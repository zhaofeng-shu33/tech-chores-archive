#include <QtGui/QApplication>
#include "mainwindow.h"
#include "StandardInputDialog.h"
#include "EventLabel.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
   /* EventLabel myLabel;
    myLabel.setWindowTitle("MouseEvent");
    myLabel.resize(300,200);
    StandardInputDialog my1;
    my1.setModal(false);
    my1.setWindowFlags(Qt::WindowStaysOnTopHint);
    my1.show();
     myLabel.show();

   */return a.exec();
}
