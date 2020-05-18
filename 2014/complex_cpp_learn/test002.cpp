#include <iostream>
#include <cmath>
using namespace std;
int find_minimum_position(int* a,int start,int end){
    int tem=100;int position=0;
    for(int i=start;i<end;i++)
        if(tem>a[i]){
           tem=a[i];
           position=i;
        }  
    return position;
}  
void selective_array(int* a,int length){
  for(int i=0;i<length-1;i++){
          swap(a[i],a[find_minimum_position(a,i,length)]);
      cout<<a[i]<<endl;
      }  
}
void arrange(bool* a,int N){
   for(int i=1;i<=N;i++)
       for(int j=i;j<=N;j+=i){
           if(a[j])
              a[j]=false;
           else
              a[j]=true;
       }   
    
}    
int main(){
 int a=1,b=1;
 int c=++a;
 int d=b++;
 cout<<c<<' '<<d;  
 system("pause");
 return 0;
}

