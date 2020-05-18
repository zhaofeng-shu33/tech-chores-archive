#include<iostream>
using namespace std; 
int q=0;int cnt=0;int tem;
bool re(int c[],int d[]){
     if(cnt==q)
        return true;
     bool tr=false;int u=0;     
     for(int t=0;t<q-cnt;t++)
         if(c[t]+tem>=d[t]){ 
            u=t;
            tem+=c[t];
            cnt++;//cout<<'*'<<cnt<<'*';
            tr=true;
            break;
         }
         
     if(tr){
        if(cnt==q)
           return true;
        for(int i=u;i<q-cnt;i++){
         c[i]=c[i+1];
         d[i]=d[i+1];
        }
        re(c,d);
     }
     else
         return false;       
 
   return true;     
}
            

int main(){
   int n;
   cin>>n;
   int a[n],b[n];
   for(int i=0;i<n;i++)
      b[i]=true;
  // for(int i=0;i<n;i++)
  //    cin>>a[i];
   for(int j=0;j<n;j++){
      cin>>a[j];int c[a[j]],d[a[j]]; 
      for(int i=0;i<a[j];i++)
          cin>>c[i]>>d[i];
      q=a[j];tem=0;cnt=0;
      b[j]=re(c,d);
   
  }


   for(int i=0;i<n;i++){
      if(b[i])
        cout<<"YES"<<endl;
      else
        cout<<"NO"<<endl;
   }
  

   char ch;
   cin>>ch;
   return 0;


}

