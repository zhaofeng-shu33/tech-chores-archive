#include <QChar>
#include <stdio.h>

int main()
{
    short i=0b0111111111111111;
    short j=0b1000000000000001;//补码，i按位取反，最低位加1，short为2 byte.
    QChar a1(i);
    printf("%d/n",i);
    printf("%x/n",-32767);
    
    return 0;
}

