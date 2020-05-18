#include<string>
#include<string.h>
#include<stdio.h>
#define WORD_NUM  10
#define HASH_LEN 60
#define M  60
#define FLAG -1
#pragma  message("消息文本")
typedef struct word
{
    char *entry;
    int key;      
};
word wordlist[WORD_NUM];
typedef struct Hash
 {
    char *entry;
    char* wordmean;
    int  key;
};
Hash HashTable[HASH_LEN];
void Init_Word()
{
   static  char *p = NULL;
   static  int i = 0;
   static  int j = 0;
   int  sum = 0;
   wordlist[0].entry = "Abend";  
   wordlist[1].entry = "Apfel";  
   wordlist[2].entry = "Baum";  
   wordlist[3].entry = "Bett";  
   wordlist[4].entry = "Boot";  
   wordlist[5].entry = "Buch";  
   wordlist[6].entry = "Eis";  
   wordlist[7].entry = "Fahne";  
   wordlist[8].entry = "Frau";   
   wordlist[9].entry = "Gas";
   for(i =0; i < WORD_NUM; i++ )
   {
        sum = 0;
        p = wordlist[i].entry;
        while (*p)
        {
          sum = sum + (*p); 
          p++;     
        }
        wordlist[i].key = sum; //store the ASCII sum of the word
   }
   for (i = 0;i <WORD_NUM; i++)
   {
       printf("%d: %s\n",i,wordlist[i].entry);    
       printf("%d\n",wordlist[i].key);
   }
}
void initHashTable()
 {
     static int i = 0;
     static int j = 0;
     for(i = 0;i < HASH_LEN; i++) 
     {
        HashTable[i].key = FLAG; 
        HashTable[i].entry = NULL; 
        strcpy(HashTable[i].wordmean,  "this is: ");
         
     } 
 }
 
int h(int k)
 {
     k = (k+1) % M;
     return k;
 }
 void askl()
 {
    int i = 0;
    int addr = 0;
    int d = 0;
   
    for(i = 0; i < WORD_NUM; i++)
    {
       
       addr = (wordlist[i].key & 0x7FFFFFFF)% M; //Hash function
       d = addr;
       if(HashTable[addr].key == FLAG)
       {
           HashTable[addr].key = wordlist[i].key;
           HashTable[addr].wordmean = wordlist[i].entry;
           
       }  
       else //线性探查法解决冲突。 
       {
         do
           {
              addr = h(addr);
              if(addr == d)
              {
                printf("the Hash table is overloaded. \n");
                break;
                        
              }
                          
           }while(HashTable[addr].key!=FLAG) ;  
 
          HashTable[d].key = wordlist[i].key;
           HashTable[d].wordmean = wordlist[i].entry;
           
       }
    }
    for(i = 0; i<HASH_LEN; i++)
    {
         printf("%d\n",HashTable[i].key);
         printf("%d\n",HashTable[i].wordmean);
       
    }
    
}
 

int main(int argc, char* argv[]){
  Init_Word();

  system("pause");
  return 0;
}

