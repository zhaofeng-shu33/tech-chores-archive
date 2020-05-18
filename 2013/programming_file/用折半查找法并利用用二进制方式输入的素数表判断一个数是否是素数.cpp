#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream fin("PrimeBinary.txt",ios::binary);
    int p=-1,n,s=0,e;
    fin.seekg(0,ios::end);
    e=fin.tellg()/4 -1;
    cin>>n;
    while(e>=s){
         int m= (s+e)/2;
         fin.seekg(m*4,ios::beg);
         fin.read((char*)&p,4);
         cout<<p<<' ';
         if(p==n) break;
         else if(p>n)
         e=m-1;
         else
         s=m+1;     
   }
if(n==p)
  cout<<"是素数"<<endl;
else
  cout<<"不是素数"<<endl;
fin.close();
    char ch;
    cin>>ch;
    return 0;
}  
