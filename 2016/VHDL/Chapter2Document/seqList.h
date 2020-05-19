#ifndef SEQ_LIST
#define SEQ_LIST
/*
本文件定义了顺序表类模板SeqList
*/
#include "linearList.h"
#include <cstdio>
const int defaultSize=100;
template <class T>
class SeqList: public LinearList<T>
{
protected:
	T* data;																//存放数组
	int maxSize;															//最大可容纳表项个数
	int last;																//当前已存表项的最后位置（从0开始）
	void reSize(int newSize);												//改变data数组空间大小
public:
	SeqList(int sz=defaultSize);											//构造函数，sz为表最大可容纳表项个数
	SeqList(SeqList<T>& L);													//复制构造函数
	~SeqList(){delete[] data;}												//析构函数
	int Size() const {return maxSize;}										//计算表最大可容纳表项个数
	int Length() const {return last+1;}										//计算表长度
	int Search(T& x) const;													//搜索x在表中位置，函数返回表项序号
	int Locate(int i) const;												//定位第i个表项，函数返回表项序号
	bool getData(int i, T& x) const											//取第i个表项的值，若操作成功则返回true，否则返回false
		{if (i>0 && i<=last+1){x=data[i-1]; return true;} else return false;}
	void setData(int i, T& x)												//用x修改第i个表项的值												
		{if (i>0 && i<=last+1) data[i-1]=x;}
	bool Insert(int i, T x);												//插入x在第i个表项之后，若i==0则插在表头，若操作成功则返回true，否则返回false
	bool Remove(int i, T& x);												//删除第i个表项，通过x返回该表项的值，若操作成功则返回true，否则返回false
	bool IsEmpty() const {return (last==-1)?true:false;}					//判表空，空则返回true，否则返回false
	bool IsFull() const {return (last==maxSize-1)?true:false;}				//判表满，满则返回true，否则返回false
	void output() const;													//输出，每个元素一行
};

template <class T>
SeqList<T>::SeqList(int sz)
//构造函数，sz为表最大可容纳表项个数
{
	if (sz>0){
		maxSize=sz;
		last=-1;															//置表的初始长度为0
		data=new T[maxSize];												//创建顺序表存储数组
		if (data==NULL)														//动态分配失败
			{cerr << "存储分配错误！" << endl;	exit(1);}
	}
}

template <class T>
SeqList<T>::SeqList(SeqList<T>& L)
//复制构造函数
{
	maxSize=L.Size();
	last=L.Length()-1;
	data=new T[maxSize];
	if (data==NULL)															//创建顺序表存储数组
		{cerr << "存储分配错误！" << endl;	exit(1);}
	for (int i=1;i<=last+1;i++)
		data[i-1]=L.getData(i);
}

template <class T>
void SeqList<T>::reSize(int newSize)
//改变data数组空间大小为newSize
{
	if (newSize<=0)															//检查参数的合理性
		{cerr << "无效的数组大小" << endl;	return;}
	if (newSize!=maxSize){													//若数组空间大小有变化，则修改
		T* newarray=new T[newSize];											//建立新数组
		if (newarray == NULL)
		{cerr<<"存储分配错误"<<endl;	exit(1);}
		int n=last+1;
		T* srcptr=data;														//源数组首地址
		T* destptr=newarray;												//目的数组首地址
		while(n--) *destptr++=*srcptr++;									//复制
		delete [] data;														//删除源数组
		data=newarray;														//复制新数组
		maxSize=newSize;
	}
}

template <class T>
int SeqList<T>::Search(T& x) const
//搜索x在表中位置，函数返回表项序号，若搜索失败则返回0
{
	for (int i=0;i<=last;i++)
		if (data[i]==x) return i+1;											//顺序搜索
	return 0;																//搜索失败
}

template <class T>
int SeqList<T>::Locate(int i) const
//定位第i个表项，函数返回表项序号，若定位失败则返回0
{
	if (i>=1 && i<=last+1) return i;
	else return 0;
}

template <class T>
bool SeqList<T>::Insert(int i,T x)
//插入x在第i个表项之后，若i==0则插在表头，若操作成功则返回true，否则返回false
{
	if (last==maxSize-1) return false;										//表满，不能插入
	if (i<0 || i>last+1) return false;										//参数i不合理，不能插入
	for (int j=last;j>=i;j--)
		data[j+1]=data[j];													//依次后移，空出第i号位置
	data[i]=x;																//插入
	last++;																	//表长加1
	return true;															//插入成功
}

template <class T>
bool SeqList<T>::Remove(int i,T& x)
//删除第i个表项，通过x返回该表项的值，若操作成功则返回true，否则返回false
{
	if (last==-1) return false;												//表空不能删除
	if (i<1||i>last+1) return false;										//参数i不合理，不能删除
	x=data[i-1];															//保存被删除元素
	for (int j=i;j<=last;j++)
		data[j-1]=data[j];													//依次前移，填补空缺
	last--;																	//表长减1
	return true;															//删除成功
}

template <class T>
void SeqList<T>::output() const
//输出，每个元素一行
{
	for (int i=1;i<=Length();i++)
	{
		T te;
		getData(i,te);														//获取第i个元素
		cout << te << endl;													//输出并换行
	}
}
#endif
