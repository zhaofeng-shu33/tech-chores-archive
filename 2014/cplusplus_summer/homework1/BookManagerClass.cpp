#include<iostream>
#include<fstream>
#include <cstring>
#include<cmath>
using namespace std;
int Great_Common_Divisor(int b1,int b2){   // calculate the great common divisor of two integers
    if(b2==0)
       return b1;
    return Great_Common_Divisor(b2,b1%b2);
    
}  
int Two_Number_LCM(int b1,int b2){         //calculate the least common multiple of two integers
    return (b1*b2)/Great_Common_Divisor(b1,b2);
}    
int Least_Common_Multiple(int* a, int n){  //calculate the least common multiple of a[0], a[1]...a[n-1]
    int tem=1;
    for(int i=0;i<n;i++)
        tem=Two_Number_LCM(tem,a[i]);
    return tem;    
}

bool is_prime(int n){     //Judge whether n is a prime. If so , return true; if not ,return false;
    for(int i=2;i*i<=n;i++)
        if(n%i==0)
           return false;
    return true;
}  

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
   
  private:
      ComicBook* book_pointer;
};
int the_smallest_prime_not_in_A(ComicBook* a, int n){  // This function calculates the smallest prime which does not lie in set A    
                                                       // n signifies the current quantity of books in set A;
                                                       // a is the initial address of books contained in set A;  
       int b[n];                                       // use another array to save the index of every books contained in set A;                 
       for(int i=0;i<n;i++)                                                    
       b[i]=a[i].get();                                                                                                                               
  // calculate the smallest prime does not occur in b[0], b[1],...b[n-1];
       for(int i=2;;i++){ 
        if(is_prime(i)){
           for(int j=0;j<n;j++){
               if(i==b[j])
                  break;
               if(j==n-1){
                 return i;
               }  
           }
        }  
           
        else
           continue; 
      }  

}  

class BookManager: public ComicBook
{
   public:
     BookManager(){Sum=0;}
     friend int count(BookManager & bm);
     int getNum(string name){
         for(int i=0;i<Sum;i++)
             if(name==book[i].getName())
                return book[i].get();
     }
    void add(ComicBook* cd, int n, string names[]){
          book[Sum].set(cd->getName());          
          if(n==0){ 
             if(Sum==0)
                book[0].set(1);
             else{
                int tem=the_smallest_prime_not_in_A(book,Sum);
                book[Sum].set(tem);   
             }  
          
          }
          else{
           int* tem=new int [n];
           for(int i=0;i<n;i++)
               tem[i]=getNum(names[i]);
             
           //calculate the least multiple of n integers.  
           int least=Least_Common_Multiple(tem,n);
           book[Sum].set(least);
          }    
        Sum++;     
     }
     void Output(){
      for(int i=0;i<Sum;i++)
          cout<<book[i].getName()<<'\t'<<book[i].get()<<endl;
     }
       
     private:   
     ComicBook book[200];
     int Sum;  //Sum is the current quantity of books contained in set A
}; 
int count(BookManager & bm){
   return bm.Sum;
}  
int main(){
 BookManager my_bookmanager;
 int m;
 cin>>m;
 for(int i=0;i<m;i++){
      string tem1;
      cin>>tem1;
      int tem2;
      cin>>tem2;
      string* tem3=new string[tem2];
      for(int j=0;j<tem2;j++){
          cin>>tem3[j]; 
      }      
      my_bookmanager.add(new ComicBook(tem1,0),tem2,tem3); 
      delete [] tem3;
  }  
 my_bookmanager.Output();
 cout<<count(my_bookmanager)<<endl;
 return 0;
}   
