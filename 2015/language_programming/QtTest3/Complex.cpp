#include <iostream>
#include <cmath>
using namespace std;

#include "Complex.h"

Complex::Complex(double a, double b) : real(a), img(b) {
}
Complex::Complex(const Complex & c) {
    real = c.real;
    img = c.img;
}    
Complex::~Complex() {
}

Complex Complex::operator +(const Complex & c) const {
    return Complex(real + c.real, img + c.img);
}
Complex Complex::operator *(const Complex & c) const {
    double new_real = real * c.real - img * c.img;
    double new_img = img * c.real + real * c.img;
    return Complex(new_real, new_img);
}
Complex Complex::operator /(const Complex & c) const {
    const double EPS = 0.0000001;
    double q = c.real * c.real + c.img * c.img;
    double nr = real * c.real + img * c.img;
    double ni = real * c.img - img * c.real;
    if (q <= EPS && q >= -EPS)
        throw nr;
    return Complex(nr / q, ni / q);
}

istream & operator >>(istream & i, Complex & c) {
    return i >> c.real >> c.img;
}
ostream & operator <<(ostream & o, const Complex & c) {
    return o << c.real << " + " << c.img << " * i";
}    
QString Complex::display() const {
    return QString("%1 + %2 * i").arg(real).arg(img);
}
