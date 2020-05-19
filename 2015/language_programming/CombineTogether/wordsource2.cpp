#include "wordsource2.h"
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <QTextCodec>
#include <QMessageBox>
int cnt2=0;
using namespace std;

wordSource2::wordSource2(QWidget *parent) :
    QWidget(parent)
{
    loadTextFile();
    srand((unsigned)time(0));
    total=num2*5;
     for(int t=0;t<num2;t++){
         word_weight[t]=5;
     }

}
void wordSource2::loadTextFile()
 {
     int i=0,j=0;
     QFile inputFile(":/ConjugaisonAnswer.txt"); //target language
     inputFile.open(QIODevice::ReadOnly);
     QTextStream in(&inputFile);
     while(!in.atEnd()){
         word[i++]=in.readLine(75);
     }
     i=0;
     QFile inputFile1(":/ConjugaisonPasse.txt"); //target language
     inputFile1.open(QIODevice::ReadOnly);
     QTextStream in1(&inputFile1);
     while(!in1.atEnd()){
         wordp[i++]=in1.readLine(75);
     }

     QFile inputFile_2(":/Conjugaison.txt"); //translated meaning
     inputFile_2.open(QIODevice::ReadOnly);
     QTextStream in_2(&inputFile_2);
     while(!in_2.atEnd()){
         word_2[j++]=in_2.readLine(75);
     }
     cnt2=j;
     //cout<<cnt2;
     inputFile.close();
     inputFile1.close();
     inputFile_2.close();

   /*  QMessageBox msgBox;
     msgBox.setText(word[4]);
     msgBox.exec();
     */
 }


double wordSource2::distribution_function(int n){//n takes 0~cnt2-1
    int sum=0;
    for(int t=0;t<=n;t++)
        sum+=word_weight[t];
    return sum*1.0/total;
}
int wordSource2::generate_random_number(){
   double tmp;
   for(int t=0;t<5;t++)
        tmp=(rand()%1000)*1.0/1000;
   for(int t=0;t<cnt2-1;t++){
       if(tmp<=distribution_function(0))
          return 0;
       if((distribution_function(t)<tmp)&&(tmp<=distribution_function(t+1)))
          return t+1;
   }
}

