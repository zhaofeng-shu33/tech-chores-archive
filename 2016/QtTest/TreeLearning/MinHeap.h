/*
 * MinHeap.h
 *
 *  Created on: 2009-3-29
 *      Author: Admin
 */

#ifndef MINHEAP_H_
#define MINHEAP_H_

#include <iostream>
using namespace std;
const int MINHEAP_H_DefaultSize = 10;												//默认的堆大小为1000
//const int maxHeapSize = 10000;
struct element{
    int num;
    int x;
    int y;
    element(){}
    element(int n,int x1=0,int y1=0):num(n),x(x1),y(y1){}
    void operator =(const element& b){
        num=b.num;
        return;
    }
};

bool operator <=(element& a,element& b){
    return (a.num<=b.num);
}

template<class E>
class MinHeap//:public MinPQ<T,E>
{
public:
	MinHeap(int sz = MINHEAP_H_DefaultSize);										//构造函数：建立空堆
	MinHeap(E arr[], int n);														//构造函数：通过数组建立堆
	~MinHeap() { delete[] heap; }													//析构函数
	bool Insert(const E& x);														//将x插入到最小堆中
	bool RemoveMin(E& x);															//删除堆顶的最小元素
	bool IsEmpty() const { return (currentSize == 0) ? true : false;}				//判断堆是否为空
	bool IsFull() const { return (currentSize == maxHeapSize) ? true : false;}		//判断堆是否已满
	void MakeEmpty() { currentSize = 0; }											//将堆置空
	E getMin();																		//获取最小元素,但不改变堆
private:
	E *heap;																		//存放最小堆中元素的数组
	int currentSize;																//当前元素总个数
	int maxHeapSize;																//最多允许元素个数
	void siftDown(int start, int m);												//从start到m下滑调整成最小堆
	void siftUp(int start);															//从start到0上滑调整成最小堆
};

/*
 * 构造函数,在缺省范围内,构造容量为sz的堆
 */
template<class E>
MinHeap<E>::MinHeap(int sz) {
	maxHeapSize = (MINHEAP_H_DefaultSize < sz) ? sz : MINHEAP_H_DefaultSize;
	heap = new E[maxHeapSize];														//为堆分配存储空间
	if (heap == NULL) {std::cerr << "堆存储分配失败！" << std::endl; exit(1); }
	currentSize = 0;																//设定当前堆大小
};

/*
 * 构造函数，根据arr[]中的内容，构建一个最小堆。
 * 另外，n为元素个数
 */
template<class E>
MinHeap<E>::MinHeap(E arr[], int n)
{
	maxHeapSize = (MINHEAP_H_DefaultSize < n) ? n : MINHEAP_H_DefaultSize;
	heap = new E[maxHeapSize];
	if (heap == NULL) {std::cerr << "堆存储分配失败！" << std::endl; exit(1); }
	for (int i = 0; i < n; i++) heap[i] = arr[i];
	currentSize = n;																//复制堆数组，并设定堆大小
	int currentPos = (currentSize - 2) / 2;											//最初调整位置：最后的分支结点
	while (currentPos >= 0)															//从底向上逐步扩大形成堆
	{
		siftDown(currentPos, currentSize - 1);										//局部自上而下维护最小堆性质
		currentPos--;																//再向前换一个分支结点
	}
}

/*
 * 私有函数：从结点start开始到m为止，自上向下比较，如果子女的值小于father结点的值，
 * 则关键码小者上浮，继续向下层比较，这样将一个集合局部调整为最小堆。关键码比较符"<="在E中定义
 */
template<class E>
void MinHeap<E>::siftDown(int start, int m)
{
	int i = start;
	int j = 2 * i + 1;																//j是i的左子女位置
	E temp = heap[i];
	while (j <= m)																	//检查是否到达最后位置
	{
		if ((j < m) && (heap[j+1] <= heap[j])) j++;									//让j指向两子女中较小者
		if (temp <= heap[j]) break;													//根小不需要调整
		heap[i] = heap[j];															//否则小者上移，i,j相应下降
		i = j;
		j = 2 * j + 1;
	}
	heap[i] = temp;																	//回放temp中暂存元素
}

/*
 * 私有函数：从结点start开始到结点0结束，自下向上比较，如果子女的值小于父结点的值
 * 则互相交换，这样将集合重新调整为最小堆。关键码比较符"<="在E中定义
 */
template<class E>
void MinHeap<E>::siftUp(int start)
{
	int j = start;
	int i = (j - 1) / 2;
	E temp = heap[j];
	while (j > 0)																	//沿父结点路径向上直达根
	{
		if (heap[i] <= temp) break;													//不需要再调整,跳出
		heap[j] = heap[i];															//调整
		j = i;
		i = (j - 1) / 2;
	}
	heap[j] = temp;																	//回送tmep中暂存元素
}

/*
 * 公共函数， 将x插入到最小堆中
 */
template<class E>
bool MinHeap<E>::Insert(const E& x)
{
	if (currentSize == maxHeapSize)													//堆已经满了
	{
		std::cerr << "HeapFull" << std::endl;
		return false;
	}
	heap[currentSize] = x;															//插入元素

	siftUp(currentSize);															//向上调整
	currentSize++;																	//堆计数器加1
	return true;
}

/*
 * 删除最小值
 */
template<class E>
bool MinHeap<E>::RemoveMin(E& x)
{
	if (!currentSize) {																//堆已空，无法再删除，返回false
		std::cout << "Heap empty" << std::endl;
		return false;
	}

	x = heap[0];																	//记录下最小元素
	heap[0] = heap[--currentSize];													//最后元素填补到根结点
	siftDown(0, currentSize - 1);													//自上向下调整为堆
	return true;																	//返回删除成功
}

/*
 * 返回最小值
 */
template<class E>
E MinHeap<E>::getMin()
{
	return (heap[0]);
}

#endif /* MINHEAP_H_ */
