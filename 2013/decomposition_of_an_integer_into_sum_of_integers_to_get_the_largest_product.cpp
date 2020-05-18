#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int fastFind(string pattern, string target, int k, int next[]){
//从 k 开始寻找 pat 在 this 串中匹配的位置。若找
//到，函数返回 pat 在 this 串中开始位置，否则函
//数返回-1。数组next[ ] 存放 pat 的next[j] 值。
     int posP = 0,  posT = k;	//两个串的扫描指针
     int lengthP=pattern.length();         //模式串长度
     int lengthT=target.length();               //目标串长度
     //cout<<pattern.length()<<' '<<target.length()<<endl;
     while(posP<lengthP && posT < lengthT){
 	      	if (posP == -1||pattern[posP] == target[posT]) 
               { posP++;  posT++; }          //对应字符匹配
          else posP = next[posP];   //求pat下趟比较位置
          cout<<posP<<' '<<posT<<endl;  
     }  
     if (posP<lengthP) return -1;	//匹配失败
     else return posT-lengthP;		//匹配成功
}

int main(){
  int next[]={-1,0,1};
  string target("ababbaabaa");
  string pattern("aab");
  cout<<"Find? "<<fastFind(pattern,target,0,next);
  
  return 0;
}
 
