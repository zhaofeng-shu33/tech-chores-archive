#include <QChar>
#include <stdio.h>
#include <windows.h>

int main()
{
    int i=0x3e200000;

    float j=0.15625;//补码，i按位取反，最低位加1，short为2 byte.
    int *pd=(int*)&j;
    int *pf=(int*)&i;
    float j1=*pf;
    printf("%p \n",pf);
    printf("%x \n",i);
    printf("%p \n",*pd);
    system("pause");
    return 0;
}

