#include<iostream>
#include<fstream>
#include <cstring>
#include<cmath>
using namespace std;
class function{ //f(x)=x*x;
   public:      // self-defined function by programmer;
     double operator ()(double x){
       return x*x;
     }  
};
class Integral{
   public:
     Integral(function f):F(f){}
     double operator ()(double a, double b, double c){
   double sum1=0,sum2=0,l=b-a,n=1;
     sum2=(F(a)+F(b))*l/2;
   while(fabs(sum2-sum1)>c){
     sum1=sum2;
     sum2/=2;
     l/=2;
     for(int i=0;i<n;i++)
         sum2+=F(a+(2*i+1)*l)*l;
     n*=2;
   
   }  
   return sum2;
   }   
   private:
       function F;   
};    
int main(){
  function f;
  Integral my_integral(f);
  
  cout<<my_integral(0,1,1e-7);
  cout<<endl;
  
  return 0;
}
 
