//计算方阵的秩 
#include<iostream>
using namespace std;
int rank=0;
int swap(int &a,int& b){
    int temp=a;
    a=b;
    b=temp;
}
void ChangeTwoRow(int* a,int* b,int c,int d,int order,int** matrix){
    for(int i=0;i<order;i++)
        swap(matrix[c][i],matrix[d][i]);
}
void ElementaryConversion(int** matrix,int order){
       
    if(matrix[order-1][order-1]==0)
      for(int i=0;i<order-1;i++){
         ChangeTwoRow(matrix[i],matrix[order-1],i,order-1,order,matrix);
         if(matrix[order-1][order-1]!=0)
            break;
      }    
          
    if(matrix[order-1][order-1]!=0){
        rank++;
    for(int i=0;i<order-1;i++){
       int temp= matrix[i][order-1]/matrix[order-1][order-1];
       for(int j=0;j<=order-1;j++)
          matrix[i][j]=matrix[i][j]-temp * matrix[order-1][j] ; //写成 matrix[i][j]- =temp * matrix[order-1][j]是错的，为什么？ 
    }}
    else
       return;
}  
   
int main(){
    int order;
    cin>>order;
    int* *matrix=new int*[order];
    for(int i=0;i<order;i++)
       matrix[i]=new int[order];
    for(int i=0;i<order;i++)
       for(int j=0;j<order;j++)
          cin>>matrix[i][j];
    for(int i=0;i<order;i++)   
    ElementaryConversion(matrix,order-i);
    
        
//这个程序代码用来输出矩阵    
    for(int i=0;i<order;i++)
       for(int j=0;j<order;j++){
          cout<<matrix[i][j]<<'\t';
          if(j==order-1) 
            cout<<'\n';
       } 
     cout<<"The rank of matrix is "<<rank;          

              
    char ch;
    cin>>ch;
    return 0;
}  
