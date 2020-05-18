#include <iostream>
#include <stdio.h> 
#include <ctime>
#include<time.h>
#include <string>
using namespace std; 
class Player{
  public:
    Player(string str,int voc=1000):vocabulary(1000){name=str;}
    string get_name(){return name;}
    void set_vocabulary(int change){vocabulary+=change;}
  private:
    int vocabulary; 
    string name;   
};  
int main() {
  srand((unsigned)time(0));
  string str; 
  int change;
  Player zhao("zhao");
  while(1){
    cin>>str;
    if(str=="zhao"){
       cin>>change;
       zhao.set_vocabulary(change);
    }  
    if(int(str)<60000)
       cout<<rand()%(int(str))<<endl;
  }  
  return 0;
}

