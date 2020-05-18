#include<iostream>
#include<fstream>
#include <cstring>
#include<cmath>
using namespace std;
//how to get the last node in a linklist;
/*
template <class T> 
  
class Umwelt{
  public:
    void Aufbewahren(T x);
    T Erhaelten();
  private:
    T Bestandteil;
    
};
template <class T>
void Umwelt<T>::Aufbewahren(T x){
      Bestandteil=x;
    }

template <class T>  
T Umwelt<T>::Erhaelten(){
    return Bestandteil;
} */
class LinkNode{
  public:
    LinkNode(int data=0):n(data),Next(NULL){}
      
    void Insert(int a){// insert a node at the front of the head
         LinkNode* tem=new LinkNode(a);
         tem->Next=Next;
         Next=tem;
    }
    int GetCurrentData(){
        return n;
    }
    void DeleteNext(){
        if(Next!=NULL){
        LinkNode* tem=Next;
        Next=tem->Next;
        delete tem;
      }  
    }    
    LinkNode* Get_NextNode(){
      return Next;
    }    
  protected:
    int n;
    LinkNode* Next; 
};      
class LinkList {
  public:
      LinkList():size(0){};
      void InsertHead(int a){
       head->Insert(a);
       size++; 
      // cout<<size<<endl; size=9;
      }
      void Move_current_ptr(int b=0){
        position=b;
        int tem=0;
        current_ptr=head;
        while((tem++)<b)
             current_ptr=current_ptr->Get_NextNode();
       // cout<<current_ptr->GetCurrentData()<<' ';
      } 
      bool if_current_ptr_at_end_of_LinkList(){
         if(current_ptr==NULL); //position==size can also be used;
         return true;
         
         return false;
       }  
      int GetCurrentData(){
         return current_ptr->GetCurrentData();
       }   
       void Next_current_ptr(){
          position++;
          if(current_ptr!=NULL)
          current_ptr=current_ptr->Get_NextNode();
       }  
  private:
      LinkNode* head,*current_ptr;
      int size;
      int position;
};
/*class cyclelist{
   public:
   cyclelist(int n):content(n);
   void AddBefore(){}
   void AddAfter(){}
   void Print(){}
   private:
      int content;
      cyclelist *next,*prev;


} */  
int main(){
  LinkList my_linklist;
  for(int i=1;i<10;i++)
      my_linklist.InsertHead(i);
  my_linklist.Move_current_ptr(0);
  while(my_linklist.if_current_ptr_at_end_of_LinkList()){
        cout<<my_linklist.GetCurrentData()<<' ';
        my_linklist.Next_current_ptr();
  }  
  //using recurrence to output;
  
  return 0;
}
 
