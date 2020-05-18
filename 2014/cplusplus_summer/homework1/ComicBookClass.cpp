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
int main(){
 
 return 0;
}   
