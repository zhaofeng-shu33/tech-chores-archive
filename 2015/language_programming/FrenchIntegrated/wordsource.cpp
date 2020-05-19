#include "wordsource.h"
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;
wordSource::wordSource(QWidget *parent) :
    QWidget(parent)
{
   loadTextFile();
   srand((unsigned)time(0));
   total=num*5;
    for(int t=0;t<num;t++){
        word_weight[t]=5;
    }
    word_weight[23]=15;
    word_weight[26]=15;
    word_weight[38]=15;
    word_weight[40]=15;
    word_weight[41]=15;
    word_weight[42]=15;

}
void wordSource::loadTextFile()
 {
     QFile inputFile(":/hiragana.txt");
     inputFile.open(QIODevice::ReadOnly);

     QTextStream in(&inputFile);
     //QString line = in.readAll();
     int i=0,j=0;
     while(!in.atEnd()){
         word[i++]=in.readLine(75);
     }
     inputFile.close();

     QFile inputFile_2(":/katakana.txt");
     inputFile_2.open(QIODevice::ReadOnly);

     QTextStream in_2(&inputFile_2);
     while(!in_2.atEnd()){
         word_2[j++]=in_2.readLine(75);
     }
     inputFile_2.close();
     QFile inputFile_3("D:/C++/language programming/FrenchIntegrated/address.txt");
     inputFile_3.open(QIODevice::ReadOnly);
     i=0;
     QTextStream in_3(&inputFile_3);
     while(!in_3.atEnd()){
         wordAudioAddress[i++]=in_3.readLine(75);
     }
     inputFile_3.close();


 }


double wordSource::distribution_function(int n){//n takes 0~num-1
    int sum=0;
    for(int t=0;t<=n;t++)
        sum+=word_weight[t];
    return sum*1.0/total;
}
int wordSource::generate_random_number(){   
   double tmp;
   for(int t=0;t<5;t++)
        tmp=(rand()%1000)*1.0/1000;
   for(int t=0;t<num-1;t++){
       if( (t==0)&& (tmp<=distribution_function(0)))
          return 0;
       if( (distribution_function(t)<tmp) && (tmp<=distribution_function(t+1)))
          return t+1;
   }
}

