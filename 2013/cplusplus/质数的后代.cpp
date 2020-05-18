#include<iostream>
using namespace std;
class Complex{
  public:
    Complex(){}
    Complex(double a, double b);
    Complex(int a, int b);
    Complex(Complex& c);
    ~Complex(){}
    friend istream& operator >>(istream& fin,Complex& c);
    friend ostream& operator <<(ostream& fout,Complex& c);
    void operator = (Complex& c);
    private:
    double real;
    double img;
}; 
  
int main(int argc,char* argv[]) {
  Complex a(2,3);
  cout<<a;
  system("pause");

    return 0;
}
Complex::Complex(double a,double b){
  real=a;
  img=b;
}
Complex::Complex(int a,int b){
  real=a;
  img=b;
}

Complex::Complex(Complex& c){
  real=c.real;
  img=c.img;
}

  
istream& operator >>(istream& fin,Complex& c){
  return fin>>c.real>>c.img;
}
ostream& operator <<(ostream& fout,Complex& c){
  return fout<<c.real<<'+'<<c.img<<'i';
}
void Complex::operator =(Complex& c)
{
        real=c.real;
        img=c.img;
}     
