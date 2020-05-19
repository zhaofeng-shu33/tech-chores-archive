#include <QApplication>
#include <QDialog>
#include "ui_rectangledialog.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Ui::RectangleDialog ui;
    QDialog* dialog=new QDialog;
    ui.setupUi(dialog);
    dialog->show();
    return a.exec();
}


