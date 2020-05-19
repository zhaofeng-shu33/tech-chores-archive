#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qInstallMsgHandler(MessageWindow::AppendMsgWrapper);
    MainWindow w;
    w.show();

    return a.exec();
}
