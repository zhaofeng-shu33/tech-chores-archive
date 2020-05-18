#include<iostream>
#include "test.h"
using namespace std;
//Question::Question(){}
void Question::Set_Question(string b){answer=b;state=0;}

void Question::give_answer(string in){
  if(in==answer)
     state=0;
}
void Content::Set_Content(string a1, string b[]){
  Sentence=a1;if_choice=1;
  for(int i=0;i<4;i++)
      choice[i]=b[i];
}
void Content::Set_Content(string a1, string a2){
   Sentence=a1;if_choice=0;
   attach_info=a2;
}      
void Content::Print(int i){
  cout<<"Question "<<i<<": "<<Sentence<<endl;
  if(if_choice)
     for(int i=0;i<4;i++)
         cout<<(char)(65+i)<<' '<<choice[i]<<endl;
  else
      cout<<attach_info<<endl;
  cout<<"Input your answer: ";
}
User::User(string n){
  name=n;
  for(int i=0;i<10;i++)
     q[i]=NULL;
}
void User::see_state(){
  if(q[2]==NULL)
  cout<<"you have not answered question ";
  for(int i=1;i<3;i++)
      if(q[i]==NULL)
         cout<<i+1<<',';
  for(int i=0;i<3;i++)
      if(q[i]!=NULL)
  cout<<"your answer to question "<<i+1<<" is "<<q[i]->user_answer<<endl; 
  cout<<"Come on "<<name<<'!'<<endl; 
}    
