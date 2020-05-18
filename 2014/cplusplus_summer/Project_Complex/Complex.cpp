#include<iostream>
#include<cmath>
using namespace std;
class complex{
  public:
    complex(){}
    complex(double a, double b);
    complex(const complex& c);
    ~complex(){}
    void Add(complex & c){
        real+=c.real;
      	img+=c.img;
   }
    void Sub(complex & c){
        real-=c.real;
	      img-=c.img;
    }      
    void Div(complex & c){
       double temp=real*real+img*img,temp_real=real,temp_img=img;
       real=(temp_real*c.real+temp_img*c.img)/temp;
       img=(temp_img+c.real-temp_real*c.img)/temp;
    }
    double modulus(){
          return sqrt(real*real+img*img);
    }
    complex operator + (const complex& n1){
    /*  complex tem;
      tem.real=real+n1.real;
      tem.img=img+n1.img;*/
      return complex(real+n1.real,img+n1.img);
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
    complex operator * (complex& n1);
    private:
    double real, img;
};
complex::complex(double a,double b){
   real=a;img=b;
}
complex::complex(const complex& c){
        real=c.real;
        img=c.img;
}
complex complex::operator *(complex& n1){
      complex tem;
      tem.real=real*n1.real-img*n1.img;
      tem.img=real*n1.img+img*n1.real;
      return tem;
}     		    	 
    
istream& operator >>(istream& fin, complex& n1){
  return fin>>n1.real>>n1.img;
  
}
ostream& operator <<(ostream& fout, const complex& n1){
  fout<<n1.real<<'+'<<n1.img<<'i';
  return fout;
}  
  
