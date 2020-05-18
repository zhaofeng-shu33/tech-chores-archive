#include<iostream>
using namespace std;
int DigitCapacity(int n){
    int sum=0;
    for(int i=1;i<=n;i*=10)
        sum++;
        
    return sum;
}    
int NumberTwo(int n){
    int sum=0,nre=n; 
    int digit=DigitCapacity(n);
    for(int i=1;i<=n;i++){
         int num=nre%10;
         if(num==2)
         sum++;
         nre /=10;
     }   
     return sum;
}     
    
int main(){
    int sum=0,L,R;
    cin>>L>>R;
    for(int i=L;i<=R;i++)
       sum+=(NumberTwo(i));
    cout<<sum;   
    char ch;
    cin>>ch;
    return 0;
}    
