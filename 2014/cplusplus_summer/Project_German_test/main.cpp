#include <iostream>
#include <stdlib.h>
#include "test.h"
#include <vector>
using namespace std;
  
int main(int argc, char *argv[])
{
  string b[12];
  string a1[10],a2[10];
  Question my[10];
  a1[0]=" Wir brauchen ___ Haus. ";
  a2[0]="B";
  b[0]="keines";b[1]="kein";b[2]="nicht";b[3]="nichts";
  a1[1]=" Er hat einen Kaffee ___. ";
  a2[1]="D";
  b[4]="bestellen";b[5]="gebestellen";b[6]="begestellt";b[7]="bestellt";
  my[0].special.Set_Content(a1[0],b);
  my[0].Set_Question(a2[0]);
  my[1].special.Set_Content(a1[1],b+4);
  my[1].Set_Question(a2[1]);
  a1[2]=" Er dankt ___ meine Hilfe. ";
  a2[2]="C";
  b[8]="mich fuer";b[9]="mir an";b[10]="mir fuer";b[11]="mich an";
  my[2].special.Set_Content(a1[2],b+8);
  my[2].Set_Question(a2[2]);
  
       cout<<'\t'<<'\t'<<'\t'<<"A test for Deutsch I"<<endl<<"   This test consists of three questions. ";
       cout<<"and they are all single choices "<<endl;
       cout<<"   After you submit your answer, you will be rewarded or punished according to your right rate."<<endl;
       cout<<"   Firstly, dear user, please type in your name"<<endl; 
       cout<<"   (After your input,Press 'Enter' to go on):  ";
   string name;
   cin>>name;
   User my_user(name);
       cout<<endl<<"   Dear "<<my_user.name<<", the following is the first question."<<endl;
   for(int i=0;i<3;i++){
       my[i].special.Print(i+1);
       cin>>my[i].special.user_answer;
       if(my[i].special.user_answer==my[i].answer){
         my[i].state=true; 
       }  
      
       my_user.q[i]=&(my[i].special);
       char ch='r';
       while(true){
           if(i<2) cout<<"   Now you can choose either to go on answering questions(Input 'n')"<<endl;
           if(i==2)cout<<"   Now you have answered all the questions.\n"<<"you can choose either to submit your answer(Input 'n')"<<endl;
             cout<<"   or alter your answers(Input 'r')"<<endl;
            cout<<"   or see your answering state(Input 's')"<<endl;
           if(i==0) cout<<"   (pay attention not to input two ' on two sides of the letter.)"<<endl; 
            cin>>ch;
            { if(ch=='n')
                 break;
              else if(ch=='s')
               my_user.see_state();
              else if(ch=='r'){
               cout<<"Please input the question number of the question"<<endl;
               cout<<"that you want to deal with again: "<<endl;
               int tem1;
               cin>>tem1;
               cout<<"This is ";my[tem1-1].special.Print(tem1);
               cin>>my[i].special.user_answer;
               if(my[i].special.user_answer==my[i].answer)
                   my[tem1-1].state=true;         
              }else
              cout<<" Illegal Input! Input again! "<<endl;
            }  
            
        }              
            
   }
    cout<<endl; int tem2=0;
   //cout<<my[0].state<<' '<<my[1].state<<' '<<my[2].state;
   for(int i=0;i<3;i++){
       cout<<"Your answer to Question "<<i+1<<" is "<<my[i].special.user_answer<<" which is ";
       if(my[i].state){
          cout<<"right";
          tem2++;
        }else{
          cout<<"wrong. The right answer is "<<my[i].answer;
          
        }  
        cout<<endl;
   }
   cout<<endl;
   switch (tem2){
     case 3:
     cout<<"  Congratulations! Your are excellent German learner."<<endl;
     cout<<"  By the way, Dear "<<my_user.name<<", do you think that \n";
     cout<<"  Language is an amazying thing which can be applied almost everywhere?\n";
     cout<<"  To add one point, The designer of the program will give you reward\n";
     cout<<"  for your uncommon behaviour in this small test\n";
     cout<<"  For more information about the reward please contact free-wind through Email.";
     break;
     case 2:
     cout<<"  You are pretty good in this small test.\n";
     cout<<"  By paying a little more effort can you learn German well enough.\n";
     cout<<"  Let us use 'Uebungen machen Meister' as mutual encouragement.\n";
     break;
     case 1:
     cout<<"  It seems you do not behave well in this small test\n";
     cout<<"  You should pay much effort to catch up with others if you want to go on learning German.\n";
     cout<<"  Let us use 'Gib niemals auf' (never give up ) as mutual encouragement.\n";
     break;
     case 0:
     cout<<"  You have probably not learned German.\n";
     cout<<"  You are not encouraged to go on learning German because of your bad behaviour in this small test.\n";
     cout<<"  According to instructions listed on the top of the program, you should be punished.\n";
     cout<<"  For more information about the reward please contact free-wind through Email.";
     break;
   }
   cout<<endl<<endl<<endl<<"At last, Hope you enjoy this small program."<<endl;
   cout<<'\t'<<'\t'<<'\t'<<'\t'<<"free wind";            
   
     
  
  
  //}    
  system("PAUSE");	
  return 0;
}
