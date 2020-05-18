//这个程序应该返回一个数，它比m n 都小 
//注意，这个程序可能多做了若干次不必要的初等行变换。 
#include<iostream>
#include<iomanip>
using namespace std;
int rank=0;
int swap(double &a,double& b){
    double temp=a;
    a=b;
    b=temp;
}
void ChangeTwoRow(double* a,double* b,int c,int d,int n,double** matrix){
    for(int i=0;i<n;i++)
        swap(matrix[c][i],matrix[d][i]);
}
void ElementaryConversion(double** matrix,int m,int n){
       
    if(matrix[m-1][n-1]==0)
      for(int i=0;i<m-1;i++){
         ChangeTwoRow(matrix[i],matrix[m-1],i,m-1,n,matrix);
         if(matrix[m-1][n-1]!=0)
            break;
      }    
          
    if(matrix[m-1][n-1]!=0){
        rank++;
    for(int i=0;i<m-1;i++){
       
       for(int j=0;j<=n-1;j++){
           
          matrix[i][j]=matrix[i][j]- matrix[i][n-1] / matrix[m-1][n-1]* matrix[m-1][j] ;    //写成 matrix[i][j]- =temp * matrix[order-1][j]是错的，为什么？ 
    }}}
    else
       return;
}  

int main(){
    int m,n;
    cin>>m>>n;
    double* *matrix=new double*[m];
    for(int i=0;i<m;i++)
       matrix[i]=new double[n];
    for(int i=0;i<m;i++)
       for(int j=0;j<n;j++)
          cin>>matrix[i][j];
    for(int i=0;i<m && i<n;i++){   
       ElementaryConversion(matrix,m-i,n-i);
       cout<<matrix[0][0]<<' '<<matrix[1][0]<<matrix[2][0]<<endl;
   }    
  //   cout.setf(ios::fixed);
  //  cout.setf(ios::showpoint);       
  //  setprecision(1);      //这个魔法配方怎么达不到应有的效果？ 

    for(int i=0;i<m;i++)
       for(int j=0;j<n;j++){
          cout<<matrix[i][j]<<'\t';
          if(j==n-1) 
            cout<<'\n';
       } 
     cout<<"The rank of matrix is "<<rank;          
          

    char ch;
    cin>>ch;
    return 0;
} 
