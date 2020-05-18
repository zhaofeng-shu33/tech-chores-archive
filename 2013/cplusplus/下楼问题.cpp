//该程序解决下楼问题 终级目的是给出integer N的拆分和各种拆分的排列。Q1 计算N的拆分数，递归还行的通吗？先要从数学中借力。 
#include<iostream>
#include<fstream>
using namespace std;
int subsidiary[50],N=0;
void down(int);
void down_copy(int);
int stair(int n){
    if(n==1)
       return 1;
    else if(n==2)
       return 2;
    else if(n==3)
       return 4;
    else{
        if(subsidiary[n]<0)
           subsidiary[n]=stair(n-1)+stair(n-2)+stair(n-3);
        return subsidiary[n];
    }
}        
int main(){
   cout<<40%3;
   char ch;
   cin>>ch;
}
int steps[20];//用一个数组就可以 
int step_num=0;
void down(int n){//没有初始条件也可以结束（n=0)别无选择就只有一种选择，原地不动。 
    //int res=0;
    if(n==0){
      for(int i=0;i<step_num;i++)
         cout<<steps[i]<<' ';
      cout<<endl;
    } 
    if(n>=3){// 3 2   3 1 1    //每次调 n>=几时就在数组里存上那个数 
        steps[step_num++]=3;
        down(n-3);
        step_num--;
    }
    if(n>=2){
        steps[step_num++]=2;
        down(n-2);
        step_num--;
    }         
    if(n>=1){
        steps[step_num]=1;//表示这一步下3；  
        step_num++;
        down(n-1);
        step_num--;//回溯   这套思路用来走迷宫。退回来看有没有其他选择。 
    } //什么时候能执行到这里？
}   
void down_copy(int n){
    if(n==0){
      for(int i=0;i<step_num;i++)
         cout<<steps[i]<<' ';
      cout<<endl;
    }
    for(int i=1;i<=N;i++){
      steps[step_num]=i;
      if((n-i)>=0){
         if((step_num==0)||(step_num>0 && steps[step_num]>=steps[step_num-1])){
         step_num++;
         down_copy(n-i);
         step_num--;
     }}
     else break;
   }        
}    
        
    

//你能输出所有的走法。用一个int 数组记一个方案。   
