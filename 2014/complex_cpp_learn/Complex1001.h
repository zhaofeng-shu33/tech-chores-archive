#ifndef COMPLEX1001_H__
#define COMPLEX1001_H__
#include <iostream>
#include <cmath>
using namespace std;

class Complex{
 public:
    Complex(){}
    Complex(double,double);
    Complex(Complex&);
    ~Complex(){//cout<<"Use this function!\n";
    }
    void Input();
    void Output();
    void Add(Complex&);
    void Mul(Complex&);
    void Sub(Complex&);
    void Div(Complex&);
    friend Complex comp_add(Complex&,Complex&);
 private:
    double real,img;

};
#endif 




