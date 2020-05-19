#include <QApplication>
#include <QDialog>
#include "rectangledialog.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RectangleDialog* dialog=new RectangleDialog;
    dialog->show();
    return a.exec();
}


