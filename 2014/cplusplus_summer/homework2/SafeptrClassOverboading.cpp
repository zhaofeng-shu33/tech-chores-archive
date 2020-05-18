#include<iostream>
#include<fstream>
#include <cstring>
#include<cmath>
using namespace std;
class ComicBook{
  public:
    ComicBook(){}//Constructor
    ComicBook(string BookName,int id){book_name=BookName; identifier=id;}// Constructor
    ~ComicBook(){}  //Destructor
    void set(int num){
      identifier=num;
    }
    void set(string bookname){
      book_name=bookname;
    }  
   int get(){
      return identifier;
    }
    string getName(){
      return book_name;
    }      
  private:
     int identifier;
     string book_name;
};
class SafePtr{
  public:
     SafePtr(){book_pointer=NULL;}
     SafePtr(ComicBook* cb):book_pointer(cb){}
     ~SafePtr(){
       cout<<' '<<"existieren"<<endl;
      delete book_pointer;
    }  
    void reset(ComicBook *cb){
      ComicBook* temp=book_pointer;
      delete temp;
      book_pointer=cb;
    }
    ComicBook* get(){
      return book_pointer;
    }  
    ComicBook* revoke(){
      ComicBook* temp=book_pointer;
      book_pointer=NULL;
      return temp;
    }  
    ComicBook* operator ->(){
      return book_pointer;
    }
    ComicBook& operator *(){
      return *book_pointer;
    }   
  private:
      ComicBook* book_pointer;
};


int main(){
    SafePtr p(new ComicBook("Diplomat",2));
    cout<<(*p).getName(); // fragen!
    char ch;
    cin>>ch;
 return 0;
}   
