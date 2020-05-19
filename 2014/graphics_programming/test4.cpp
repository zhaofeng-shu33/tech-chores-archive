
/* Copyright (c) Mark J. Kilgard, 1994. */

/* This program is freely distributable without licensing fees 
   and is provided without guarantee or warrantee expressed or 
   implied. This program is -not- in the public domain. */

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<deque>
using namespace std;
void swap(int* a,int* b){
  int tmp;
  tmp=*a;
  *a=*b;
  *b=tmp;
  cout<<*a<<' '<<*b<<endl;
}  
main(int argc, char **argv)
{
  deque<float> myQueue;
  myQueue.push_front(3.1f);
  myQueue.push_front(3.2f);
  for(deque<float>::iterator i=myQueue.begin();i!=myQueue.end();i++)
      cout<<*i<<endl;
  cout<<myQueue.size();
  
  return 0;             /* ANSI C requires main to return int. */
}
