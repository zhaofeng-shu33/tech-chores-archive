#include<iostream>
#include<fstream>
using namespace std;
void ren(char* filename){

 int si=0;char main_name[100];
   for(int i=0;;i++){
       main_name[i]=filename[i]; si++;
       if(main_name[i]=='.')
         break;
   }   
   
   main_name[si]='t';
   si++;main_name[si]='x';
   si++;main_name[si]='t';
   si++;main_name[si]='\0';
         
  cout<<main_name;
  ofstream fout(main_name);
   ifstream fin(filename);
   char temp;
   fin.get(temp);
     while(!fin.eof()){
         fout.put(temp);
         fin.get(temp);
         
    }
    fin.close();
    fout.close();    
}

int main(){
    ren("verabschieden.doc");
    
    char ch;
    cin>>ch;
    return 0;
}  
