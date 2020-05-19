#include <QtGui/QApplication>
#include <QtUiTools/QUiLoader>
#include <QFile>
#include "mainwindow.h"
#include <QMainWindow>
#include "ui_scalabledialog.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QUiLoader uiLoader;
    QFile file("rectangledialog.ui");
    QWidget* scalabledialog=uiLoader.load(&file);
    file.close();
    scalabledialog->show();

    return a.exec();
}
