#include<iostream>
using namespace std;
int main(){
    int n,en;
    cin>>n;
    for(int i=1; (i-1)<(n/2);i++){
        int sum=0;
        for(int t=i;sum<n;t++){
            sum+=t;
            en=t;
        }        
        if(sum==n)
        cout<<i<<" "<<en<<endl;
   }         
            
    char ch;
    cin>>ch;
    return 0;
}    
