#include <QApplication>
#include <QIcon>
#include "wordinput.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon("Deutsch.ico"));
    wordInput wordinput;
    wordinput.show();
    return app.exec();
}

