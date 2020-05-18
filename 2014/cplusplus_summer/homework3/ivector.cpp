#include<iostream>
#include<fstream>
#include <cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<iterator>
#include<deque>
#include<list>
#include<numeric>
#include<iomanip>
#include<vector>
using namespace std;
template <class T>
class iVector{
  protected: 
      int _size;
      T* _vector;
  public:
      typedef T* iterator;
      iVector(int n): _size(n){
        _vector=new T;
      }
      iterator begin(){
        return _vector;
      }
      iterator end(){
        return _vector+_size;
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
           if(_size<=0){
              throw string("no elements to delete!");
            }  
           _size--;            
      }
      void push_back(const T& v){
          *(_vector+_size)=v; 
          _size++;
      }     
      T& operator [](int n){
          return *(_vector+n);
      }    
      template <class iterator>  
     void isort(iterator begin, iterator end){
         for(iterator i=end-1; i!=begin; i=i-1)
             for(iterator j=begin;j!=i;j=j+1)
                 if(*j > *(j+1)){
                   T tem= *j;
                   *j = *(j+1);
                   *(j+1) = tem; 
                  }  
          for(iterator i=begin;i!=end; i=i+1)           
                 cout<<*i<<' ';
         cout<<endl;
}

};
    
int main(){
  iVector<int> a(0);
  try{
    a.pop_back();
  }catch(string a){
    cout<<a<<endl;
  }    
  // can not finish properly?
  return 0;
}
 
