#include<iostream>
#include<fstream>
using namespace std;
struct ProgramList{
  char name[20];
  int time;
  ProgramList* next;
};
ProgramList* head;
ProgramList* Creat(){
   ProgramList* p=NULL;
   ProgramList* q=NULL;
   head=NULL;
   int Time;
   cin>>Time;
   while(Time!=0){
      p=new ProgramList;
      p->time=Time;
      cin>>p->name;
      if(head==NULL)
         head=p;
      else
         q->next=p;
      q=p;
      cin>>Time;
   }
   if(head!=NULL)
      q->next=NULL;
   return head;   
}
void Display(ProgramList* head){
   cout<<endl;
   while(head!=NULL){
        cout<<head->name<<' '<<head->time<<endl;
        head=head->next;
   }  
}      
void insert(ProgramList* & head, ProgramList* Node){
   if(head==NULL){
      head=Node;
      return;
   }
   if(Node->time<=head->time){
      Node->next=head;
      head=Node;
      return;
   }
   ProgramList *r=head,*q=head->next;
   while(q!=NULL){
      if(q->time<Node->time){
         r=q;
         q=q->next;
      }
      else
         break;
   }
   r->next=Node;
   Node->next=q;
}      
void del(ProgramList* head,int num){
  if(head==NULL)
     return;
  ProgramList *p=head,*q;
  if(p->time==num){
     head=p->next;
     delete p;
     return;
  }
  q=p->next;
  while(q!=NULL){
    if(q->time==num){
       p->next=q->next;
       delete q;
       return;
    }
    if(q->time>num)
       return;
    p=q;
    q=q->next;
  }      
}               

    
int main(){
  while(true){
  Display(Creat());
  ProgramList tem={"schrecklich",13,NULL};
  ProgramList* Node=&tem;
  del(head,13);
  Display(head);
  cout<<"\n\n\n";
  }  
  system("pause");
  return 0;
}
 
