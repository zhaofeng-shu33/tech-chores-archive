#include <iostream>
#include <cmath>
#include <time.h>
#include <windows.h> 
using namespace std;
double f(double x)
{
  return ( cos(x)+x );
}  
double S(double a, double b, int m){
  double h=(b-a)/m;
  double c=0;
  for(int k=1;k<=m-1;k++)
      c+=f(a+k*h);
  double S=((f(a)+f(b))/2+c)*h;
  return S;
} 
void selectSort(int* a, const int n){
 long start,stop;
     time(&start);
 Sleep(1000);
 for(int i=0;i<n-1;i++){
     int k=i;
     for(int j=i+1;j<n;j++)
         if(a[j]<a[k]) k=j;
     if(i!=k){int temp=a[i];a[i]=a[k];a[k]=temp;}
     
 }  
  time(&stop);
  cout<<endl<<stop-start<<endl; 
}   
void BubbleSort(int* a,int n){
 for(int i=1;i<=n-1;i++){
    for(int j=n-1;j>=i;j--)
        if(a[j-1]>a[j]){int tmp=a[j-1];a[j-1]=a[j];a[j]=tmp;}
 }  
}
template <class T>
class LinearList{
  public:
    LinearList();
    ~LinearList();
    virtual int Size() const=0; // 声明为const 的成员函数不能对对象进行修改; //声明为纯虚函数，没有函数体 
    virtual int Length() const=0;
    virtual int Search(T& x) const=0;
    virtual int Locate(int i) const=0;
    virtual void setData(int i,T& x)=0; 
};  
     
int main(){
  short int b=32768;
  int c;
  long int d;
  int i=0;
  while(i==0){
  }  
  cout<<b<<endl;
  cout<<(b+2)<<endl;
  int a[]={5,3,2,1,4};
  BubbleSort(a,5);
  for(int i=0;i<5;i++)
     cout<<a[i]<<' ';
  
   
  system("pause");
  return 0;
}

