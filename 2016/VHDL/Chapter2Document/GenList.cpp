#include <iostream>
#include <ostream>
#include <fstream>
#include <cmath>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#include<string> 
#include<queue>
#include<deque> 
#include "seqList.h"
using namespace std;
template <class T>
struct GenListNode {	          //广义表结点类定义
     int utype;			//＝0 / 1 / 2
     GenListNode<T> *tlink;	//同层下一结点指针
     union {				//等价变量
       int ref;	                     //存放引用计数
	     T value;			//存放数值
		   GenListNode<T> *hlink;	
      }info;  //存放子表指针	
     GenListNode(): utype(0),tlink(NULL){info.ref=0;}
     GenListNode(GenListNode<T>& R) {
     //复制构造函数
          utype = R.utype;   tlink = R.tlink; 
          info = R.info;
     }
};
template <class T>
class GenList{			  //广义表类定义
public:
     GenList();			          //构造函数
     ~GenList(){}			//析构函数 
     bool Head (GenListNode<T>& x);	   //x 返回表头元素
     bool Tail (GenList<T>& lt);	   //lt 返回表尾
     GenListNode<T> *First();	   //返回第一个元素
     GenListNode<T> *Next (GenListNode<T> *elem);
	//返回表元素elem的直接后继元素
     void Copy ( const GenList<T>& R);
	//广义表的复制
     int Length();    		          //计算广义表长度
     int depth();			//计算非递归表深度   
     void print();  
     void initialize(queue<T>& in){
     int n=8;
     SeqList<T> Ls1(n);
	   SeqList<GenListNode<T>*> Ls2(n);    
     //cout <<"输入广义表的字符串描述:"<< endl;
     CreateList (in,first,Ls1,Ls2);	//建立存储结构
     GenListNode<T> *p = first;
     first = first->info.hlink;
     delete p;
     }
public:
     GenListNode<T> *first;	//广义表头指针
     GenListNode<T> *Copy (GenListNode<T> *ls);
        //复制一个ls指示的无共享非递归表
     int Length (GenListNode<T> *ls);
        //求由ls指示的广义表的长度
     int depth (GenListNode<T> *ls);		
        //计算由ls指示的非递归表的深度
     void print(GenListNode<T>* ls,deque<T>& in);
     bool equal (GenListNode<T> *s, 
             GenListNode<T> *t);
       //判以s和t为表头的两个表是否相等
     void Remove (GenListNode<T> *ls);
       //释放以ls为附加头结点的广义表
     void CreateList (queue<T>& in, 
           GenListNode<T> *&ls, SeqList<T>& L1, SeqList <GenListNode<T> *>& L2);
        //从输入流对象输入广义表的字符串描述, 
        //建立一个带头结点的广义表结构
    };
template <class T>
class Complex{
  public:
    Complex(T n10,T n20){n1=n10;n2=n20;}
    T n1,n2;
    friend ostream& operator << (ostream& out, Complex<T> L){
      out<<L.n1<<' '<<L.n2;
      return out;           
    }  
};
int main(){
 char in[]="D(a,B(b,c),e,f);";
 int len=strlen(in);
 queue<char> myqueue;
 for(int i=0;i<len;i++)
    myqueue.push(in[i]);
  cout<<endl;  
  GenList<char> myGenList;
  myGenList.initialize(myqueue);
  cout<<"LENGTH:"<<' '<<myGenList.Length()<<endl;
  //cout<<myGenList.first->tlink->info.value<<endl;
  myGenList.print();
  cout<<endl;
  GenList<char> yourGenList;
  cout<<myGenList.Tail(yourGenList)<<endl;
  cout<<myGenList.depth()<<endl; 
  return 0;
}
template <class T>
GenList<T>::GenList(){		//构造函数
     first = new GenListNode<T>;
     if(first == NULL)
     { cerr <<"存储分配失败！\n";  exit(1); 
         }	
};

template <class T>
bool GenList<T>::Head (GenListNode<T>& x) {
if (first->tlink == NULL) return false;	//空表
	 else {						//非空表
          x.utype = first->tlink->utype;
		x.info = first->tlink->info;
    x.tlink=first->tlink->tlink;
		return true;		                 //x返回表头的值
	 }
};
template <class T>
bool GenList<T>::Tail(GenList<T>& lt) {
//若广义表非空，则通过lt返回广义表除表头元素
//以外其他元素组成的表，否则函数没有定义
     if (first->tlink == NULL) return false;	    //空表
     else { 				//非空表
          lt.first->utype = 0;		//设置头结点
          lt.first->info.ref = 0;
         // cout<<"DEBUG"<<first->tlink->tlink->utype;
          lt.first->tlink = Copy(first->tlink->tlink); //跨表头
          return true; 
   	}
};


