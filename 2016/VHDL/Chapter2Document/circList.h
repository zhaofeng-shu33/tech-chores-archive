#ifndef CIRCLIST_H
#define CIRCLIST_H
/*
本文件定义了循环链表类模板CircList
*/
#include <cstdio>
#include <cstdlib>
template <class T>
struct CircLinkNode														//循环链表结点类的定义
{
	T data;																//数据域
	CircLinkNode<T> *link;												//链指针域
	CircLinkNode(CircLinkNode<T> *next=NULL):link(next){}				//仅初始化指针成员的构造函数
	CircLinkNode(T d,CircLinkNode<T> *next=NULL):data(d),link(next){}	//初始化数据与指针成员的构造函数
};

template <class T>
class CircList//: public LinearList<T>									//循环链表类定义，此处没有使用继承
{
public:
	CircList();															//默认构造函数，构造一个空的循环链表
	CircList(const T& x);												//构造函数，构造一个仅含x一个元素的循环链表
	CircList(CircList<T>& L);											//复制构造函数
	~CircList();														//析构函数
	void makeEmpty();													//将链表置空
	int Length() const;													//计算链表的长度
	bool IsEmpty()														//判表空，空则返回true，否则返回false
	{
		return first->link==first?true:false;
	}
	CircLinkNode<T> *getHead(){return first;}							//返回附加头结点的地址
	CircLinkNode<T> *Search(T x);										//搜索含数据x的元素，返回第一个符合要求的结点的地址，若搜索失败则返回NULL
	CircLinkNode<T> *Locate(int i);										//定位第i个元素的地址，若定位失败则返回NULL
	bool getData(int i, T& x);											//取出第i个元素的值，若操作成功则返回true，否则返回false
	void setData(int i, T& x);											//用x修改第i个元素的值，若操作成功则返回true，否则返回false
	bool Insert(int i, T& x);											//在第i个元素后插入x，若操作成功则返回true，否则返回false
	bool Remove(int i, T& x);											//删除第i个元素，x返回该元素的值，若操作成功则返回true，否则返回false
	void output() const;												//输出链表，每个元素一行
private:
	CircLinkNode<T> *first, *last;										//链表的头指针，尾指针
	friend class Polynomial;											//将Polynomial类设为友元
};

template <class T>
CircList<T>::CircList()
//默认构造函数，构造一个空的循环链表
{
	first=new CircLinkNode<T>;
	first->link=first;
	last=first;
}

template <class T>
CircList<T>::CircList(const T& x)
//构造函数，构造一个仅含x一个元素的循环链表
{
	first=new CircLinkNode<T>;
	last=new CircLinkNode<T>(x);
	first->link=last;
	last->link=first;
}

template <class T>
CircList<T>::CircList(CircList<T>& L)
//复制构造函数
{
	T value;
	CircLinkNode<T> *srcptr=L.getHead();								//源链表的附加头节点地址
	CircLinkNode<T> *destptr=first=new CircLinkNode<T>;					//新链表的附加头节点
	while (srcptr->link!=L.getHead())									//逐个结点复制
	{
		value=srcptr->link->data;
		destptr->link=new CircLinkNode<T>(value);
		destptr=destptr->link;
		srcptr=srcptr->link;
	}
	destptr->link=first;
	last=destptr;
}

template <class T>
CircList<T>::~CircList()
//析构函数
{
	makeEmpty();
}

template <class T>
void CircList<T>::makeEmpty()
//将链表置空
{
	CircLinkNode<T> *q;
	while (first->link!=first)											//当链表不空时，删去链中所有结点
	{
		q=first->link;													//从链上取下第一个结点
		first->link=q->link;											//表头后移
		delete q;														//删除该结点
	}
}

template <class T>
int CircList<T>::Length() const
//计算链表的长度
{
	CircLinkNode<T> *p=first->link;
	int count=0;
	while (p!=first)													//循链扫描，直到回到表头
	{
		p=p->link;count++;
	}
	return count;
}

template <class T>
CircLinkNode<T> *CircList<T>::Search(T x)
//搜索含数据x的元素，返回第一个符合要求的结点的地址，若搜索失败则返回NULL
{
	CircLinkNode<T> *current=first->link;
	while (current!=first)
		if (current->data==x) break;									//循链扫描，寻找含x结点
		else current=current->link;
	return current;
}

template <class T>
CircLinkNode<T> *CircList<T>::Locate(int i)
//取出第i个元素的值，若操作成功则返回true，否则返回false
{
	if (i<0) return NULL;												//i不合理
	CircLinkNode<T> *current=first->link;int k=1;
	while (current!=first && k<i)										//循链找第i个结点
		{current=current->link;k++;}
	if (i>0 && current==first) return NULL;								//返回第i个结点地址，否则返回NULL，表示i值太大
	else return current;
}

template <class T>
bool CircList<T>::getData(int i,T& x)
//取出第i个元素的值，若操作成功则返回true，否则返回false
{
	if (i<=0) return NULL;												//i值太小
	CircLinkNode<T> *current=Locate(i);
	if (current==NULL) return false;									//i值太大
	else {x=current->data;return true;}
}

template <class T>
void CircList<T>::setData(int i,T& x)
//用x修改第i个元素的值，若操作成功则返回true，否则返回false
{
	if (i<=0) return ;													//i值太小
	CircLinkNode<T> *current=Locate(i);
	if (current==NULL) return;											//i值太大
	else current->data=x;
}

template <class T>
bool CircList<T>::Insert(int i,T& x)
//在第i个元素后插入x，若操作成功则返回true，否则返回false
{
	CircLinkNode<T> *current=Locate(i);
	if (current==NULL) return false;									//插入不成功
	CircLinkNode<T> *newNode=new CircLinkNode<T>(x);
	if (newNode==NULL) {cerr<<"存储分配错误！"<<endl;exit(1);}
	newNode->link=current->link;										//链接在current之后
	current->link=newNode;
	return true;														//插入成功
}

template <class T>
bool CircList<T>::Remove(int i,T& x)
//删除第i个元素，x返回该元素的值，若操作成功则返回true，否则返回false
{
	CircLinkNode<T> *current=Locate(i-1);
	if (current==NULL) return false;									//删除不成功
	CircLinkNode<T> *del=current->link;									//重新拉链，将被删除结点从链中摘下
	current->link=del->link;
	x=del->data;delete del;												//取出被删除结点中的数据值
	return true;
}

template <class T>
void CircList<T>::output() const
//输出链表，每个元素一行
{
	CircLinkNode<T> *current=first->link;
	while (current!=first)
	{
		cout << current->data <<endl;
		current=current->link;
	}
}

#endif