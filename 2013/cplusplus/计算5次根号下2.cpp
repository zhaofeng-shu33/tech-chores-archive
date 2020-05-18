//现阶段给出计算2的0.2次方的两种算法，第一种算法很慢。 
#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
 //函数递归。   
double fun(double x){
  return pow(x+1,1.0/3);
}  
void recursion(){
  //方法1：解方程，二分法。 
    double a=1.0,b=1.5;//初始化interval 
    double t0=a,t1=b;//initial test value
    while(fabs(t0-t1)>=0.00001){
        t0=t1;
       t1=fun(t1);
      
    }    
   cout<<t1;
} 
double a=2,helfen[100];
double recursion(int n){
    if(n==1)
      return 2;
    else{
        if(helfen[n]>0)
           return helfen[n];
           
        helfen[n]=0.2*4*recursion(n-1)+0.4/(recursion(n-1)*recursion(n-1)*recursion(n-1)*recursion(n-1));
     
     return helfen[n];
    }   
}        
int main(){
    double a[5];
    a[0]=6.150-3.360;
    a[1]=6.140-3.329;
    a[2]=6.150-3.333;
    a[3]=6.115-3.339;
    a[4]=6.111-3.340;
    a[5]=6.130-3.321;
    double sum=0;
    for(int i=0;i<6;i++){
       sum+=a[i];
       cout<<a[i]<<' ';
     }  
    sum/=6;
    cout<<endl<<sum<<endl;
    cout<<sum*0.1*55<<' '<<endl;

    cout<<endl;
    
    char ch;
    cin>>ch;
    return 0;
}  
