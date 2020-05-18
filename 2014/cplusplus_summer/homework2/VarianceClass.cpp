#include<iostream>
#include<fstream>
#include <cstring>
#include<cmath>
using namespace std;
class Variance{
public:
   template<class T>
   double operator () (T a[],int number_of_a){
   double average=0,tem=0;
   for(int i=0;i<number_of_a;i++)
       average+=a[i];
   average/=(double)number_of_a; 
   for(int i=0;i<number_of_a;i++){
       tem+=(a[i]-average)*(a[i]-average);
      // cout<<tem<<' ';    
   }
   
   tem/=(double)number_of_a;
   return tem;
   }
   template<class T>
   double operator () (T a1,T a2,T a3){
   double average=(a1+a2+a3)/3,tem=0; 
       tem+=(a1-average)*(a1-average)+(a2-average)*(a2-average)+(a3-average)*(a3-average);    
   
   
   tem/=3;
   return tem;
   }  
 
};  
int main(){
  Variance my_variance;
  double a[]={1,2,3,4};
  cout<<my_variance(a,4);
  return 0;
}
 
