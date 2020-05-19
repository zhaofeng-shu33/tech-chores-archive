#include "wordlist.h"
#include <QtCore/QFile>
#include <QtCore/QTextStream>

WordList::WordList()
{
    QFile inputFile("D:/QtTest/50Phonetic/hiragana.txt");
    inputFile.open(QIODevice::ReadOnly);

    QTextStream in(&inputFile);
    //QString line = in.readAll();
    int i=0;
    while(!in.atEnd()){
        word[i++].hiragana=in.readLine(75);
    }
    inputFile.close();

    QFile inputFile_2("D:/QtTest/50Phonetic/katakana.txt");
    inputFile_2.open(QIODevice::ReadOnly);
    i=0;
    QTextStream in_2(&inputFile_2);
    while(!in_2.atEnd()){
        word[i++].katakana=in_2.readLine(75);
    }
    inputFile_2.close();

    QFile inputFile_3("D:/QtTest/50Phonetic/address.txt");
    inputFile_3.open(QIODevice::ReadOnly);
    i=0;
    QTextStream in_3(&inputFile_3);
    while(!in_3.atEnd()){
        word[i++].address=in_3.readLine(75);
    }
    inputFile_3.close();
}
