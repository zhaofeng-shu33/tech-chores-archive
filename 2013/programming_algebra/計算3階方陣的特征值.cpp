#include<iostream>
#include<fstream>
using namespace std;
void swap_value(int& num1,int& num2){
    int temp=num1;
    num1=num2;
    num2=temp;
}
// factorial_calculation这个函数计算给定正整数的阶乘。 
int factorial_calculation(int num){
    int product=1;
    for(int i=1;i<=num;i++)
        product*=i;
    return product;
}
int calculation_of_determinant(int** matrix,int order){
    int number_of_terms=factorial_calculation(order);
    //number_of_terms这个数标示了在行列式的一般展开中有多少项。 
    int total_sum=0;
    
    
    int* auxiliary_array=new int [order];
    int* subsidiary_array=new int [order];
    int* supplementary_array=new int[order];
    //对以上三个辅助数列的处理是我的程序代码的关键所在。 
    int pro=1;
    for(int i=0;i<order;i++){
        pro*=(i+1);
        supplementary_array[i]=pro;
    } 
               
    for(int i=0;i<order;i++)
        auxiliary_array[i]=i;
     //给 auxiliary_array辅助数列的初始化为0~n-1的自然排列。 
    for(int i=0;i<number_of_terms;i++){
        int substitute_i=i;
        for(int j=0;j<order;j++){           
            (subsidiary_array[j])= substitute_i / supplementary_array[order-j-2] ;
             substitute_i = substitute_i % supplementary_array[order-j-2];
             for(int t=j+subsidiary_array[j];t>j;t--)
                    swap_value( auxiliary_array[t], auxiliary_array[t-1]);
        }
            int product=1; 
            for(int j=0;j<order;j++)
                product*=matrix[(auxiliary_array[j])][j];
           
            int inverse_order_of_sequence=0; 
            for(int t=0;t<order;t++)
                for(int r=t+1;r<order;r++)
                   if(auxiliary_array[t]>auxiliary_array[r])
                      inverse_order_of_sequence++;
            if(inverse_order_of_sequence%2==0)
               total_sum+=product;
            else
               total_sum-=product;
                    
           

            for(int i=0;i<order;i++)
                auxiliary_array[i]=i;
                                
    }      
    return total_sum;  
}    
int main(){
   int a[3][3];
   int** b=new int*[3];
   for(int i=0;i<=2;i++)
      b[i]=new int[3];
   for(int i=0;i<=2;i++)
       for(int j=0;j<=2;j++)
           cin>>a[i][j];
   int minor2,trace,one_eigen_value=-51;
   trace=a[0][0]+a[1][1]+a[2][2];
   minor2=a[0][0]*a[1][1]-a[0][1]*a[1][0]+a[0][0]*a[2][2]-a[0][2]*a[2][0]+a[1][1]*a[2][2]-a[1][2]*a[2][1];
   for(int t=-50;t<=50;t++){
        for(int i=0;i<=2;i++)
           for(int j=0;j<=2;j++){
               if(i==j)
                  b[i][j]=a[i][j]-t;
               else b[i][j]=a[i][j];
           }
       if(t==50){
          cout<<endl;
          for(int i=0;i<=2;i++)
            for(int j=0;j<=2;j++){
                cout<<b[i][j]<<' ';
                 if(j==2)
                   cout<<endl;
          }    
       }    
       cout<<calculation_of_determinant(b,3)<<' ';
       if(calculation_of_determinant(b,3)==0)//b[0][0]*b[1][1]*b[2][2]+b[0][1]*b[1][2]*b[2][0]+b[0][2]*b[1][0]*b[2][1]-b[0][2]*b[1][1]*b[2][0]-b[0][1]*b[1][0]*b[2][2]-b[0][0]*b[1][2]*b[2][1]==0)
          {one_eigen_value=t; cout<<"Abgemcht"<<t;
           
          }
      int co_efficient1=trace-one_eigen_value;
      if(one_eigen_value!=-51)
        cout<<'*'<<one_eigen_value;
        break;
   }
            
       
    char ch;
    cin>>ch;
    return 0;
} 
