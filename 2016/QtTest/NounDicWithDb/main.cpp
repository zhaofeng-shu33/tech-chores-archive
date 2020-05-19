#include <QApplication>
#include "mainwindow.h"
#include <QDir>
int main(int argc, char *argv[])
{
    QApplication::addLibraryPath(QString("%1/plugins").arg(QDir::currentPath()));
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon("Deutsch.ico"));
    MainWindow mainwindow;
    mainwindow.show();
    return app.exec();
}