template <class T>
void GenList<T>::CreateList(queue<T>& in, GenListNode<T> *& ls, SeqList<T>& L1, SeqList <GenListNode<T> *>& L2) {
//从广义表的字符串描述 s 出发, 建立一个带头结
//点的广义表，要求T为char类型。在表L1存储大
//写字母的表名, 在表L2存储表名对应子表结点的
//地址。
     if(in.empty())return;
     T chr; 
     chr=in.front();in.pop();
       //读入一个字符，只可能读入#、左括号和字母
     if (isalpha(chr) && isupper(chr) || chr == '(') {	
      //大写字母或'('
          ls = new GenListNode<T>;         //建子表结点
          ls->utype = 2;		
          if (isalpha(chr) && isupper(chr)) {  //表名处理
               int n = L1.Length();
               int m = L1.Search(chr);
               if (m != 0) {                  //该表已建立
                    GenListNode<T> *p;
                    L2.getData(m,p);		            //查子表地址
		          p->info.ref++;		//引用计数加一
	        } 	
               else {       //该表未建立
                    L1.Insert(n, chr);  L2.Insert(n, ls);	
                              //保存表名及地址
               }
               chr=in.front();in.pop();
               if (chr != '(') exit(1);	           //表名后必跟'('
          }
          ls->info.hlink = new GenListNode<T>; 
          ls->info.hlink->utype = 0;         //建头结点
          ls->info.hlink->info.ref = 1;
	        CreateList(in, ls->info.hlink->tlink, L1, L2);
             //递归建子表
	        CreateList(in, ls, L1, L2);         //递归建后继表
      }
     else if (isalpha(chr) && islower(chr)) {	
          //建原子结点
          ls = new GenListNode<T>;
          ls->utype = 1;  ls->info.value = chr;
		       CreateList(in, ls, L1, L2);
     }
     else if (chr == ',') 		//建后继结点
          CreateList(in, ls->tlink, L1, L2); 
     else if (chr == ')') ls->tlink = NULL;  //链收尾
     else if (chr =='#') ls == NULL;	    //空表, 链收尾
}
template <class T>                 //公有函数
void GenList<T>::Copy(const GenList<T>& R) { 
     first = Copy(R.first);          //调用私有函数
};
template <class T>                 //私有函数
GenListNode<T>* GenList<T>::Copy(GenListNode <T> *ls) {
//复制一个 ls 指示的无共享子表的非递归表
     GenListNode<T> *q=NULL;
     if (ls != NULL) {
         q= new GenListNode<char>; 
          //处理当前的结点q
          q->utype = ls->utype;	  //复制结点类型
	      	switch (ls->utype) {	  //根据utype传送信息
              case 0: q->info.ref = ls->info.ref;  break;	
              case 1: q->info.value = ls->info.value;  break;
         	    case 2: q->info.hlink = Copy(ls->info.hlink); break;
     	    }
    	
          q->tlink = Copy(ls->tlink);  //处理同层下一结点
     }
     return q;
};
template <class T>
GenListNode<T> *GenList<T>::First() {
//返回广义表的第一个元素（若表空，则返回一个
//特定的空值NULL）	
     if (first->tlink == NULL) return NULL;    //空表
     else return first->tlink;	 	 //非空表
};
template <class T>
GenListNode<T> *GenList<T>::Next(GenListNode<T> *elem) {
//返回表元素elem的直接后继元素
     if (elem->tlink == NULL) return NULL;
	 else return elem->tlink;
};
template <class T>
int GenList<T>::depth() {             //公有函数
//计算一个非递归表的深度
     return depth(first);
};

template <class T>                      //私有函数
int GenList<T>::depth(GenListNode<T> *ls) {
     if (ls->tlink == NULL) return 1;		
      // ls->tlink ==NULL, 空表，深度为1
	 GenListNode<T> *temp = ls->tlink;  
     int m = 0, n;
while (temp != NULL) {	//在广义表顶层横扫
          if (temp->utype == 2) {	   //扫描到表结点 
               n = depth(temp->info.hlink);	
                //递归计算子表深度
              if (m < n) m = n;	   //取最大深度
          }
		temp = temp->tlink;
     }
     return m+1;			  //返回深度
};
template <class T>
void GenList<T>::print(){
    cout<<'(';
    deque<T> in;
    print(first,in);
    while(!in.empty()){
      cout<<in.front();in.pop_front();
    }  
    cout<<')';
}
template <class T>
void GenList<T>::print(GenListNode<T>* ls,deque<T>& in){
  if(ls->tlink==NULL) return;
  GenListNode<T> *temp=ls->tlink;
  while(temp!=NULL&&temp->utype==1) {
        in.push_back(temp->info.value);
        in.push_back(',');        
        temp=temp->tlink;
      }
  in.pop_back();
  if(temp!=NULL){
    if(temp->utype==2) {
      //if(in.back()!='(')in.push_back(',');
      in.push_back('(');
      print(temp->info.hlink,in);
      in.push_back(')');
    }  
    print(temp,in);     
  }    
}      
template <class T>
int GenList<T>::Length(){
  GenListNode<T>* p=first;
  int cnt=0;
//  if(first->tlink==NULL)return cnt;
  while(p->tlink!=NULL)
     {cnt++;p=p->tlink;}
  return cnt;
}
