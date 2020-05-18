#include<iostream>
using namespace std;
int main(){
    int A=0,B=0,C=0,D=0,E=0,F=0;
    for(int i=0;i<=63;i++){
        F=(i&1);
        E=((i>>1)&1);
        D=((i>>2)&1);
        C=((i>>3)&1);
        B=((i>>4)&1);
        A=((i>>5)&1);
                            
                            if((A||B)&&(A&&E||A&&F||E&&F)&&(!A||!D)&&(B&&C||!B&&!C)&&(C&&!D||D&&!C)&&(!D&&!E||D))
                            cout<<A<<B<<C<<D<<E<<F;
    }    
    char ch;
    cin>>ch;
    return 0;
}    
