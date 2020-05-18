#include<iostream>
#include<fstream>
#include <cstring>
#include<cmath>
#include<algorithm>
#include<iterator>
#include<deque>
#include<list>
#include<numeric>
#include<iomanip>
#include<vector>
using namespace std;

namespace THU{

template <class T>
class iIterator{
  protected:
      T* _iterator;
  public:
      iIterator(){}
      iIterator(T* p){_iterator=p;}
      iIterator<T> operator -(int i){
        return(_iterator-i);
      }  
      iIterator<T> operator +(int i){
        return(_iterator+i);
      }  
      iIterator<T>& operator =(iIterator ii){
        _iterator=ii._iterator;
        return *this;
      }
      bool operator ==(iIterator li){
        if(_iterator==li._iterator)
           return true;
        return false;
      }  
      
      bool operator !=(iIterator ii){
        if(_iterator!=ii._iterator)
           return true;
        return false;
      }
      operator T*(){
           return alist;
         }
      T& operator *(){
        return *_iterator;
      }      
};
  
template <class T>
class iVector{// what use?
  protected: 
      int _size;
      T* _vector;
  public:
      typedef iIterator<T> iterator;
      iVector(int n): _size(n){
        _vector=new T;
      }
      iterator begin(){   //_vector
        return iterator(_vector);
      }
      iterator end(){
        return iterator(_vector+_size);
      }
      void clear(){
       // _vector=NULL;?
        _size=0;
      }
      bool empty() const{
        if(_size==0 || _vector==NULL)
           return true;
        return false;
      }
      void pop_back(){ 
           _size--;            
      }
      void push_back(const T& v){
          *(_vector+_size)=v; 
          _size++;
      }     
      T& operator [](int n){
          return *(_vector+n);
      }    
       // here iterator is a class
  void isort(iterator begin, iterator end){
         
        for(iterator i=end-1; i!=begin; i=i-1)
            for(iIterator<T> j=begin; j != i; j=j+1)
                 if(i==(begin-1)){
                   //cout<<*j<<' '<<*(j+1)<<'*';
                   T tem= *j;
                   *j = *(j+1);
                   *(j+1) = tem; 
                   
                   //cout<<*j<<' '<<*(j+1)<<'*';
                  }  
          for(iIterator<T> i=begin;i!=end; i=i+1)           
                 cout<<*i<<' ';
         cout<<endl;
      
  }  
};
}    

int main(){
  THU::iVector<int> a(0);
  for(int i=10;i>0;i--)
      a.push_back(i);
  //THU::iIterator<int> my=a.begin();
  //cout<<(*my);
  a.isort(a.begin(),a.end());
  cout<<endl;
  system("pause");// can not finish properly?
  return 0;
}
 
