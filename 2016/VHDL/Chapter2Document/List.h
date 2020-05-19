#ifndef LIST_H
#define LIST_H
/*
本文件定义了单链表类模板List
*/
#include <cstdio>
template <class T>
struct LinkNode												//链表结点类的定义
{
	T data;													//数据域
	LinkNode<T> *link;										//链指针域
	LinkNode(LinkNode<T> *ptr=NULL) {link=ptr;}				//仅初始化指针成员的构造函数
	LinkNode(const T& item, LinkNode<T> *ptr=NULL)			//初始化数据与指针成员的构造函数
	{
		data=item;
		link=ptr;
	}
};

template <class T>
class List//:public LinearList<T>							//单链表类定义，此处没有使用继承
{
public:
	List(){first=new LinkNode<T>;}							//默认构造函数，构造一个空的单链表
	List(const T& x){first=new LinkNode<T>(x);}				//构造函数，构造一个仅含x一个元素的单链表
	List(List<T>& L);										//复制构造函数
	~List(){makeEmpty();}									//析构函数
	void makeEmpty();										//将链表置空
	int Length() const;										//计算链表的长度
	LinkNode<T> *getHead() const {return first;}			//返回附加头结点的地址
	LinkNode<T> *Search(T x);								//搜索含数据x的元素，返回第一个符合要求的结点的地址，若搜索失败则返回NULL
	LinkNode<T> *Locate(int i);								//定位第i个元素的地址，若定位失败则返回NULL
	bool getData(int i,T& x);								//取出第i个元素的值，若操作成功则返回true，否则返回false
	void setData(int i,T& x);								//用x修改第i个元素的值，若操作成功则返回true，否则返回false
	bool Insert(int i,T& x);								//在第i个元素后插入x，若操作成功则返回true，否则返回false
	bool Remove(int i,T& x);								//删除第i个元素，x返回该元素的值，若操作成功则返回true，否则返回false
	bool IsEmpty() const									//判表空，空则返回true，否则返回false
	{return first->link==NULL?true:false;}
	bool IsFull() const {return false;}						//判表满，满则返回true，否则返回false
	void output();											//输出链表，每个元素一行
protected:
	LinkNode<T> *first;										//链表的头指针
};

template <class T>
List<T>::List(List<T>& L)
//复制构造函数
{
	T value;
	LinkNode<T> *srcptr=L.getHead();						//源链表的附加头节点地址
	LinkNode<T> *destptr=first=new LinkNode<T>;				//新链表的附加头节点
	while (srcptr->link!=NULL)								//逐个结点复制
	{
		value=srcptr->link->data;
		destptr->link=new LinkNode<T>(value);
		destptr=destptr->link;
		srcptr=srcptr->link;
	}
	destptr->link=NULL;
}

template <class T>
void List<T>::makeEmpty()
//将链表置空
{
	LinkNode<T> *q;
	while (first->link!=NULL)								//当链表不空时，删去链中所有结点
	{
		q=first->link;										//从链上取下第一个结点
		first->link=q->link;								//表头后移
		delete q;											//删除该结点
	}
}

template <class T>
int List<T>::Length() const
//计算链表的长度
{
	LinkNode<T> *p=first->link;
	int count=0;
	while (p!=NULL)											//循链扫描，寻找链尾
	{
		p=p->link;count++;
	}
	return count;
}

template <class T>
LinkNode<T> *List<T>::Search(T x)
//搜索含数据x的元素，返回第一个符合要求的结点的地址，若搜索失败则返回NULL
{
	LinkNode<T> *current=first->link;
	while (current!=NULL)
		if (current->data==x) break;						//循链扫描，寻找含x结点
		else current=current->link;
	return current;
}

template <class T>
LinkNode<T> *List<T>::Locate(int i)
//定位第i个元素的地址，若定位失败则返回NULL
{
	if (i<0) return NULL;									//i不合理
	LinkNode<T> *current=first;int k=0;
	while (current!=NULL && k<i)							//循链找第i个结点
		{current=current->link;k++;}
	return current;											//返回第i个结点地址，否则返回NULL，表示i值太大
}

template <class T>
bool List<T>::getData(int i,T& x)
//取出第i个元素的值，若操作成功则返回true，否则返回false
{
	if (i<=0) return NULL;									//i值太小
	LinkNode<T> *current=Locate(i);
	if (current==NULL) return false;						//i值太大
	else {x=current->data;return true;}
}

template <class T>
void List<T>::setData(int i,T& x)
//用x修改第i个元素的值，若操作成功则返回true，否则返回false
{
	if (i<=0) return ;										//i值太小
	LinkNode<T> *current=Locate(i);
	if (current==NULL) return;								//i值太大
	else current->data=x;
}

template <class T>
bool List<T>::Insert(int i,T& x)
//在第i个元素后插入x，若操作成功则返回true，否则返回false
{
	LinkNode<T> *current=Locate(i);
	if (current==NULL) return false;						//插入不成功
	LinkNode<T> *newNode=new LinkNode<T>(x);
	if (newNode==NULL) {cerr<<"存储分配错误！"<<endl;exit(1);}
	newNode->link=current->link;							//链接在current之后
	current->link=newNode;
	return true;											//插入成功
}

template <class T>
bool List<T>::Remove(int i,T& x)
//删除第i个元素，x返回该元素的值，若操作成功则返回true，否则返回false
{
	LinkNode<T> *current=Locate(i-1);
	if (current==NULL || current->link==NULL) return false;	//删除不成功
	LinkNode<T> *del=current->link;							//重新拉链，将被删除结点从链中摘下
	current->link=del->link;
	x=del->data;delete del;									//取出被删除结点中的数据值
	return true;
}

template <class T>
void List<T>::output()
//输出链表，每个元素一行
{
	LinkNode<T> *current=first->link;
	while (current!=NULL)
	{
		cout << current->data <<endl;
		current=current->link;
	}
}

#endif