#include<iostream>
#include<fstream>
#include <cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
template <class T>
struct Node{
  T a;
  Node<T>* prev;
  Node<T>* next;
  //Node(Node<T>* ptr){next=ptr;}
  Node(Node<T>* ptr1,Node<T>* ptr2,int a1){a=a1;prev=ptr1;next=ptr2;}
};
template <class T>
struct double_linklist{
    Node<T> *first,*last;
    void AddAfter(){}
    void AddBefore(Node<T>* ptr,T b){
      Node<T>* tem=new Node<T>(ptr->prev,ptr,b);
      ptr->prev->next=tem;
      ptr->prev=tem;    
    }
    void AddAfter(Node<T>* ptr,T b){
      Node<T>* tem=new Node<T>(ptr,ptr->next,b);
      ptr->next->prev=tem;
      ptr->next=tem;
    }  
    double_linklist(T b1,T b2){
      first=new Node<T>(NULL,NULL,b1);
      last=new Node<T>(first,first,b2);
      first->next=last;
      first->prev=last;
   }
   void print(){
      for(Node<T>* tem=first->next;tem!=last;tem=tem->next)
         cout<<tem->a<<' ';
    }
   int find_the_max(){
       T max1=0;
       for(Node<T>* tem=first->next;tem!=last;tem=tem->next)
           if( tem->a > max1)
              max1=tem->a;
       return max1;
   }
   void sort(){
      for(Node<T>* tem1=last->prev;tem1!=first;tem1=tem1->prev)
          for(Node<T>* tem2=first->next;tem2!=tem1;tem2=tem2->next)
              if((tem2->a)>(tem2->next->a)){
                 T tem3=tem2->a;
                 tem2->a=tem2->next->a;
                 tem2->next->a=tem3;
              }  
   }          
};      
int main(){
  double_linklist<int> my_double_linklist(4,5);
  for(int i=3;i<8;i++)
  my_double_linklist.AddAfter(my_double_linklist.first,i*i+3);  
  for(int i=3;i<8;i++)
  my_double_linklist.AddAfter(my_double_linklist.first,i*i+2);  
  
  my_double_linklist.print();
  cout<<endl<<my_double_linklist.find_the_max();
  cout<<endl;my_double_linklist.sort();
  my_double_linklist.print();
  
 
 
  return 0;
}
 
