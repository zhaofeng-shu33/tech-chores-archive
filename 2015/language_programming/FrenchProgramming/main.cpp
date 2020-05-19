#include <QtCore/QCoreApplication>
#include<iostream>
#include<fstream>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<cctype>
using namespace std;
struct word{
   string form;
   string type;
};
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    word French[10];
     int i=0;
     ifstream fin;
     fin.open(":/words.txt");
     if(fin.fail())
        cout<<"Input file opening failed.\n";
     char symbol;
     string str,str2;
     while(fin>>str){
       fin.get(symbol);
       //cout<<"   what?"<<symbol<<endl;
       while(symbol!='\n'){
            fin.putback(symbol);
            fin>>str2;
            str=str+' ';
            str=str+str2;
            fin.get(symbol);
       }
       //fin.putback(symbol);
       French[i].form=str;
       i++;
     }
     cout<<i<<endl;
     for(int t=0;t<i;t++)
         cout<<French[t].form<<endl;
     fin.close();
     while(1){
     cout<<"Input French words: ";
     cin>>French[i].form;
     cout<<French[i].form<<endl;
     }
    return a.exec();
}
