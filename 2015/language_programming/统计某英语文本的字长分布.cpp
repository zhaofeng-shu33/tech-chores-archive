#include<iostream>
#include<fstream>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<cctype>
using namespace std;
int hypenation_adjustment(string s){
    int sl=s.length();
     int location=s.find('-',0);//�ų����ַ���Ӱ�� 
         if(location>=0&&location<sl){
            sl--;
             int location=s.find('-',location);
           if(location>=0&&location<sl)
            sl--;
          }  
    return sl;
}          
int main(){
  int a[3000];
  int length_of_words[21];
  for(int i=0;i<15;i++)
      length_of_words[i]=0;
  int cnt=0;
  ifstream fin("tokkenization.txt");
  ofstream  fout("statistical result.txt",ios::app); 
   string punct(",.:;?!'\"()"),ns;
  int pl=punct.length();
  
  string s;
  
  while(fin>>s){
  int sl=s.length();
  for(int i=0;i<pl;i++){
    string a_char=punct.substr(i,1);
    int location=s.find(a_char,0);
      if(location>=0&&location<sl){
           length_of_words[location]++;
           if(location!=0){
           a[cnt++]=location;  if(location==2)cout<<s<<' ';/*cout<<"1 way: "<<a[cnt-1]<<' '<<s<<"  "<<endl;*/}
           if(sl-1-location!=0){
              length_of_words[sl-1-location]++;if(sl-1-location==2)cout<<s<<' ';
           a[cnt++]=sl-1-location; /*cout<<"2 way: "<<a[cnt-1]<<' '<<s<<"  "<<endl;*/ } 
           break;
      }  
          
     
      if(i==pl-1){
        if(sl==2)cout<<s<<' ';
        // sl=hypenation_adjustment(s); 
        //Ĭ�����ַ��൱��һ����Ч����ĸ����Ϊ�ų���Ӱ����㷨�ܸ��ӡ� 
         length_of_words[sl]++;
         a[cnt++]=sl;  //cout<<"3 way: "<<a[cnt-1]<<' '<<s<<"  "<<endl;
      }  
 
  }   
  s="";ns="";
  }
  fout<<"����ͳ��: "<<cnt<<endl; 
  int sum=0,ave=0;
   for(int i=1;i<15;i++){
      if(length_of_words[i]!=0){
      fout<<"����Ϊ"<<i<<"�ĵ��ʹ�����"<<length_of_words[i]<<"��,";
      fout<<"��ռ�ܴ����ı���Ϊ "<<1.0*length_of_words[i]/cnt<<endl; 
      sum+=length_of_words[i];
      ave+=length_of_words[i]*i;
      }  
  }
  fout<<"�����������ӵ� "<<endl<<ave*1.0/cnt<<endl<<endl;  
  
  fin.close();
  fout.close();
  
  return 0;
}   
