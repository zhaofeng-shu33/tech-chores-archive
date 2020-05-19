#include <iostream>
#include <ctime>
#include <cmath>
using namespace std; 
class Player{
  public:
    Player(int pos=0):position(pos){}
  private:
    int position;
  public:
    int get_position();
    void set_position(int move){
      position+=move;
    }    
};  
int main() {
   cout<<sin(3.14);
   return 0;
}

