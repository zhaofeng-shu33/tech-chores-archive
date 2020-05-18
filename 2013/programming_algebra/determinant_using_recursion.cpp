#include<iostream>
#include<fstream>
using namespace std;
int det(int** a,int n){
  if(n==1)
     return a[0][0];

 int temp[n];
 for(int i=0;i<n;i++){
     int** b=new int*[n-1];
     for(int y=0;y<n-1;y++)
        b[y]=new int [n-1]; 
     for(int j=0;j<n;j++){
        
       if(j<i)
          for(int r=0;r<n-1;r++)
              b[r][j]=a[r][j];
       if(j>=i && j<n-1)
          for(int r=0;r<n-1;r++)
              b[r][j]=a[r][j+1];
     }
     
     temp[i]=det(b,n-1);
    }    
 int sum=0;
  for(int i=0;i<n;i++){
      if((n+i+1)%2==0)
      sum+=a[n-1][i]*temp[i];
      else
      sum-=a[n-1][i]*temp[i];
  }         
  return sum; 
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
    cout<<endl;
    for(int i=0;i<order;i++)
       for(int j=0;j<order;j++){
          cout<<matrix[i][j]<<' ';
         if(j==order-1)
          cout<<endl;  
      }        
  cout<<det(matrix,order);    
    char ch;
    cin>>ch;
    return 0;
}
