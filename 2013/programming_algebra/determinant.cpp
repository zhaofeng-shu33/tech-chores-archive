#include<iostream>
using namespace std;
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
int main()
{
    //我的程序代码需要完善之处：求逆序数的方法很笨。
    //我的程序代码的最关键的地方是给出0~n-1的n!个不同的排列，这一点我给你当面解释。 
    //This program calculates the value of a determinant.
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
        auxiliary_array[i]=i;//To get all the permunation.
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
            for(int j=0;j<order;j++){
               // cout<<(auxiliary_array[j]+1)<<' ';
                product*=matrix[j][(auxiliary_array[j])];
            }
           // cout<<endl;    
            int inverse_order_of_sequence=0; 
            for(int t=0;t<order-1;t++)//这里用冒泡法没优势，因为要不断调用函数。 
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
    cout<<total_sum;  
                                  
    char ch;
    cin>>ch;
    return 0;
}

