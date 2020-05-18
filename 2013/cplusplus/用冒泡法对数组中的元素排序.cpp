#include<iostream>
using namespace std;
void swap(int& a,int& b){
    int temp=a;
    a=b;
    b=temp;
}
//from the samllest to the largest.    
void arraySort(int a[],int size){//冒泡排序。 与选择排序法的  排序是为了折半查找。 折半是为了把o(n)'s problem 变成 0(logn)'s problem. 
    //This function sorts an array from the smallest to the largest.
    for(int i=size-1;i>=0;i--)
        for(int j=0;j<i;j++)
            if(a[j]>a[j+1]){
               swap(a[j],a[j+1]);
               
             }    
    for(int i=0;i<size;i++)
        cout<<a[i]<<'\t';
}  
          
int main(){
    
    char ch;
    cin>>ch;
    return 0;
}  
void arraySort_usingRecursion(int a[],int length_of_array){
     int min=a[0],index=0;
     for(int i=1;i<length_of_array;i++)
        if(a[i]<min){
            min=a[i];
            index=i;
        }
     swap(a[i],a[0]);
     if(length_of_array>1)       
     arraySort_usingRecursion( a[], length_of_array-1);
 }    
     
 
     
     
