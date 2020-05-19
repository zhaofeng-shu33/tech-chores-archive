#include<string.h>
#include<stdio.h>
#define KEY_LEN 60
#define MAX_WORD_NUM 15 
#define MAX_WORD_LENGTH 18
#define MAX_TRANSLATION_LENGTH 12
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
    fp=fopen("germanWord.txt","rb");
    if(fp==NULL) {printf("file germanWord.txt does not exist");return -1;}

    unsigned char buf[MAXLEN];
    int num=fread(buf,1,MAXLEN,fp);
    fclose(fp);
    buf[num]=0x00;
    printf("NUM: %d\n",num);
    int i=3;
    num=0;
    while(buf[i]!='\0'){
        int j=0;
        while(buf[i]!='\r'){
            wordlist[num].entry[j]=buf[i];
        i++;j++;
        }
        printf("%s\n",wordlist[num].entry);
        wordlist[num].entry[i++]='\0';
        i++;num++;
    }
   fp=fopen("meaning.txt","rb");
   if(fp==NULL) printf("the file meaning.txt does not exist");
   num=fread(buf,1,MAXLEN,fp);
   fclose(fp);
   buf[num]=0x00;
   i=3; num=0;
   while(buf[i]!='\0'){
       int j=0;
       while(buf[i]!='\r'){
           wordlist[num].translation[j]=buf[i];
       i++;j++;
       }
       printf("%s\n",wordlist[num].translation);
       wordlist[num].translation[i++]='\0';
       i++;num++;
   }

/*
   int r;
   for(r=0;r<KEY_LEN;r++)
      key[r]=FLAG;
   char *p = NULL;

    int  sum=0;
    for(r=0;r<num;r++)
    {
        sum = 0;
        p = wordlist[r].entry;
        while (*p)
        {
          sum = 26*sum + (*p); 
          p++;     
        }
        wordlist[r].key = sum % KEY_LEN; //store the ASCII sum of the word
        if(key[wordlist[r].key]==FLAG)key[wordlist[r].key]=r;
        else{
          int pos;
          do{
            pos=(wordlist[r].key+1) % KEY_LEN;
          }while(key[pos]!=FLAG && pos!=wordlist[r].key);
          key[pos]=r;
        }  
   }*/
   return num;
}    
void Search(char wordform[]){
  int size=0;
  while(wordform[size]!='\0')size++;
  int sum=0,i;
  for(i=0;i<size;i++)sum=26*sum+wordform[i];
  sum=sum % KEY_LEN;
  printf("%s\n",wordlist[key[sum]].translation);
}          
int main(int argc, char* argv[]){
  int word_num;
  word_num=Init_Word();
  printf("%d\n",word_num);
  int i;
  for(i=0;i<word_num;i++)
     printf("%s -> %s\n",wordlist[i].entry,wordlist[i].translation);
//  Search("Abend");
  
  system("pause");
  return 0;
}

