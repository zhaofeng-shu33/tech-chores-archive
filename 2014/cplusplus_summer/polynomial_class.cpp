#include<iostream>
#include<fstream>
#include <cstring>
#include<cmath>
using namespace std;
class polynomial{
  public:
    polynomial(){max_degree=0;}
     void set_poly(int a){
       max_degree=a;
       for(int i=0;i<a;i++)
           cin>>poly_link[i];
     }
      
     double operator ()(double a){
       double sum=0;
       for(int i=0;i<max_degree;i++)
           sum+=poly_link[i]*pow(a,i);
       return sum;
     }    
  private:
    double* poly_link;
    int max_degree;
};  
int main(){
  polynomial f;
  f.set_poly(3);
  cout<<f(1);
  
  return 0;
}
 
