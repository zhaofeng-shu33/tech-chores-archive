#ifndef _BOOK_H_
#define _BOOK_H_
#include<string>
#include<vector>
using namespace std;
struct Book{
   string name,author;
   double price;
   Book(string n1,string n2,double p);
   void Print();
}; 
struct BookStore{
  vector<Book*> book_list;
  void Print();
};   
struct ShoppingCart{
  vector<Book*> book_list;
  double total_number,total_price;

  ShoppingCart();
  void AddBook(Book* b);
  void RemoveBook(int a);
  void Print();
};  
#endif
