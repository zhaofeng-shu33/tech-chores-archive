#include <iostream>
#include <fstream>
#include <cmath>
#include <deque>
class Deque : public Queue<T> {
public:
   bool getHead(T& x)const = 0;
	 bool getTail(T& x)const = 0;
	 bool EnQueueHead(const T& x) = 0;
	 bool EnQueueTail(const T& x) = 0;
	 bool DeQueueHead(T& x) = 0;
   bool DeQueueTail(T& x) = 0;
using namespace std;
int main(){
  deque<int> a;
  for(int i=0;i<10;i++)
  a.push_back(i*i);
  deque<int>::iterator p=a.end();
  p--;
  *p=3;
  cout<<a.back();
  system("pause");
  return 0;
}

