#include <QChar>
#include <stdio.h>


union fnum
{
int m;
float f;
};
int main(int argc, char *argv[])
{
union fnum num;
num.m=0x40a80000;
int a=0b01000000101010000000000000000000;
printf("int: %x \n",a);
printf("float: %f \n",num.f);

return 0;
}

