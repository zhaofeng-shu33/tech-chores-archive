#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
using namespace std;
int get_number_product_root(int n){   
  char a[6];
  sprintf(a, "%d", n);
  int tem=1;
 // cout<<a<<endl;
  for(int i=0;i<6&&a[i]!='\0';i++)
      if(a[i]!='0')
         tem=tem*(int(a[i])-48);
  if(tem<10)
     return tem;
  return get_number_product_root(tem); 
 }      
using namespace std;
int main(){
  while(true){
  char word[20];
  cin>>word;
  int len=strlen(word);
  //cout<<len<<endl;
  len--;
  if(word[len]=='y'){
     word[len]='i';
     word[len+1]='e';
     word[len+2]='s';
     word[len+3]='\0';
  }
  else if(word[len]=='s'||word[len]=='x'||(word[len-1]=='c'&&word[len]=='h')||(word[len-1]=='s'&&word[len]=='h')){
     word[len+1]='e';
     word[len+2]='s';
     word[len+3]='\0';
  }
  else if(word[len]=='o'){
     word[len+1]='e';
     word[len+2]='s';
     word[len+3]='\0';
  }
  else{
     word[len+1]='s';
     word[len+2]='\0';
  }
  cout<<endl<<word;    
  
  }  
  system("pause");
  return 0;
}
 
