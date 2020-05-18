#include "book.h"
#include <iostream>
#include<iomanip>
using namespace std;
Book::Book(string n1,string n2,double p):name(n1),author(n2),price(p){}
void Book::Print(){
     cout<<name<<'\t'<<author<<'\t'<<price<<" RMB"<<endl;
}  
void BookStore::Print(){
  int j=0;
  for(vector<Book*>::iterator i=book_list.begin();i!=book_list.end();i++){
      cout<<(j++)<<": ";(*i)->Print();
  }  
      
}  
ShoppingCart::ShoppingCart():total_number(0),total_price(0){}
void ShoppingCart::AddBook(Book* b){
    book_list.push_back(b);
    total_number++;
    total_price+=b->price;
}
void ShoppingCart::RemoveBook(int a){
    total_price-=book_list[a]->price;
    book_list.erase( book_list.begin()+a );
    total_number--;
}  
void ShoppingCart::Print(){
    for(int i=0;i<total_number;i++){
        cout<<(i)<<':';
        book_list[i]->Print();
    }
    cout<<"Total price is "<<total_price<<endl;  
}
