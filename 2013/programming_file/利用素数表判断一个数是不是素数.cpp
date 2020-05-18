#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream fin("Prime.txt");
    int p=-1,n;
    cin>>n;
    while(n>p && !fin.eof()   ){  // end of file 该函数返回 一个bool 值 true 表示文件结束
   fin>>p;
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
