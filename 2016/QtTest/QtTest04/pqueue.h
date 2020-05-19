#ifndef PQUEUE_H
#define PQUEUE_H
#include <assert.h>
template <class T>
class PQueue
{
public:
     PQueue(int sz = 50){
         maxPQSize = sz;  count = 0;
         pqelements = new T[maxPQSize];
         assert (pqelements != NULL);
    }

    ~PQueue() { delete [ ] pqelements; }
    bool Insert(T x){
        if (IsFull() == true) return false;   //判队满
        pqelements[count++] = x;              //插入
        adjust();
        return true;
    }
    bool RemoveMin(T& x){
        if (IsEmpty()) return false;
        x = pqelements[0];       //取出0号元素
        for (int i = 1; i < count; i++)
            pqelements[i-1] = pqelements[i];
             //从后向前逐个移动元素填补空位
        count--;
        return true;
   }

    bool GetFront(T& x){
        if (IsEmpty() == true) return false;
        x = pqelements[0];
        return true;
   }

    void MakeEmpty() { count = 0; }
    bool IsEmpty() const { return count == 0; }
    bool IsFull() const
           { return count == maxPQSize; }
    int Length() const { return count; }
private:
    T *pqelements;	       //存放数组
    int count;	                 //队列元素计数
    int maxPQSize;                //最大元素个数
    void adjust(){
        T temp = pqelements[count-1];
        //将最后元素暂存再从后向前找插入位置
        int j;
        for (j = count-2;  j >= 0;  j--)
            if (pqelements[j] <= temp) break;
            else pqelements[j+1] = pqelements[j];
        pqelements[j+1] = temp;
   }


};

#endif // PQUEUE_H
