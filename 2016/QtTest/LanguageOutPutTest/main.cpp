#include <QtCore/QCoreApplication>
#include <QDebug>
#include <QTextCodec>
#include <QTextStream>
//QTextCodec * codec =QTextCodec::codecForName("GBK");
int main(int argc, char *argv[])
{

    QTextStream cout1(stdout);
    QTextStream cin(stdin);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    cout1.setCodec("ISO 8859-1");
    cout1<<"Willkommen zu der sch?ne Welt von C++";

  //  cout1<<codec->toUnicode("ÖÐÎÄ");
    cout1<<"Bitte geben Sie eine Eingabe: "<<endl;
   QString str;
   //cin>>str;
   cout1<<"Die Ausgabe ist: ";
   //char ch;
   //cin>>ch;
   //cout<<str;
   return 0;
}
