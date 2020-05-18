#pragma once
#include<iostream>
#include<cmath>
using namespace std;
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
    complex operator +(const complex& n1){return complex(n1.real+real,n1.img+img);}
    complex operator -(const complex& n1){return complex(n1.real-real,n1.img-img);}
    complex operator * (complex& n1){
      complex tem;
      tem.real=real*n1.real-img*n1.img;
      tem.img=real*n1.img+img*n1.real;
      return tem;
    }     		    	 
  private:
    double real,img;
};
istream& operator >>(istream& fin, complex& n1){
  return fin>>n1.real>>n1.img;
  
}
ostream& operator <<(ostream& fout, const complex& n1){
  fout<<n1.real<<'+'<<n1.img<<'i';
  return fout;
}  
  
