#include<iostream>
#include<iomanip>//This program calculates the reverse of a matrix.
using namespace std;
//cout.setf(fixed);
//cout.setf(showpoint);
// swap_value这个函数交换两个数的值。 
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
        
        cout<<"\t input the number of order of a determinant.\n";
    int order;
    cin>>order;
    cout<<"  Input every elements of the determinant,from the first line to the last line,\n"
        <<"from the first column to the last column.\n";
    //定义一个动态2维数组来容纳输入的n*n个数。 
    int* *matrix=new int*[order];
    for(int i=0;i<order;i++)
       matrix[i]=new int[order];
    for(int i=0;i<order;i++)
       for(int j=0;j<order;j++)
          cin>>matrix[i][j];
     
    double determinant= calculation_of_determinant(matrix, order) ;
    int** reverse_matrix=new int*[order];
    for(int i=0;i<order;i++)
       reverse_matrix[i]=new int[order]; 
    int** minor_determinant=new int*[order-1];
    for(int i=0;i<order;i++)
       minor_determinant[i]=new int[order-1];

   for(int i=0;i<order;i++)
       for(int j=0;j<order;j++){
     
           for(int k=0;k<order-1;k++)
               for(int r=0;r<order-1;r++){
                   int p,q;
                   if(k<i)
                   p=k;
                   else
                   p=k+1;
                   if(r<j)
                   q=r;
                   else
                   q=r+1;   
                   minor_determinant[k][r]=matrix[p][q]; 
                } 
               

                   int sign;
                   if((i+j)%2==0)
                      sign=1;
                   else
                      sign=-1;
                   reverse_matrix[j][i]=sign*calculation_of_determinant(minor_determinant,order-1);
                       
         } 
         cout<<"The reverse of the matrix you input is:"<<endl;
  for(int i=0;i<order;i++)
       for(int j=0;j<order;j++){
          cout<<setiosflags(ios::fixed)<<setprecision(2)<<(reverse_matrix[i][j]/determinant)<<'\t';
          if(j==order-1)
            cout<<endl;
       }    
    char ch;
    cin>>ch;
    return 0;
} 
