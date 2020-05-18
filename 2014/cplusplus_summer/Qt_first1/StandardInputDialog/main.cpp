#include "StandardInputDialog.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    StandardInputDialog w;

    w.show();

    return a.exec();
}
