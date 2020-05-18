#include<iostream>
#include<fstream>
using namespace std;
int N=0;
int step=1;
void hanoi_move(int,char,char,char);
void move(int m,char A,char B,char C){
    if(m==1){
    cout<<step<<' '<<A<<"->"<<C<<endl;
    step++;
    }
    else{
     move(m-1,A,C,B);
     cout<<step<<' '<<A<<"->"<<C<<endl; step++;
     move(m-1,B,A,C);
    }   
}       
int main(){
    N=4;
    hanoi_move(4,'A','B','C');
    char ch;
    cin>>ch;
    return 0;
}
//C++ code of my teacher.
void hanoi_move(int n,char from,char to,char tmp){//tmp作中转 一个参数太少。 //n代表挪1~n号的盘子。 
    if(n==0) //调3次hanoi_move输出3行。 
      return;  
   //加初值 
    hanoi_move(n-1,from,tmp,to);
    cout<<cout<<N-n<<':'<<from<<"->"<<to<<endl;
    hanoi_move(n-1,tmp,to,from);//输出现在在挪第几个盘子。 
}    
