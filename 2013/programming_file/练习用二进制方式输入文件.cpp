#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ofstream fout("PrimeBinary.txt",ios::binary);
    int n=1000;
bool isPrime[n+1];
for(int i=1;i<=n;i++)
    isPrime[i]=true;

for(int i=2;i*i<n;i++)
  if(isPrime[i])
    for(int j=i+i;j<=n;j+=i)
        isPrime[j]=false;
for(int i=2;i<=n;i++)
   if(isPrime[i])
     fout.write( (char*)&i,4);
     fout.close(); 
    char ch;
    cin>>ch;
    return 0;
}  
