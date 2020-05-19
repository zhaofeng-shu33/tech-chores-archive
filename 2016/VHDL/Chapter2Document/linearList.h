#ifndef LINEARLIST_H
#define LINEARLIST_H
/*
本文件定义了线性表的抽象基类模板LinearList
*/
template <class T>
class LinearList
{
public:
	LinearList(){}								//构造函数
	~LinearList(){}								//析构函数
	virtual int Size() const=0;					//求表最大体积
	virtual int Length() const=0;				//求表长度
	virtual int Search(T& x) const=0;			//在表中搜索给定值x
	virtual int Locate(int i) const=0;			//在表中定位第i个元素位置
	virtual bool getData(int i, T& x) const=0;	//取第i个表项的值到x，若操作成功则返回true，否则返回false
	virtual void setData(int i, T& x)=0;		//修改第i个表项的值为x
	virtual bool Insert(int i, T x)=0;			//在第i个表项后插入x，若操作成功则返回true，否则返回false
	virtual bool Remove(int i, T& x)=0;			//删除第i个表项，通过x返回该表项，若操作成功则返回true，否则返回false
	virtual bool IsEmpty() const=0;				//判表空
	virtual bool IsFull() const=0;				//判表满
	virtual void output() const=0;				//输出该线性表，每个元素一行
};
#endif
