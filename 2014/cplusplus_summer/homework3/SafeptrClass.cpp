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
namespace THU{
template <class T>
class SafePtr{
  public:
     SafePtr(){book_pointer=NULL;}
     SafePtr(T* cb):book_pointer(cb){}
     ~SafePtr(){
       delete book_pointer;
    }  
    void reset(T *cb){
      delete book_pointer;
      book_pointer=cb;
    }
    T* get(){
      return book_pointer;
    }  
    T* revoke(){
      ComicBook* temp=book_pointer;
      book_pointer=NULL;
      return temp;
    }  
    T* operator ->(){
      return book_pointer;
    }
    T& operator *(){
      return *book_pointer;
    }
      private:
      T* book_pointer;
};
template <class T>
void swap(SafePtr<T>& a,SafePtr<T>& b){
      SafePtr<T> tem=a;
      a=b;
      b=tem;
}     

}

int main(){
    THU::SafePtr<ComicBook> p1(new ComicBook("Diplomat",2));
    THU::SafePtr<ComicBook> p2(new ComicBook("Zutat",3));
    THU::swap(p1,p2);
    cout<<(*p1).getName(); 
    char ch;
    cin>>ch;
 return 0;
}   
