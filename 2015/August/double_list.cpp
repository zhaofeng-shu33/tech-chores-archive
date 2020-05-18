#include <iostream>
#include <cmath>
using namespace std;

struct group{
  string name;
  int birthdate;
  group* next;
};group* head=NULL;

group* Creat(){
  group* p=NULL,*q=NULL;
 // cout<<"give birthdate of the first person: ";
  int tem=0;
  //cin>>tem;
  for(int i=1;i<4;i++){
    p=new group;
    p->birthdate=(++tem);
    //cout<<"give name of the "<<i<<" person: ";
    //cin>>p->name;
    if(head==NULL)
       head=p;
    else
       q->next=p;
       
    q=p;
    q->next=NULL;
   // if(p!=NULL)cout<<q->name<<endl;
    //cout<<"give birthdate of the "<<i+1<<" person: ";
    //cin>>tem;
  }
  return head;   
}

void show(group* head){
  int i=1;
  for(int i=1;head!=NULL;i++){
      //cout<<"The name of the "<<i<<" person is: \n";
      //cout<<head->name<<endl;
      cout<<"The birthdate of the "<<i<<" person is:  ";
      cout<<head->birthdate<<endl;
      head=head->next;
  }
  #include <iostream>
#include <cmath>
using namespace std;

struct group{
  string name;
  int birthdate;
  group* next;
};group* head=NULL;

group* Creat(){
  group* p=NULL,*q=NULL;
  cout<<"give birthdate of the  person: ";
  int tem;
  cin>>tem;
  for(;tem!=0;){
    p=new group;
    p->birthdate=tem;
    cout<<"give name of the person: ";
    cin>>p->name;
    if(head==NULL)
       head=p;
    else
       q->next=p;
       
    q=p;
    q->next=NULL;
   // if(p!=NULL)cout<<q->name<<endl;
    cout<<"give birthdate of the person: ";
    cin>>tem;
  }
  return head;   
}

void show(group* head){
  int i=1;
  if(head==NULL)
     cout<<"NONE\n";
  for(int i=1;head!=NULL;i++){
      cout<<"The name of the "<<i<<" person is: ";
      cout<<head->name<<endl;
      cout<<"The birthdate of the "<<i<<" person is: ";
      cout<<head->birthdate<<endl;
      head=head->next;
  }
  
}           
void Insert(group* head,int n){//在第i个节点后插入所需之新节点。 
     group* p=head;
     group* q=new group;
     cout<<"Give the name of the person: ";
     cin>>q->name;
     cout<<"Give birthdate of the person: ";
     cin>>q->birthdate;
     if(n==0||head==NULL)
       return;
     for(int i=0;i<n-1;i++)
          p=p->next;
          
     q->next=p->next;
     p->next=q;
}
void Delete(group*& head,int n){
     group* p=head,*q=NULL;
     if(n==0||head==NULL)
       return;
     if(n==1){
       head=p->next;
       delete p;  
     return;
     }  
     for(int i=0;i<n-2;i++)
         p=p->next;
     q=p;
     q->next=p->next->next;
     //delete p->next;
}    
int main(){
 group* head=Creat();
 show(head);
 int j=0,j1,j2;
 while(1){
 cout<<"now determine what to do: 1 represents insert and 2 represents delete, 3 represents print\n";
 cin>>j;
  switch(j){
    case 1:
      cout<<"Give the number you would like to insert: ";
      cin>>j2;
      Insert(head,j2);
      break;
    case 2:
      cout<<"Give the number you would like to delete: ";
      cin>>j1;
      Delete(head,j1);
      break;
    case 3:
      show(head);
      break;
  }
 }  
 
   
 system("pause"); 
 return 0;
}
}           
void Insert(group* head){

}
void Delete(group*& head,int n){
     group* p=head,*q=NULL;
     if(n==0||head==NULL)
        return;
     if(n==1){
       head=p->next;
       delete p;  
     return;
     }  
     for(int i=0;i<n-2;i++)
         p=p->next;
     q=p;
     q->next=p->next->next;
     //delete p->next;
}    
int main(){
 group* head=Creat();
 //show(head);
 int j=0,j1,j2;
 while(1){
 //cout<<"now determine what to do: 1 represents insert and 2 represents delete, 3 represents print\n";
 //cin>>j;
  //switch(j){
    //case 1:Insert(head);break;
    //case 2:
      cout<<"Give the number you would like to delete: ";
      cin>>j1;
      Delete(head,j1);
      show(head);
     // break;
    //case 3:show(head);break;
  
 }  
 
   
 system("pause"); 
 return 0;
}

