#include<iostream>
#include<fstream>
#include <cstring>
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
  
class Point1D{
  private: int x;
  public: 
    Point1D(int x1):x(x1){}
    void Output(){
      cout<<x;
    }
    void operator ++(int){
      x++;
    }  
};   
int main(){
  complex a, b;
  cin >> a >> b;
  a=b;
  cout<<a;  
  //cout << a-b;// why can not directly output a-b;???
  system("pause");
  return 0;
}
 
