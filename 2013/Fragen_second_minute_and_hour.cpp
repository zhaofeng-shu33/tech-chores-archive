#include <iostream>
#include <stdlib.h> 
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;
double grd_trans(string str){
  if(str=="A+")return 4;
  if(str=="A=")return 4;
  if(str=="A-")return 3.7;
  if(str=="B+")return 3.3;
  if(str=="B=")return 3;
  if(str=="B-")return 2.7;
  if(str=="C+")return 2.3;
  if(str=="C=")return 2;
  if(str=="C-")return 1.7;
  if(str=="D+")return 1.3;
  if(str=="D=")return 1;
  return 0; 
}  
struct student{
  double GPA;
  int total_grd;
  student(){GPA=-1;total_grd=0;} 
};  
struct LinkNode												//链表结点类的定义
{
	int type;													//数据域
  double value;
	LinkNode *link;										//链指针域
	LinkNode(){LinkNode *ptr=NULL;}
	LinkNode(const int& tp,const double& vl, LinkNode *ptr=NULL)			//初始化数据与指针成员的构造函数
	{
      type=tp;
      value=vl;
  		link=ptr;
	}
};
class ListWithTail{
public:
  LinkNode* first;
  LinkNode* last;
	ListWithTail(){first=new LinkNode;last=first;}							//默认构造函数，构造一个空的单链表
  void Insert(int x,double y){
   			LinkNode* p=new LinkNode(x,y);	
   			last->link=p;
   			last=last->link;
   }
   void Print(){
      first=first->link;
      while(first!=NULL){
      if(first->type==0) cout<<int(first->value)<<endl;
      else{  double a=first->value;
      int b=100-int(100-a*10);
       cout<<b/10.0<<endl;
 }  
      first=first->link;
      }
   }      			
};

int main(){
  int n,m;
  cin>>n>>m;
  int istr;
  int stu_no,grd;
  string level;
  double gpa;
  if(n==1){
      double* GPA=new double[m];
      int* score=new int[m];
      int sum=0;
      for(int i=0;i<m-1;i++){
          cin>>istr>>stu_no>>grd>>level;
          GPA[i]=grd_trans(level);
          score[i]=grd;
          sum+=grd;
      }
      cin>>istr;
      cin>>stu_no;
      double avr=0;
      for(int i=0;i<m-1;i++)
          avr+=score[i]*GPA[i]/sum;  
      cout<<setiosflags(ios::fixed)<<setprecision(1)<<ceil(avr*10)/10.0<<endl;
      
      return 0;
   }  
      
  
  
  student* stu=new student[n+1]; 
  ListWithTail myoutput;
  for(int i=0;i<m;i++){
     cin>>istr;
     if(istr==1){
        cin>>stu_no>>grd>>level;
        stu[stu_no].total_grd+=grd;
        stu[stu_no].GPA=grd*1.0*grd_trans(level)/stu[stu_no].total_grd+(1-grd*1.0/stu[stu_no].total_grd)*stu[stu_no].GPA;
        stu[stu_no].GPA=ceil(stu[stu_no].GPA*10)/10.0;
     }
     if(istr==2){
        cin>>stu_no;
        myoutput.Insert(1,stu[stu_no].GPA);
        //cout<<setiosflags(ios::fixed)<<setprecision(1)<<stu[stu_no].GPA<<endl;
      }
     if(istr==3){
        cin>>gpa;
        int num=0;
        for(int i=1;i<=n;i++)
            if(stu[i].GPA==gpa)
               num++;
        myoutput.Insert(0,num);
       // cout<<num<<endl;
       }     
     }    
     
    myoutput.Print();   
   
   return 0;
}

