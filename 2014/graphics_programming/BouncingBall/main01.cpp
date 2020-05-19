#include<iostream>
#include<fstream> 
using namespace std;
int main(int argc, char* argv[]){
  char buf[20];
  ifstream fin;
  fin.open("data.txt");
  double myData;
  while(!fin.eof()){
    fin>>myData;
    cout<<myData<<endl;
  }  
  fin.close();

  
  return 0;
} 
 
