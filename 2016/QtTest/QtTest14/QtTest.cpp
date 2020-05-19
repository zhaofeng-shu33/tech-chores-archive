#include <QtGui/QApplication>
#include <QLabel>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLabel* label=new QLabel("Guten Tag!");
    label->show();
   
    return a.exec();
}
