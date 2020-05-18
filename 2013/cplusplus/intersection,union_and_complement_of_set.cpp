#include<iostream>
#include<fstream>
using namespace std;
int n,m;
void swap(int& a,int& b){
    int temp=a;
    a=b;
    b=temp;
}
void arraySort(int a[],int size){//冒泡排序。 与选择排序法的  排序是为了折半查找。 折半是为了把o(n)'s problem 变成 0(logn)'s problem. 
   // cout<<"Speisekarte";//This function sorts an array from the smallest to the largest.
    for(int i=size-1;i>=0;i--)
        for(int j=0;j<i;j++)
            if(a[j]>a[j+1]){
               swap(a[j],a[j+1]);
               //cout<<"Schweine";
             }    
   // for(int i=0;i<size;i++)
   //     cout<<a[i]<<'\t';
}  

void intersection(int a[],int b[]){
   int step=0;
   int c[n];
   for(int i=0;i<n;i++){
       c[step]=a[i];//cout<<'*'<<c[step]<<endl;
       for(int j=0;j<m;j++)
           if(c[step]==b[j])
              {step++;break;}
   }
 //  for(int i=0;i<step;i++)
 //     cout<<c[i]<<' ';
 //  cout<<endl;

   arraySort(c,step);    
   for(int i=0;i<step;i++)
      cout<<c[i]<<' ';
   cout<<endl;
     
}
void union1(int a[],int b[]){
    int step=0;
    int* c=new int[m+n];
    for(int i=0;i<n;i++)
       c[step++]=a[i];
    for(int i=0;i<m;i++){
       c[step]=b[i];
       for(int j=0;j<n;j++){
          if(c[step]==a[j])
             break;
          if(j==n-1)
             step++;
       }
    }    
    arraySort(c,step);
   for(int i=0;i<step;i++)
      cout<<c[i]<<' ';
   cout<<endl;
        
} 
void complement(int a[],int b[]){
    int step=0;
    int c[n];
    for(int i=0;i<n;i++){
        c[step]=a[i];//cout<<step<<' '<<a[i]<<endl;
        for(int j=0;j<m;j++){
            if(c[step]==b[j]){
              break;}
            if(j==m-1)
               step++;
        }
    }  
    arraySort(c,step);
   for(int i=0;i<step;i++)
      cout<<c[i]<<' ';
   cout<<endl;
      
}            
int main(){

   cin>>n;
   int* a=new int[n];
   for(int i=0;i<n;i++)
      cin>>a[i]; 
   cin>>m;
   int* b=new int[m];
   for(int i=0;i<m;i++)
      cin>>b[i]; 
   intersection(a,b); 
   union1(a,b);
   complement(a,b);  
    char ch;
    cin>>ch;
    return 0;
} 
