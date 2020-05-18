#include<iostream>
#include<fstream>
#include <cstring>
#include<cmath>
using namespace std;
class Scale{
  public:
      Scale(int m):Position(m){n10=0;}
      bool fromDec(unsigned long long int t){ //dec:decimal
           n10=t;
           num=0;
           while(t>=Position){
                 a[num++]=t%Position;
                 t=t/Position;
                 if(num>49)
                    return false;
           }
           a[num]=t;
           return true;
      }
      unsigned long long int toDec(){
        return n10;
      } 
      void print(){
        if(num==0)
           cout<<'0';
        for(int i=num;i>=0;i--){
            if(a[i]<=9)
            cout<<a[i];
            if(a[i]>9)
            cout<<(char)(a[i]+55);
        }
      }  
      void clear(){
           n10=0;
           for(int i=0;i<=num;i++)
               a[i]=0;
            num=0;
      }
      bool operator ==(const Scale &RHS) const{
          if(n10==RHS.n10)
             return true;
          return false;
      }  
      bool operator <(const Scale &RHS) const{
          if(n10<RHS.n10)
             return true;
          return false;
      }
      bool operator <=(const Scale &RHS) const{
          if(n10<=RHS.n10)
             return true;
          return false;
      }
      Scale operator +(const Scale &RHS){
           Scale tem(0);
           tem.n10=n10+RHS.n10;    
           return tem;
      }               
      Scale& operator =(const Scale &RHS){
           n10=RHS.n10;
           return *this;
      }  
  protected:
      int Position;// 2~16
      unsigned long long int n10; // save the number in decimal notation.
      int a[50];
      int num;
         
}; 
class Factoradic: public Scale{
  public:
     Factoradic():Scale(0){}
     bool fromDec(unsigned long long int t){ // to factorial notation
         n10=t;
         num=0;
         int n2=2;
         unsigned long long int tem=1;
         while(tem<t)
              tem*=(n2++);
         tem/=(--n2);
         while(tem>=1&&n2>=2){
           a[num++]=t/tem;
           t=t%tem;
           tem/=(--n2);
         }
         num--;  
     }
     void print(){
        if(num==0)
           cout<<'0';
        for(int i=0;i<=num;i++){
            if(a[i]<=9)
            cout<<a[i];
            if(a[i]>9)
            cout<<(char)(a[i]+55);
        }
      }  
     
    
};   
int main(){
  Scale my_scale(8),your_scale(8);
  my_scale.fromDec(719);
  your_scale.fromDec(123);
  my_scale=(my_scale+your_scale);
  cout<<endl<<my_scale.toDec();
  cout<<endl;
  return 0;
}
 
