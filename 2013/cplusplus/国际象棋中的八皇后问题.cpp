#include<iostream>
#include<fstream>
using namespace std;
//总共的方法和每一种方法具体的实现。
int pos[8];//把数组放到函数参数里，回头再试。
bool attack(int,int);
void queen(int n){//（int n,int * pos)
    for(int i=0;i<8;i++){
        pos[n]=i;//int new_pos[8];把pos的值copy给new_pos; 
        bool attacked=false;//先假设没有攻击到 //假定pos[n] 中的n symbolize the row ,pos[n]表示所在的列数 
         
        for(int j=0;j<n;j++)  //continue是走下一个循环的意思 
       // bool asymptote=attack(j,n)   
           if(attack(j,n)){ 
               attacked=true;
               break;
           }    
        if(attacked) continue;
        if(n==7){ 
            for(int j=0;j<8;j++)
                cout<<pos[j]<<' ';
            cout<<endl;//当有一组输出时,n跑到7关系不大。 //Attention:要算一共有多少种可能，在这里设一个计数器就可以。 
        }else
           queen(n+1);//(queen(n+1,new_pos)
    }//delete [] new_pos;
}               
int main(){
    queen(0);
    char ch;
    cin>>ch;
    return 0;
} 

bool attack(int x,int y){
    if(pos[x]==pos[y])//不在同一行的两个皇后所在的列数相同，故能攻击到。 
       {return true;cout<<"asymptote";}
    if((pos[x]+x) == (pos[y]+y))//不在相当于y=-x的直线上。
       return true;
    if((pos[x]-x)==(pos[y]-y))
       return true;
    return false;
}    
