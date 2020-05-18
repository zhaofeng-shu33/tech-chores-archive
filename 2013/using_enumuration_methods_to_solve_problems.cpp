#include <iostream>
using namespace std;
bool LR(char br){
  if(br=='('||br=='['||br=='{'||br=='<')return true;
  return false;
}   
int changeL(char br){
  switch(br){
    case '(': return 0;
    case '[': return 1;
    case '{': return 2;
    case '<': return 3;
    break;
  }  
}  
int changeR(char br){
  switch(br){
    case ')': return 0;
    case ']': return 1;
    case '}': return 2;
    case '>': return 3;
    break;
  }  
}  
char brace_pair(char br){
  switch(br){
    case ')': return '(';
    case ']': return '[';
    case '}': return '{';
    case '>': return '<';
    case '(': return ')';
    case '[': return ']';
    case '{': return '}';
    case '<': return '>'; 
    break;
  }  
}  
  
int main(){
   int braceR[4]={0,0,0,0};//0~( 1~[ 2~{ 3~< 
   int braceL[4]={0,0,0,0};//represents 0~( 1~[ 2~{ 3~< which have not been paried
   char next;
   int num;
   cin>>num;
   bool* output=new bool[num];
   
   int type;
   for(int i=0;i<num;i++){
       cin>>type;
       switch(type){ 
       case 1:
           cin.get(next);cin.get(next);
           if(LR(next))//braceL
                 braceL[changeL(next)]++;
            else //braceR
              if(braceL[changeR(next)]>0){
                //from right to left search the deque s to find the nearest matching element and pair them. 
                braceL[changeR(next)]--;
              }  
              else braceR[changeR(next)]++;
              break;      
        case 2:
           cin.get(next);cin.get(next);
           if(!LR(next))//braceR
            braceR[changeR(next)]++;
             
           else //braceL
              if(braceR[changeL(next)]>0)braceR[changeL(next)]--;
              else braceL[changeL(next)]++;

                 break;
           
         }
       
        if(braceL[0]+braceL[1]+braceL[2]+braceL[3]+braceR[0]+braceR[1]+braceR[2]+braceR[3]==0) output[i]=true;
        else output[i]=false;
   }      
   for(int i=0;i<num;i++)
       if(output[i])cout<<1<<endl;
       else cout<<0<<endl;
      
   system("pause");
   return 0;
}

