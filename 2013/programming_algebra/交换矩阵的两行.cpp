//先做一个交换矩阵两行的变换。 
#include<iostream>
using namespace std;
int swap(int &a,int& b){
    int temp=a;
    a=b;
    b=temp;
}
void ChangeTwoRow(int* a,int* b,int c,int d,int order,int** matrix){
    for(int i=0;i<order;i++)
        swap(matrix[c][i],matrix[d][i]);
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
   ChangeTwoRow(matrix[0],matrix[1],0,1,order,matrix);//这个函数是传引用啊？ 
//这个程序代码用来输出矩阵    
    for(int i=0;i<order;i++)
       for(int j=0;j<order;j++){
          cout<<matrix[i][j]<<'\t';
          if(j==order-1) 
            cout<<'\n';
       }         
    char ch;
    cin>>ch;
    return 0;
} 


   
     
