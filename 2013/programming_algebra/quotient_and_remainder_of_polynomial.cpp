//This program 完成 polynominal 的带余除法。 
#include<iostream>
#include<fstream>
using namespace std;
void division(int* polynomial1,int* polynomial2,int degree1,int degree2){
    int degree3=degree1-degree2+1;int temp=degree3+1,t=0;
    int quotient[degree3];
    while(temp>1){
       temp--;
       int tem_quotient=polynomial1[degree3-temp]/polynomial2[0];
       cout<<'*'<<tem_quotient<<'*';
       quotient[t++]=tem_quotient;
       for(int i=degree3-temp;i<degree2+degree3-temp;i++)
           polynomial1[i]=polynomial1[i]-tem_quotient*polynomial2[i-degree3+temp];
           for(int j=0;j<degree1;j++)
               cout<<polynomial1[j]<<' ';
    }
    cout<<endl;
    for(int i=0;i<degree3;i++)
       cout<<'*'<<quotient[i]<<' ';           
    cout<<endl<<"The remainder is";
    for(int i=0;i<degree1;i++)
       if(polynomial1[i]!=0){
          for(int j=i;j<degree1;j++)
              cout<<'*'<<polynomial1[j]<<' ';
          break;
       }    
}    

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
