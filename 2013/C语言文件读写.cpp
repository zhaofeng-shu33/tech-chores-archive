#include<string>
#include<string.h>
#include<stdio.h>
char _str[17];
char * cTob(char c){
  unsigned int i,a;
  i=c;
  a=~((~0)<<8);
  i=i&a;
  itoa(i,_str,2);
  return _str;
} 
int main(int argc, char* argv[]){
  FILE *fp;
  fp=fopen("D:/ProjectNote/PyAudio/binary1.txt","wb");
  char mystr[]="ab";
  fprintf(fp,"%s",mystr);
  fclose(fp);
  fp=fopen("D:/ProjectNote/PyAudio/binary1.txt","rb");  
    int num=0;
  if(fp==NULL) printf("the file does not exist");  
  else{
    char ch;
    while(!feof(fp)){
      num++;
      ch=fgetc(fp);
      char* result=cTob(ch);
      printf("%s\n",result);
    }
  }    
  printf(" %d",num);
  system("pause");
  return 0;
}

