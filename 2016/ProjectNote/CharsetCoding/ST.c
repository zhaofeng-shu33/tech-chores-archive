#include<string.h>
#include<stdio.h>
#define KEY_LEN 60
#define MAX_WORD_NUM 15
#define MAX_WORD_LENGTH 10
#define MAX_TRANSLATION_LENGTH 8
#define MAXLEN 1024
#define FLAG -1
typedef struct word
{
    char entry[MAX_WORD_LENGTH];
    char translation[MAX_TRANSLATION_LENGTH];
    int key;
}word;

word wordlist[MAX_WORD_NUM];
int key[KEY_LEN];

int Init_Word()//return the word number
{
  FILE *fp;
  fp=fopen("meaning.txt","rb");
  if(fp==NULL) {printf("file germanWord.txt does not exist");return -1;}

  unsigned char buf[MAXLEN];
  int num=fread(buf,1,MAXLEN,fp);
  fclose(fp);
  buf[num]=0x00;
  printf("NUM: %d\n",num);
  printf("Buffer: %s\n",(buf+3));
  printf("EndOFBUFFer");
  int i=3;
  num=0;
  while(buf[i]!='\0'){
      int j=0;
      while(buf[i]!='\r'){
          wordlist[num].translation[j]=buf[i];
      i++;j++;
      }
      wordlist[num].translation[i++]='\0';
      i++;num++;
  }

   return num;
}

int main(int argc, char* argv[]){

 int word_num=Init_Word();
 printf("%d\n",word_num);
 int i=0;
 for(i;i<word_num;i++)
     printf("%s\n",wordlist[i].translation);
// printf("%0x\n",wordlist[1].entry[0]);
  return 0;
}

