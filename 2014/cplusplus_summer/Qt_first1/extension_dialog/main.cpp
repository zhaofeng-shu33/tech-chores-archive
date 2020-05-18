#include<QApplication>
#include"extensiondialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
     ExtensionDialog w;
     w.show();

    return a.exec();
}
