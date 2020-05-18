//This program 完成 polynominal 的带余除法。//要对这个程序进行改进使它完成辗转相除法。用到recursion. 
#include<iostream>
#include<fstream>
using namespace std;
void division(int* polynomial1,int* polynomial2,int degree1,int degree2){
    int degree3=degree1-degree2+1,temp=degree3+1,degree4=0,wri;
   // cout<<"ubung"<<' ';
    while(temp>1){
       temp--;
       int tem_quotient=polynomial1[degree3-temp]/polynomial2[0];
       
      
       for(int i=degree3-temp;i<degree2+degree3-temp;i++)
           polynomial1[i]=polynomial1[i]-tem_quotient*polynomial2[i-degree3+temp];
       }
    bool ya=true;
   // cout<<"Lerherin"<<' ';//递归一次根本到不了这儿！是不是不能乱定义新的东西？ 
    for(int i=0;i<degree1;i++)
       if(polynomial1[i]!=0){
          ya=false;degree4=degree1-i;
          wri=i;
         
        //  for(int j=0;j<degree4;j++)
         //    cout<<' '<<remaider[j];
          break;
       }
    if(ya)// return 1;
    {     // the remainder is 0 polynomial.
    cout<<"The great common divisor is";
    for(int i=0;i<degree2;i++)
       cout<<'*'<<polynomial2[i]<<' ';
   }
    else //return -1;
    {
    // cout<<endl<<"wieder";
     int remaider[degree4];
     for(int j=wri;j<degree1;j++)
             remaider[j-wri]=polynomial1[j];
       division(polynomial2,remaider,degree2,degree4);  //如何解决非整数的情况？ 
   }                
}
//void gcd(int* polynomial1,int* polynomial2,int degree1,int degree2){   
 //    division(polynomial1,polynomial2,degree1,degree2); 
int main(){
    int degree1,degree2;
    cin>>degree1>>degree2;
    int polynomial1[degree1],polynomial2[degree2];//；输入polynomial真实的次数+1。 
    for(int i=0;i<degree1;i++)
       cin>>polynomial1[i];
    for(int i=0;i<degree2;i++)
       cin>>polynomial2[i];
    division(polynomial1,polynomial2,degree1,degree2);
    char ch;
    cin>>ch;
    return 0;
}   
