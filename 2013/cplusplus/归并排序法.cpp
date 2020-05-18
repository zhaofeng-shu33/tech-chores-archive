#include<iostream>
using namespace std;
void Merge(int* a,int first,int medium,int last){
    int i=first,j=medium+1, *temp,cur=0;
    temp=new int(last-first+2);
    while( i<=medium && j<=last)
        if(a[i]>a[j])
           temp[cur++]=a[j++];
        else
           temp[cur++]=a[i++];
    while(i<=medium)
        temp[cur++]=a[i++];
    while(j<=last)
        temp[cur++]=a[j++];
    for(int r=0;r<cur;) 
        a[first++]=temp[r++];  
    delete temp;    
}           
void MergeSort(int* a,int first,int last){
     if(first==last)
         return;
               
     int medium=(first+last)/2;
     MergeSort(a,first,medium);
     MergeSort(a,medium+1,last);
     Merge(a,first,medium,last);
         
} 

int main(){
      int a[]={5,9,3,2,1,7,4,6,8};
      int length=sizeof(a)/4;
      MergeSort(a,0,length-1);
      for(int i=0;i<length;)
          cout<<a[i++]<<' ';
    char ch;
    cin>>ch;
    return 0;
} 
