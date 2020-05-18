#include<iostream>
#include<fstream>
#include <cstring>
#include<cmath>
#include<algorithm>
#include<iterator>
#include<deque>
#include<list>
#include<numeric>
#include<iomanip>
#include<vector>
using namespace std;
//    int a[]={0,1,2};
//    Perm(0,3,a);
enum position{chaser,beater,keeper,seeker};
struct player{
  string name;
  int hit_target;
  int endurance;
  int  nimble;
  position special_pos;
  double general_factor;
  //double special_fac;
};player p[7];double max1=0;int order[3];
void swap(int& a,int& b){
    int t=a;
    a=b;
    b=t;
}
void judge(int b[]){
  double tem;//b[0],b[1],b[2];beater beater seeker;
  p[b[0]].general_factor=0.5*p[b[0]].hit_target+2*p[b[0]].endurance+0.5*p[b[0]].nimble;
  p[b[1]].general_factor=0.5*p[b[1]].hit_target+2*p[b[1]].endurance+0.5*p[b[1]].nimble;
  p[b[2]].general_factor=0.5*p[b[0]].hit_target+0.5*p[b[0]].endurance+2*p[b[0]].nimble;
  tem=( p[b[0]].general_factor+p[b[1]].general_factor ) * p[b[2]].general_factor;
  if(tem>max1){
  max1=tem;
  order[0]=b[0];order[1]=b[1];order[2]=b[2];
  }  
}    
void Perm(int k,int n,int r,int a[]){
    if(r==0){
       for(int i=0;i<k;i++)
           judge(a);
    
    return;
  }  

    for(int i=k;i<n;i++){
      swap(a[i],a[k]);
      Perm(k+1,n,r-1,a);
      swap(a[i],a[k]);
    }  
}           
//target factor of chaser
//defence factor of beater
//keeping goal factor of keeper
//success factor of seeker
//every one has potence
int main(){
  //fisrtly determine two beaters and one seeker
  int c[7][3];
  for(int i=0;i<7;i++)
      for(int j=0;j<3;j++)
          cin>>c[i][j];
  
  for(int i=0;i<7;i++){
      p[i].hit_target=c[i][0];
      p[i].endurance=c[i][1];
      p[i].nimble=c[i][2];
  }
  //The following codes is based on the supposition that user has input needed data of seven players
  int a[]={0,1,2,3,4,5,6};
  Perm(0,7,3,a);// call the related function to get the 3 array of 7 numbers and the most proper person to become seeker.
  
  p[order[0]].special_pos=beater;
  p[order[1]].special_pos=beater;
  p[order[2]].special_pos=seeker;
  
  
  //Then find the most proper goal keeper in the rest 4 players.
  double tem_gf=0;
  int fix_keeper=0;
  for(int i=0;i<7 ;i++){
     if(i==order[0]||i==order[1]||i==order[2])
        continue;
      p[i].general_factor=p[i].hit_target+p[i].endurance+p[i].nimble;
      if(p[i].general_factor>tem_gf)
        fix_keeper=i;tem_gf=p[i].general_factor;
  }
  p[fix_keeper].special_pos=keeper;
  for(int i=0;i!=fix_keeper&&i!=order[0]&&i!=order[1]&&i!=order[2]&&i<7;i++)
      p[i].special_pos=chaser;
  
  
  cout<<endl<<"in the Quidditch match,\n ";
  for(int i=0;i<7;i++){
     if(p[i].special_pos==3)
     cout<<"player number "<<i<<" is apt to be seeker"<<endl;   
     if(p[i].special_pos==1)
     cout<<"player number "<<i<<" is apt to be beater"<<endl;   
     if(p[i].special_pos==0)
     cout<<"player number "<<i<<" is apt to be chaser"<<endl;   
     if(p[i].special_pos==2)
     cout<<"player number "<<i<<" is apt to be keeper"<<endl;   
       
  }  
  
  system("pause");
  return 0;
}
 
