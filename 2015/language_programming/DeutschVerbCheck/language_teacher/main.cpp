#include <QApplication>

#include "MainClass.h"

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(teacher);
    QApplication app(argc, argv);
    app.setQuitOnLastWindowClosed(false);
    MainClass m;
    return app.exec();
}
