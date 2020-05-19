#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
/*
本文件定义了用循环链表实现的一元多项式类Polynomial
*/
#include "circList.h"
#include <iostream>
using namespace std;
struct Term														//多项式中的项
{
	float coef;													//系数
	int exp;													//指数
	friend ostream& operator << (ostream &, const Term&);		//按自然习惯输出项x
};

ostream& operator << (ostream& out, const Term& x)
//按自然习惯输出项x
{
	if (x.coef==0.0) return out;								//该项为0，不输出
	out << x.coef;												//输出系数
	switch(x.exp)
	{
		case 0:break;											//指数为0，省略"X"
		case 1:out << "X"; break;								//指数为1，省略"^1"
		default:out << "X^" << x.exp; break;					//完整输出
	}
	return out;
}

class Polynomial												//用循环链表实现的多项式类
{
public:
	Polynomial() {}												//默认构造函数
	Polynomial(Polynomial& R):p(R.p){}							//复制构造函数
/*
	int maxOrder()												
	{
		if (p.IsEmpty()) return 0;
		else return p.last->data.exp; 
	}
*/
	float calc(float x);										//计算该多项式在x处的值
private:
	CircList<Term> p;											//循环链表，表示多项式
	friend ostream& operator<< (ostream&, Polynomial&);			//重载输出符号
	friend istream& operator>> (istream&, Polynomial&);			//重载输入符号
//	friend Polynomial operator+ (Polynomial&, Polynomial&);
//	friend Polynomial operator* (Polynomial&, Polynomial&);
};

ostream& operator<< (ostream& out, Polynomial& x)				//重载输出符号<<，按自然习惯输出x
{
	cout << "The polynomial is:" << endl;
	for (int i=1;i<=x.p.Length();i++)
	{
		Term current=(x.p.Locate(i))->data;
		if (i!=1 && current.coef>0.0) out << "+";
		out << current;											//输出当前项
	}
	out << endl;
	return out;
}


istream& operator >> (istream& in, Polynomial& x)				//重载输入符号>>
{
	x.p.makeEmpty();											//先将链表置空
	int cnt=0;
	while (1)
	{
		float c;
		int e;
		cout << "Input a term (coef, exp):" << endl;
		in >> c >> e;											//输入当前项的系数和指数
		if (e<0) break;											//以指数e<0为终止标志
		Term t;
		t.coef=c;
		t.exp=e;
		x.p.Insert(cnt,t);										//插入一项
		cnt++;
	}
	return in;
}

float Polynomial::calc(float x)									//计算多项式在x处的值
{
/*

作业2.24内容

*/
}

#endif