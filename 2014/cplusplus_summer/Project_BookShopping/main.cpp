
#include <iostream>
#include <stdlib.h>
#include "book.h"
using namespace std;

int main(int argc, char *argv[])
{
  BookStore bs;
  (bs.book_list).push_back(new Book("Jane Eyre","Charlotte Bronte",66.5)); 
  (bs.book_list).push_back(new Book("Wuthuring Heights","Emily Bronte",44.5));
  (bs.book_list).push_back(new Book("The Tenant of Wildfell Hall","Anne Bronte",34.5));
  bs.Print();
  cout<<endl;
  ShoppingCart sc; 
  while(true){
    char ch;
    cin>>ch;
    int t;
    cin>>t;
    if(ch=='b'){
       sc.AddBook((bs.book_list)[t]);
       sc.Print();
     }
    if(ch=='r') {
      sc.RemoveBook(t);
      sc.Print();
    } 
  }   
  system("PAUSE");	
  return 0;
}
