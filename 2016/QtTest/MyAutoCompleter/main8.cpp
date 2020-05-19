#include <QApplication>
#include "TextSearchDialog.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TextSearchDialog* myTextSearchDialog=new TextSearchDialog();
    myTextSearchDialog->show();
    return a.exec();
}


