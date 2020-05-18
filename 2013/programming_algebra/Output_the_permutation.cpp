#include<iostream>
#include<fstream>
//基本上成功，关键是对全局数组怎么处理。 
using namespace std;
int N=3;
int subsidiary[20],nu=0;
void swap(int &a,int& b){
    int temp=a;
    a=b;
    b=temp;
}
/*void output_permutation(int n){
    if(n==N){
       for(int i=0;i<N;i++)//nu还是0吗？ 
          cout<<subsidiary[i]<<' ';
       cout<<endl;
       
    }
    else{
       
       for(int j=1;j<=N;j++){//必须有一个判断的程序 
          
          subsidiary[n]=j;//cout<<subsidiary[nu-1];//数组索引中[n-1]不改变n的值，but [n++] will change the value of n; 
          bool equal=false;
          for(int i=0;i<n;i++){
              if(subsidiary[n]==subsidiary[i]){
                 equal=true;break;//nu--就是回溯吗，刚才加的不算，咱们重新开始。 
              }    
          }   
          if(equal) continue;//条件满足，所有一次循环中continue之后的东西也就不执行了。 
          else{
             output_permutation(n+1);
            // cout<<"Guten";
    }}}    
}*/
void Perm(int k,int n,int a[]){//code of experts. arrange numbers whose subscripts are k~n
    if(k==n){
       for(int i=0;i<n;i++)
           cout<<a[i]<<' ';
       cout<<endl;
       return;
   }    
    for(int i=k;i<n;i++){  
       swap(a[i],a[k]);
       Perm(k+1,n,a);
       swap(a[i],a[k]);
    }
}
int cnt=0;  
void Perm(int k,int n,int r,int a[]){
    fsteam fout("permu.txt");
    if(r==0){
       for(int i=0;i<k;i++)
           fout<<a[i]<<' ';
       cnt++;
       fout<<endl;
    return;
  }  

    for(int i=k;i<n;i++){
      swap(a[i],a[k]);
      Perm(k+1,n,r-1,a);
      swap(a[i],a[k]);
    }  
}           
int main(){
    int a[]={1,2,3,4,5};
    Perm(0,5,5,a);
    //output_permutation(0);
   
    cout<<endl<<cnt;
    char ch;
    cin>>ch;
    return 0;
} 
