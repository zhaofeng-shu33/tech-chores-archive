#include<iostream>
using namespace std;
bool checkPrime(int a);
int main(){
    cout<<2339*3557<<endl;
  while(1){  int n;
    cin>>n;
    bool ToF=checkPrime(n);
    cout<<ToF;
  }  
    char ch;
    cin>>ch;
    return 0;
}
bool checkPrime(int a){
    for(int i=2;i*i<a;i++){
    if ((a%i)==0){
    return 0;
    break;
    }    
    }
    return 1;
}               
