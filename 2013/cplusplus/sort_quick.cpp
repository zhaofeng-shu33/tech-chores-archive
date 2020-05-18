#include<iostream>//终于成功。 
#include<fstream>
using namespace std;//以数组为参数。n标识了数组的个数 
void swap(int &a,int& b){
    int temp=a;
    a=b;
    b=temp;
}
void quick_sort3(int *a,int l,int e){// n represents the length of the array given
    if(e-l<1)
      return;
      
    int k=a[l],l1=l+1,e1=e;
    while(l1<=e1){
        for(;l1<=e1;l1++)
           if(a[l1]>k)
              break;
        for(;e1>=l1;e1--)
           if(a[e1]<k)
              break;
       
       if(l1<e1){
       swap(a[l1],a[e1]);
       
       }    

       
               
       }    
       swap(a[l],a[e1]);        
    quick_sort3(a,l,e1-1);
    quick_sort3(a,e1+1,e);
    
}
void sort_quick(int *p,int n){//时间复杂度 平均的复杂度 nlog(2)n，最差还是n^2,array sort最快就是nlogn的数量级;快在哪儿？n比较大时。 
    if(n==1 || n==0)//或n<=1; 
      return;//下面选择第0个元素，将比它大的放右边，比它小的放在左边。 
    //位置k怎么找？
    //nemmen 0 platz 
    int t=p[0]; //不是2分法 
    //开新数组。
    int k=0,r=n-1,l=1;//right 和 left 是位置 k 的范围不断缩小的标识。 
    while(r>=l){
    for(;r>0 && r>=l;r--) 
       if(p[r]<t){//我们在数组的靠右边发现了一个比t小的数，这个数应放在p[l]的位置，右边有一个数小就换到左边,换到左边哪儿,左边从p[0]位置开始。 
          p[k]=p[r],k=r;r--;  break;//一旦找到一个这样的数就要终止循环。 刚开始r=3；l=4;k=3;
       }   // for(int i=0;i<3;i++)
        //cout<<p[i]<<' ';

       //下次r不能从n-1开始找了    
    for(; l<=n-1 && l<=r;l++)// 将5 6 9 7 4 1 3   _ 6 9 7 4 1 3    3 6 9 7 4 1 3   3 1 4 5 7 9 6 变成 3 1 4 5 7 9 6；   
       if(p[l]>t){//要放到右边去      
          p[k]=p[l],k=l;l++;  break;//k比l要滞后。 
       }
    }        
    p[k]=t; 
   
   sort_quick(&p[0],k);
   sort_quick(&p[k+1],n-k-1);
}   
void quick_sort2(int *a,int l,int e){// n represents the length of the array given
    if(e-l<1)
      return;
      
    int k=a[l],l1=l+1,e1=e,tem=l;
    while(l1<=e1){
         for(;e1>=l1;e1--)
              if(a[e1]<k){
               a[tem]=a[e1];
               tem=e1;
               e1--;
              
               break;
            }
        for(;l1<=e1;l1++)
           if(a[l1]>k){
               a[tem]=a[l1];
               tem=l1;
               l1++;
           
               break;
           }
       }    
        a[tem]=k;        
    cout<<l1<<':'<<tem<<':'<<e1<<endl;
    quick_sort(a,l,tem-1);
    quick_sort(a,tem+1,e);
    
} 
int main(){
    //int p[]={9,4,3,6,45,1,54,87,23};//出错！ 
     int p[]={0,2,1};
     int n=sizeof(p)/4;
     sort_quick(p,n);
    for(int i=0;i<n;i++)
        cout<<p[i]<<' ';
    char ch;
    cin>>ch;
    return 0;
} 
