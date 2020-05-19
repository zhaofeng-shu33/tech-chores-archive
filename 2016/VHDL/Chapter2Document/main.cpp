#include <iostream>
#include "DblList.h"
using namespace std;
int main(){
  DblList<int> myList;
  int length=100;
  int data;
  for(int i=0;i<length;i++){
      data=i*i;
      myList.Insert(i,data);
  }  
  myList.output();
  CircLinkNode<int>* p=myList.Search(625);
  cout<<p->link->data;
  system("pause");
  return 0;
}   
