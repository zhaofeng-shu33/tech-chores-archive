#include "Two.h"
#include<iostream>
using namespace std;
// 命名空间练习
void Say(){
  cout<<"Global"<<endl;
}  
int main(){
  Say();
  MyNameSpace::Say();
  MyPrintSpace::Say();
  
  return 0;
}  
