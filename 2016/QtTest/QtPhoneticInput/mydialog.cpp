#include <phonon/MediaObject>
#include "mydialog.h"

MyDialog::MyDialog(QWidget *parent) :
    QWidget(parent)
{
    QTextStream cout(stdout);
    QTextStream cin(stdin);
    QString input;
    cout<<"Input: "<<flush;
    while(input!="End"){
    Phonon::MediaObject *music =
             Phonon::createPlayer(Phonon::MusicCategory,
                                  Phonon::MediaSource("D:/QtTest/ODBC/phonetic/W_Wagge(s).mp3"));
         music->play();
         cout<<"Input: "<<flush;
         cin>>input;
    }

}
