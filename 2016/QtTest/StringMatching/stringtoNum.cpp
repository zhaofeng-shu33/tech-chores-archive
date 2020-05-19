#include <windows.h>
#include <boost/lexical_cast.hpp>
#include <boost/tokenizer.hpp>
#include <string>
#include <iostream>
#include <fstream>
void Initialize(){
    using namespace std;
    using namespace boost;
    char data[1024];
    ifstream fin("testData.txt");
    if(fin.is_open()){
      fin.seekg (0, fin.end);
      int length = fin.tellg();
      fin.seekg (0, fin.beg);
      fin.read(data,length);
      data[length-4]='\0';
      fin.close();  
    }
    string s(data);
    char_separator<char> sep(" \n");
    tokenizer<char_separator<char> > tok(s,sep);
    for(tokenizer<char_separator<char> >::iterator beg=tok.begin(); beg!=tok.end();++beg){
       double num=lexical_cast<double>(*beg);
       m<<num;
    }  
}
