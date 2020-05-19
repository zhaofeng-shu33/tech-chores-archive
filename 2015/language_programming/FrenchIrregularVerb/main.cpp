#include <QApplication>
#include "widget.h"
#include <QWidget>
#include <QIcon>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon("French.ico"));
    Widget myWidget;
   // myWidget.show();
    return app.exec();
}

