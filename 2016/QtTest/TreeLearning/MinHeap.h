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
const int MINHEAP_H_DefaultSize = 10;												//Ĭ�ϵĶѴ�СΪ1000
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
	MinHeap(int sz = MINHEAP_H_DefaultSize);										//���캯���������ն�
	MinHeap(E arr[], int n);														//���캯����ͨ�����齨����
	~MinHeap() { delete[] heap; }													//��������
	bool Insert(const E& x);														//��x���뵽��С����
	bool RemoveMin(E& x);															//ɾ���Ѷ�����СԪ��
	bool IsEmpty() const { return (currentSize == 0) ? true : false;}				//�ж϶��Ƿ�Ϊ��
	bool IsFull() const { return (currentSize == maxHeapSize) ? true : false;}		//�ж϶��Ƿ�����
	void MakeEmpty() { currentSize = 0; }											//�����ÿ�
	E getMin();																		//��ȡ��СԪ��,�����ı��
private:
	E *heap;																		//�����С����Ԫ�ص�����
	int currentSize;																//��ǰԪ���ܸ���
	int maxHeapSize;																//�������Ԫ�ظ���
	void siftDown(int start, int m);												//��start��m�»���������С��
	void siftUp(int start);															//��start��0�ϻ���������С��
};

/*
 * ���캯��,��ȱʡ��Χ��,��������Ϊsz�Ķ�
 */
template<class E>
MinHeap<E>::MinHeap(int sz) {
	maxHeapSize = (MINHEAP_H_DefaultSize < sz) ? sz : MINHEAP_H_DefaultSize;
	heap = new E[maxHeapSize];														//Ϊ�ѷ���洢�ռ�
	if (heap == NULL) {std::cerr << "�Ѵ洢����ʧ�ܣ�" << std::endl; exit(1); }
	currentSize = 0;																//�趨��ǰ�Ѵ�С
};

/*
 * ���캯��������arr[]�е����ݣ�����һ����С�ѡ�
 * ���⣬nΪԪ�ظ���
 */
template<class E>
MinHeap<E>::MinHeap(E arr[], int n)
{
	maxHeapSize = (MINHEAP_H_DefaultSize < n) ? n : MINHEAP_H_DefaultSize;
	heap = new E[maxHeapSize];
	if (heap == NULL) {std::cerr << "�Ѵ洢����ʧ�ܣ�" << std::endl; exit(1); }
	for (int i = 0; i < n; i++) heap[i] = arr[i];
	currentSize = n;																//���ƶ����飬���趨�Ѵ�С
	int currentPos = (currentSize - 2) / 2;											//�������λ�ã����ķ�֧���
	while (currentPos >= 0)															//�ӵ������������γɶ�
	{
		siftDown(currentPos, currentSize - 1);										//�ֲ����϶���ά����С������
		currentPos--;																//����ǰ��һ����֧���
	}
}

/*
 * ˽�к������ӽ��start��ʼ��mΪֹ���������±Ƚϣ������Ů��ֵС��father����ֵ��
 * ��ؼ���С���ϸ����������²�Ƚϣ�������һ�����Ͼֲ�����Ϊ��С�ѡ��ؼ���ȽϷ�"<="��E�ж���
 */
template<class E>
void MinHeap<E>::siftDown(int start, int m)
{
	int i = start;
	int j = 2 * i + 1;																//j��i������Ůλ��
	E temp = heap[i];
	while (j <= m)																	//����Ƿ񵽴����λ��
	{
		if ((j < m) && (heap[j+1] <= heap[j])) j++;									//��jָ������Ů�н�С��
		if (temp <= heap[j]) break;													//��С����Ҫ����
		heap[i] = heap[j];															//����С�����ƣ�i,j��Ӧ�½�
		i = j;
		j = 2 * j + 1;
	}
	heap[i] = temp;																	//�ط�temp���ݴ�Ԫ��
}

/*
 * ˽�к������ӽ��start��ʼ�����0�������������ϱȽϣ������Ů��ֵС�ڸ�����ֵ
 * ���ཻ�����������������µ���Ϊ��С�ѡ��ؼ���ȽϷ�"<="��E�ж���
 */
template<class E>
void MinHeap<E>::siftUp(int start)
{
	int j = start;
	int i = (j - 1) / 2;
	E temp = heap[j];
	while (j > 0)																	//�ظ����·������ֱ���
	{
		if (heap[i] <= temp) break;													//����Ҫ�ٵ���,����
		heap[j] = heap[i];															//����
		j = i;
		i = (j - 1) / 2;
	}
	heap[j] = temp;																	//����tmep���ݴ�Ԫ��
}

/*
 * ���������� ��x���뵽��С����
 */
template<class E>
bool MinHeap<E>::Insert(const E& x)
{
	if (currentSize == maxHeapSize)													//���Ѿ�����
	{
		std::cerr << "HeapFull" << std::endl;
		return false;
	}
	heap[currentSize] = x;															//����Ԫ��

	siftUp(currentSize);															//���ϵ���
	currentSize++;																	//�Ѽ�������1
	return true;
}

/*
 * ɾ����Сֵ
 */
template<class E>
bool MinHeap<E>::RemoveMin(E& x)
{
	if (!currentSize) {																//���ѿգ��޷���ɾ��������false
		std::cout << "Heap empty" << std::endl;
		return false;
	}

	x = heap[0];																	//��¼����СԪ��
	heap[0] = heap[--currentSize];													//���Ԫ����������
	siftDown(0, currentSize - 1);													//�������µ���Ϊ��
	return true;																	//����ɾ���ɹ�
}

/*
 * ������Сֵ
 */
template<class E>
E MinHeap<E>::getMin()
{
	return (heap[0]);
}

#endif /* MINHEAP_H_ */
