#include <QApplication>
#include "mainwindow.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mainwindow;
    mainwindow.setFixedSize(415,547);

    mainwindow.show();
    return app.exec();
}

