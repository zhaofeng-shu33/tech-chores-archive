#include<iostream>
#include<fstream>
using namespace std;
int sub[20][20];
int com(int k,int n){
   if(k==0 || k==n)
      return 1;
   if(sub[k][n]>0)
     return sub[k][n]; 
     
   sub[k][n]=com(k,n-1)+com(k-1,n-1);
     return sub[k][n];
}      
int main(){
    cout<<com(3,6);
    char ch;
    cin>>ch;
    return 0;
}
