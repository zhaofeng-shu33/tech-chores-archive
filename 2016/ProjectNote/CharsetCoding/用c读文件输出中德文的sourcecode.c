#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 1024
int main()
{

   //sizeof(unsigned char))=1;
    FILE* fp=fopen("a.txt","rb");
    if(fp==NULL)printf("Error!");
    unsigned char buf[MAXLEN];
    int num=fread(buf,1,MAXLEN,fp);
    fclose(fp);
    buf[num]=0x00;
    printf("Buffer: %s\n ",(buf+3));
    printf("EndOFBuffer\n");
    printf("Num: %d\n",num);

    int i=0;
    for(i;i<num;i++)
        printf("%0x\n",buf[i]);



   /*  unsigned char data[4]={0x61,0x62,0x63,0x00};
    printf("%s\n",data);
   char c[] = "abcd中ABCD";
    int i=0;
    for(i;i<10;i++)
      printf("%0x\n",c[i]);
    printf("%s\n",c);
   */ 
    return 0;
}



