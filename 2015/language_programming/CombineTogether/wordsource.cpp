#include "wordsource.h"
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <QTextCodec>
#include <QMessageBox>
int cnt=0;
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

}
void wordSource::loadTextFile()
 {
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));

     QFile inputFile(":/words1.txt"); //target language
     inputFile.open(QIODevice::ReadOnly);
     QTextStream in(&inputFile);
     int i=0,j=0;
     while(!in.atEnd()){
         word[i++]=in.readLine(75);
     }
     cnt=i;

     QFile inputFile_2(":/words.txt"); //translated meaning
     inputFile_2.open(QIODevice::ReadOnly);
     QTextStream in_2(&inputFile_2);
     while(!in_2.atEnd()){
         word_2[j++]=in_2.readLine(75);
     }
     inputFile.close();
     inputFile_2.close();

   /*  QMessageBox msgBox;
     msgBox.setText(word[4]);
     msgBox.exec();
     */
 }


double wordSource::distribution_function(int n){//n takes 0~cnt-1
    int sum=0;
    for(int t=0;t<=n;t++)
        sum+=word_weight[t];
    return sum*1.0/total;
}
int wordSource::generate_random_number(){   
   double tmp;
   for(int t=0;t<5;t++)
        tmp=(rand()%1000)*1.0/1000;
   for(int t=0;t<cnt-1;t++){
       if(tmp<=distribution_function(0))
          return 0;
       if((distribution_function(t)<tmp)&&(tmp<=distribution_function(t+1)))
          return t+1;
   }
}

