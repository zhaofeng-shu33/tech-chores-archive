#ifndef _COMPLEX_H_
#define _COMPLEX_H_

#include <istream>
#include <QString>
using namespace std;

class Complex {
public:
    Complex(double a = 0.0, double b = 0.0);
    Complex(const Complex & c);
    ~Complex();

    Complex operator +(const Complex & c) const;
    Complex operator *(const Complex & c) const;
    Complex operator /(const Complex & c) const;
    Complex& operator =(const Complex & c) ;

    friend istream & operator >>(istream & i, Complex & c);
    friend ostream & operator <<(ostream & o, const Complex & c);

    QString display() const;
private:
    double real, img;
};

#endif
