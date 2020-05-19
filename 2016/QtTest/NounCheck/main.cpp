#include "wordSource.h"
int main(int argc, char *argv[])
{
   if(argc==1){
       cout<<"No word provided!";
       return -1;
   }
   for(int i=1;i<argc;i++){
       cout<<Word(argv[i]);
   }
}
