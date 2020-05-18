//#include <iostream>
//#include <cmath>
#include "Complex1001.h"

using namespace std;

Complex comp_add(Complex & a, Complex & b) {
    Complex c(0.0, 0.0);
    c.real = a.real + b.real;
    c.img = a.img + b.img;
    return c;
}

void Complex::Input(){
   cin>>real>>img;
} 
void Complex::Output(){
  cout<<real<<'+'<<img<<'i';
}
void Complex::Add(Complex& c){
   real+=c.real;
   img+=c.img;
}
void Complex::Sub(Complex& c){
   real-=c.real;
   img-=c.img;
}

void Complex::Mul(Complex & c) {
    double new_real = real * c.real - img * c.img;
    double new_img = real * c.img + img * c.real;
    real = new_real; img = new_img;
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
