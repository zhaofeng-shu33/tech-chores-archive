#include<iostream>
void swap(int*,int*);
using namespace std;
int main()
{
    int x=3,y=5;
    cout<<x<<" "<<y<<endl;
    swap(&x,&y);
    cout<<x<<" "<<y;
                    
    char ch;
    cin>>ch;
    return 0;
} 
void swap(int*a,int*b){
    int t=*a;
    *a=*b;
    *b=t;
}    
