#include <QApplication>
#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ThreadDialog *threadDialog=new ThreadDialog;
    threadDialog->exec();
    //w.show();

    return a.exec();
}
