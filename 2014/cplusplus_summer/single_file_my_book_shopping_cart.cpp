#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;
struct Book{
   string name,author;
   double price;
   Book(string n1,string n2,double p);
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

Book::Book(string n1,string n2,double p):name(n1),author(n2),price(p){}
void Book::Print(){
     cout<<name<<' '<<author<<' '<<price<<" RMB"<<endl;
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
        cout<<(i+1)<<':';
        book_list[i]->Print();
    }
    cout<<"Total price is "<<total_price<<endl;  
}
int main(){
  
vector<Book*> BookStore(3);
 
 BookStore[0]=new Book("Jane Eyre","Charlotte Bronte",66.5); 
 BookStore[1]=new Book("Wuthuring Heights","Emily Bronte",44.5);
 BookStore[2]=new Book("The Tenant of Wildfell Hall","Anne Bronte",34.5);
 
 ShoppingCart sc;
 sc.AddBook(BookStore[0]);
 sc.AddBook(BookStore[1]);
 sc.Print();
 sc.RemoveBook(1);
 sc.Print();

 system("pause");
 return 0;
}  
