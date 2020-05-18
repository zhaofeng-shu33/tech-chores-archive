#include<iostream>
using namespace std;
int index=0;
int temp[100];//一会尝试用向量代替。 
void Merge(int *a,int first,int medium,int last){
    int i=first,j=medium+1,current=0;
    while( i<=medium && j<=last)
         if(a[i]<a[j])
           temp[current++]=a[i++];
         else{
           temp[current++]=a[j++];
           index+=medium-i+1;
         }
    while(i<=medium)
         temp[current++]=a[i++];
    while(j<=last)
         temp[current++]=a[j++];
    for(int r=0;r<current;r++)
        a[first++]=temp[r];//temp[r++]对吗？ 
}                  
            
void MergeSort(int *a,int first,int last)  
{  
   if (first==last)  
    {  
        return ;  
    }  
    int medium =first+(last-first)/2;  
    MergeSort(a,first,medium);  
    MergeSort(a,medium+1,last);  
    Merge(a,first,medium,last);  
}  

int main(){
     int a[]={5,9,3,2,1,7,4,6,8};
    int length=sizeof(a)/4;
 //用最原始的方法求逆序。           
    int inverse_order_of_sequence=0; 
        for(int t=0;t<length-1;t++) 
            for(int r=t+1;r<length;r++)
                if(a[t]>a[r])
                   inverse_order_of_sequence++;
                    cout<< inverse_order_of_sequence<<endl;
    
   
    MergeSort(a,0,length-1);
    cout<<index;
    char ch;
    cin>>ch;
    return 0;
} 
