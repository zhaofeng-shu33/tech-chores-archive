#include<iostream>
using namespace std;
int main(){
    char good='A';
    for(char i= good;i<='D';i++){
        if((i!='A')+(i=='C')+(i=='D')+(i!='D')==3)
        cout<<i;
    }    
    char ch;
    cin>>ch;
    return 0;
}    
