#include<iostream>
#include<fstream>
#include <cstring>
#include<cmath>
using namespace std;
//how to get the last node in a linklist;
class complex{
  public:
    complex(){
      // cout<<"complex0";
   }
    complex(double a, double b) {real=a;img=b;}//??
    complex(const complex& c){
        real=c.real;
        img=c.img;
       //cout<<"complex2";
   }
    ~complex(){
//	cout<<"~complex";
   }
    void Input(){
	cin>>real>>img;
   }
    void Output(){
	cout<<real<<"+"<<img<<'i'<<endl;
   }
    void Add(complex & c){
        real+=c.real;
	img+=c.img;
   }
    void Sub(complex & c){
        real-=c.real;
	      img-=c.img;
   }
    void Mul(complex & c){
       double temp_real=real,temp_img=img;
       real=temp_real*c.real-temp_img*c.img;
       img=temp_img+c.real+temp_real*c.img;
   }
    void Div(complex & c){
       double temp=real*real+img*img,temp_real=real,temp_img=img;
       real=(temp_real*c.real+temp_img*c.img)/temp;
       img=(temp_img+c.real-temp_real*c.img)/temp;
    }
    double modulus(){
          return sqrt(real*real+img*img);
   }
  
    complex operator - ( complex& n1) {
         // complex temp(real-n1.real,img-n1.img);
         // return temp; //can not return a temporary unnamed object??
          return complex(real-n1.real,img-n1.img);
    } 
    bool operator ==(const complex& a) const{
      if(real==a.real && (img==a.img))
           return true;
      return false;
    }
    void operator = (const complex& a) { //assignment
        real=a.real;
        img=a.img;
    }
         
    friend istream& operator >>(istream& fin, complex& n1); 	
    friend ostream& operator <<(ostream& fout,const complex& n1); 
    complex operator * (complex& n1){
      complex tem;
      tem.real=real*n1.real-img*n1.img;
      tem.img=real*n1.img+img*n1.real;
      return tem;
    }     		    	 
  private:
    double real, img;
};
istream& operator >>(istream& fin, complex& n1){
  return fin>>n1.real>>n1.img;
  
}
ostream& operator <<(ostream& fout, const complex& n1){
  fout<<n1.real<<'+'<<n1.img<<'i';
  return fout;
}  

template <class T>
struct Node{
  T a;
  Node<T>* next;
  Node(Node<T>* ptr){next=ptr;}
  Node(Node<T>* ptr,T a1){a=a1;next=ptr;}
}; 
template <class T>
struct LinkList{
  LinkList():size(0){last=new Node<T>(NULL);first=new Node<T>(last);}
  Node<T> *last,*first; 
  int size;
  void AddAfter(Node<T>* ptr,T b){
    //Node<T>* tem=ptr->next;
    //ptr->next=new Node<T>(tem,b);
    Node<T>* tem=new Node<T>(ptr->next,b); 
    ptr->next=tem; 
    size++;
  } 
  void print(){
     for(Node<T>* temporary=first->next;temporary!=last;temporary=temporary->next)
         cout<<temporary->a<<' '; //overload << =
  }
  void DeleteAfter(Node<T>* ptr){
     Node<T>* tem=ptr->next;
     ptr->next=ptr->next->next;
     delete tem;
     size--;  
  }      
};    
int main(){

  LinkList<int> my_linklist;
  complex a1(1,2),a2(3,4),a3(5,6);
  
  my_linklist.AddAfter(my_linklist.first,3);
  my_linklist.AddAfter(my_linklist.first,5);
  my_linklist.DeleteAfter(my_linklist.first);
  my_linklist.AddAfter(my_linklist.first,2);
  
  my_linklist.print();
  //using recurrence to output;
  //here->DisplayCurrentData();  
  
  return 0;
}
 
