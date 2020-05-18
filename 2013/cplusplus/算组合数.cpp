#include<iostream>
using namespace std;
int main()
{
    //This program calculates the number of getting m items from n items;
    int m,n;
    cin>>m>>n;
    if(m>n/2)
       m=n-m;
    int* *p=new int*[m+1];
    for(int i=0;i<m+1;i++)
      p[i]= new int[n+1];
    for(int i=0;i<n+1;i++)
        p[0][i]=1;
    for(int i=1;i<m+1;i++)
        p[i][i]=1;    
      
     
    
    for(int i=1;i<=m;i++)
        for(int j=i+1;j<=n;j++){
        p[i][j]=p[i-1][j-1]+p[i][j-1];
        cout<<i<<" "<<j<<" "<<p[i][j]<<endl;
        }
    cout<<p[m][n];          
   
    
                    
    char ch;
    cin>>ch;
    return 0;
} 
//下面用递归的方法设计了一个函数。 
int combination_calculation(int r,int n){
   if(r==0)
   return 1;
   else
   return (combination_calculation(r-1,n)*(n-r+1)/r);
}
