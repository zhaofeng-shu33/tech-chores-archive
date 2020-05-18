#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Complex{
 public:
    Complex(){}
    Complex(double,double);
    Complex(Complex&);
    ~Complex(){//cout<<"Use this function!\n";
    }
    friend istream& operator >>(istream& is, Complex& c);
    friend ostream& operator <<(ostream& out,Complex& c);
    friend Complex operator *(Complex&,Complex&);
    void Sub(Complex&);
    void Div(Complex&);
    Complex& operator ++();
    Complex operator ++(int){
      Complex c=*this;
      ++(*this);
      return c;
    }  
    friend Complex operator +(Complex&,Complex&);
    friend bool operator ==(Complex&,Complex&);

 private:
    double real,img;

}; 
 
int main(int argc,char *argv[]){
    double a=3.0;
    cout<<a<<' ';
    cout<<setprecision(2)<<a<<' ';
    cout<<setiosflags(ios::fixed)<<setprecision(1)<<a<<' ';
     
    return 0;
}
Complex operator +(Complex & a, Complex & b) {
    Complex c(0.0, 0.0);
    c.real = a.real + b.real;
    c.img = a.img + b.img;
    return c;
}
Complex operator *(Complex& a,Complex & b){
    double new_real = a.real * b.real - a.img * b.img;
    double new_img = a.real * b.img + a.img * b.real;
    Complex d(new_real,new_img);
    return d;
}
  
bool operator ==(Complex & a, Complex & b) {
    if(a.real==b.real&&a.img==b.img)
       return true;
    else 
       return false;
}  
void Complex::Sub(Complex& c){
   real-=c.real;
   img-=c.img;
}

void Complex::Div(Complex & c) {
    double d=c.real*c.real+c.img*c.img;
    double new_real = real * c.real + img * c.img;
    double new_img = -real * c.img + img * c.real;
    real = new_real*1.0/d; img = new_img*1.0/d;
}

Complex::Complex(double n1,double n2):real(n1),img(n2){
//  real=n1;
//  img=n2;
}
Complex::Complex(Complex& c):real(c.real),img(c.img){
}
istream& operator >>(istream& is,Complex& c){
   is>>c.real>>c.img;
   return is;
}
ostream& operator <<(ostream& out,Complex& c){
  out<<c.real<<'+'<<c.img<<'i';
  return out;
}
Complex& Complex::operator ++(){
  real++;
  return *this;
}         
