#include<iostream>
using namespace std;

int main(){
    int n,m=0,sum;
    cin>>n;
    m=n;
    cout<<n<<"=";
    for(int i=2;i<=n;i++){
       
        for(sum=0;m%i==0;sum++)
            m=m/i;
        
        if(sum>=1){
        cout<<i;
        if(sum>1)    
        cout<<"^"<<sum;
        if(m!=1)
        cout<<"*";
    }}
            
            
    char ch;
    cin>>ch;
    return 0;
}    
