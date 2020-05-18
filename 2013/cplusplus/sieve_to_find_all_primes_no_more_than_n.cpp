#include<iostream>
using namespace std;
typedef int* IntArrayPtr;
int DigitCapacity(int n){
    int sum=0;
    for(int i=1;i<=n;i*=10)
        sum++;
        
    return sum;
}    
int main()
{
    //This program finds all primes no more than positive integer n
    int n;
    bool *a;
    cin>>n;
    a=new bool[n+1];
    for(int i=2;i<=n;i++)
        a[i]=1;
    
    for(int i=2;i*i<=n;i++)
        if(a[i]==1)
           for(int j=i+i;j<=n;j+=i)
            a[j]=0;
    for(int i=2;i<n;i++)
        if(a[i]==1)
          cout<<i<<'\t';       
            
             
    char ch;
    cin>>ch;
    return 0;
} 

