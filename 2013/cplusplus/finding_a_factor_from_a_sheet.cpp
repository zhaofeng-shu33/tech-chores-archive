#include<iostream>
using namespace std;
int main()
{
    int N,m;
    cin>>N;
    for(int i=1;i<N;i++){
            if(((i-1)*i<(2*N))&&((i+1)*i>=(2*N))){
            m=i;
           cout<<m<<" ";
            break;
            }
    }
    int t=N-((m-1)*m)/2;
    cout<<t<<" ";
    if(m%2==0)
    cout<<t<<"/"<<m+1-t;
    else
    cout<<m+1-t<<"/"<<t;
    char ch;
    cin>>ch;        
                      
    return 0;
} 

