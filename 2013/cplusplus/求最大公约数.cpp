#include<iostream>

using namespace std;
void swap(int &a,int& b){
    int temp=a;
    a=b;
    b=temp;
}
//要用带余除法。
//int nu=0; 
int p[20],r[20],t=0;
int gcd(int a,int b){
    if(a<b)
      swap(a,b);
   // cout<<"The great common divisor is "<<m;
    {if(a%b==0){
      return b;
     }    
    else{
       p[t]=a/b;
       r[t]=a%b;
       t++;
       return gcd(b,a%b);
    }}    

  //  else
  //     return gcd(b,q[nu-1],p,q);
}    
int main(){
   // int* p ,*q;
   // int a=1;
  //  p[0]=1;//不能把一个指针指向一个常量吗？ 
  //  cout<<p[0];//在两个程序中一个会break down,另一个正常，指针有bug? 
   // cout<<gcd(48,24,p,q);
   //cout<<gcd(48,36);
   int a=13*17,b=11*13;
  // cout<<"Please input two positive integers";
 //  cin>>a>>b;
   int c=gcd(a,b);
   if(a<b)
      swap(a,b);
   int u[20],v[20];

   
   if(t==0){
     
     cout<<c<<'='<<0<<'*'<<a<<'+'<<1<<'*'<<b<<endl; 
   }
   u[0]=1;v[0]=-p[0];
   if(t==1){
     cout<<c<<'='<<u[0]<<'*'<<a<<'+'<<(u[0])<<'*'<<b<<endl; 
   }        
   u[1]=-1*p[1]*u[0];v[1]=-1*p[1]*v[0]+1;//cout<<p[1]<<' '<<v[0]<<' '<<v[1];        
   if(t==2){ 
     cout<<c<<'='<<u[1]<<'*'<<a<<'+'<<(v[1])<<'*'<<b<<endl; 
   }
   int s=2;
   for(;t>2;t--){
      u[s]=-1*u[s-1]*p[s]+u[s-2];
      v[s]=-1*v[s-1]*p[s]+v[s-2];
      s++;
   } 
   if(t==2){ 
     cout<<c<<'='<<u[s-1]<<'*'<<a<<'+'<<(v[s-1])<<'*'<<b<<endl; 
   }
        
    char ch;
    cin>>ch;
    return 0;
}
