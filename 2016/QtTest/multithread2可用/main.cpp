#include <QApplication>
#include "threaddialog.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ThreadDialog *threadDialog=new ThreadDialog;
    //threadDialog->exec();
    threadDialog->show();
    //w.show();

    return a.exec();
}

