#include<iostream>
#include<fstream>
#include<cstring>
#include<wchar.h>
using namespace std;
int main() {
 ifstream fin("verbOriginal.txt");
 ofstream fout("verbOriginal2.txt");
 string str;
 while(!fin.eof()){
 fin>>str;
 fout<<str;
 for(int i=0;i<6;i++)
   fout<<endl;
 } 
 fin.close();
 fout.close();/*
 string str;
 ifstream fin1("verbInfinitive2.txt");
 ofstream fout1("verbInfinitive4.txt");
 int i=0;
 while(fin1>>str){
 i++;
 fout1<<str;
 fout1<<endl;
 } 
 cout<<i<<endl;
 fin1.close();
 fout1.close();
 */
 

    return 0;
}

