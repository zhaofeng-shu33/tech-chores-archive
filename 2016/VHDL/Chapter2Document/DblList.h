#ifndef DBLLIST_H
#define DBLLIST_H
/*
本文件定义了双链表类模板DblList
*/
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
template <class T>
struct DblNode																								//链表结点类定义
{
	T data;																									//链表结点数据
	DblNode<T> *lLink, *rLink;																				//链表前驱（左链）、后继（右链）指针
	DblNode(DblNode<T> *left=NULL,DblNode<T> *right=NULL):lLink(left),rLink(right){}						//仅初始化指针的构造函数
	DblNode(T value, DblNode<T> *left=NULL, DblNode<T> *right=NULL):data(value),lLink(left),rLink(right){}	//初始化指针和数据的构造函数
};

template <class T>
class DblList//:public Linear List<T>																		//双链表类定义，此处没有用继承
{
public:
	DblList();																								//默认构造函数：构造空表（包括附加头结点）
	DblList(T uniqueVal);																					//构造函数：构造仅含一个元素uniqueVal的表（包括附加头结点）
	~DblList();																								//析构函数
	int Length() const;																						//计算双链表的长度
	bool IsEmpty() {return first->rlink==first;}															//判断表空，空则返回true，否则返回false
	DblNode<T> *getHead() const {return first;}																//取附加头结点的地址
	DblNode<T> *Search(const T& x);																			//在链表中沿后继方向找x元素
	DblNode<T> *Locate(int i,int d);																		//定位第i个结点的地址，d=0按前驱方向，否则按后继方向，操作失败则返回NULL
	bool Insert(int i, const T& x, int d);																	//在第i个结点后插入一个包含x元素的新结点，d=0按前驱方向，否则按后继方向，操作成功返回true，否则返回false
	bool Remove(int i,T& x, int d);																			//删除第i个结点，x返回其值，d=0按前驱方向，否则按后继方向，操作成功返回true，否则返回false
private:
	DblNode<T> *first;																						//附加头结点
};

template <class T>
DblList<T>::DblList()
//默认构造函数：构造空表（包括附加头结点）
{
	first=new DblNode<T>();
	if (first==NULL) {cerr<<"存储分配出错！"<<endl;exit(1);}
	first->rLink=first->lLink=first;
}

template <class T>
DblList<T>::DblList(T uniqueVal)
//构造函数：构造仅含一个元素uniqueVal的表（包括附加头结点）
{
	first=new DblNode<T>;
	if (first==NULL) {cerr<<"存储分配出错！"<<endl;exit(1);}
	DblNode<T> *ptr=new DblNode<T>(uniqueVal);
	if (ptr==NULL) {cerr<<"存储分配出错！"<<endl;exit(1);}
	first->rLink=ptr;
	first->lLink=ptr;
	ptr->rLink=first;
	ptr->lLink=first;
}

template <class T>
DblList<T>::~DblList()
//析构函数
{
	DblNode<T> *q;
	while (first->lLink!=first)
	{
		q=first->lLink;
		first->lLink=q->lLink;
		delete q;
	}
}

template <class T>
int DblList<T>::Length() const
//计算双链表的长度
{
	DblNode<T> *current=first->rLink;
	int count=0;
	while (current!=first){current=current->rLink;count++;}
	return count;
}

template <class T>
DblNode<T> *DblList<T>::Search(const T& x)
//在链表中沿后继方向找x元素
{
	DblNode<T> *current=first->rLink;
	while (current!=first && current->data!=x)
		current=current->rLink;
	if (current!=first) return current;
	else return NULL;
}

template <class T>
DblNode<T> *DblList<T>::Locate(int i, int d)
//定位第i个结点的地址，d=0按前驱方向，否则按后继方向，操作失败则返回NULL
{
	if (first->rLink==first || i==0) return first;
	DblNode<T> *current;
	if (d==0) current=first->lLink;
	else current=first->rLink;
	for (int j=1;j<i;j++)
		if (current==first) break;
		else if (d==0) current=current->lLink;
			 else current=current->rLink;
	if (current!=first) return current;
	else return NULL;
}

template <class T>
bool DblList<T>::Insert(int i, const T& x, int d)
//在第i个结点后插入一个包含x元素的新结点，d=0按前驱方向，否则按后继方向，操作成功返回true，否则返回false
{
	DblNode<T> *current=Locate(i,d);
	if (current==NULL) return false;
	DblNode<T> *newNode=new DblNode<T>(x);
	if (newNode==NULL) {cerr<<"存储分配失败！"<<endl;exit(1);}
	if (d==0)
	{
		newNode->lLink=current->lLink;
		current->lLink=newNode;
		newNode->lLink->rLink=newNode;
		newNode->rLink=current;
	}
	else
	{
		newNode->rLink=current->rLink;
		current->rLink=newNode;
		newNode->rLink->lLink=newNode;
		newNode->lLink=current;
	}
	return true;
}

template <class T>
bool DblList<T>::Remove(int i, T &x, int d)
//删除第i个结点，x返回其值，d=0按前驱方向，否则按后继方向，操作成功返回true，否则返回false
{
	DblNode<T> *current=Locate(i,d);
	if (current==NULL) return false;
	current->rLink->lLink=current->lLink;
	current->lLink->rLink=current->rLink;
	x=current->data;
	delete current;
	return true;
}

#endif