#include<iostream>
#include<fstream>
using namespace std;
void nine_up(int n);
void nine_down(int n);
int gcd(int m,int n){
  if(m==0||n==0)
  return m+n; 
if(m>n)
  return gcd(n,m);
  return gcd(m,n-m);
} 
//九连环的步数计算 共341步 
int step=0,subsidiary[10];
int nine(int n){
     if(n==1)
        return 1;
     if(n==2)
        return 2;
     if(subsidiary[n]<0)
        {subsidiary[n]=nine(n-1)+2*nine(n-2)+1; cout<<"卸下前"<<n<<"个环需要"<<subsidiary[n]<<"步"<<endl;}
    return subsidiary[n]; 
 }
//九连环的每一步具体操作实现    
void nine_down(int n){//表示把前n个环全卸下来 
     if(n==1)
        {cout<<"1 down"<<' ';step++;}
     else if(n==2){
        cout<<"2 down"<<' '<<"1 down"<<' ';
        step+=2;
     }
     else{
     nine_down(n-2);
     cout<<n<<" down"<<' ';step++;
     nine_up(n-2);
     nine_down(n-1);
     }    
}
void nine_up(int n){//表示把前n个环全装上去 
    if(n==1){
       cout<<"1 up"<<' '; 
       step++;
    }
    else if(n==2)
       {cout<<"1 up"<<' '<<"2 up"<<' ';step+=2;}
    else{
    nine_up(n-1);
    nine_down(n-2);
    cout<<n<<" up"<<' ';step++;
    nine_up(n-2);
    }    
}      
int main(){
    for(int i=0;i<10;i++)
        subsidiary[i]=-1;
    int ubung=nine(5);
    nine_down(5);
    cout<<endl<<"共有"<<step<<"步"; 
    char ch;
    cin>>ch;
    return 0;
}  
