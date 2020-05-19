#include<stdio.h>
int func(int n)
{
	int sum=0,i;
	for(i=0;i<n;i++)
		sum+=i;
  return sum;
}

int main(){  
  int a=0x00000001;//the smallest positive number in 32bit floating number.
	
  printf("%f\n",*(float*)(&a));
  printf("%e\n",*(float*)(&a));
  printf("%a\n",*(float*)(&a));

  return 0;
}
   

