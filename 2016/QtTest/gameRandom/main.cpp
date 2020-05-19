
#include <iostream>
#include <stdio.h>
#include <ctime>
#include <time.h>
#include <string>
using namespace std;
class Player{
  public:
    friend class MapGrid;
    Player(int pos=0):position(pos){}
  private:
    int position;
  public:
    int get_position(){
        return position;
    }

    void set_position(int move){
      position+=move;
    }
};
class MapGrid{
  public:
    MapGrid(string h=""):hint(h){}
  private:
    string hint;
    int movingInstruction;
  public:
    string get_hint(){
        return hint;
    }
    void set_hint(string h){
        hint=h;
    }
    int get_movingInstruction(){
        return movingInstruction;
    }
    void set_movingInstruction(int move){
        movingInstruction=move;
    }

    void set_Player_position(Player p){
        p.set_position(p.get_position()+get_movingInstruction());
    }
};

int main(int argc,char* argv[]) {

  srand((unsigned)time(0));
  Player player[2];
  MapGrid SpecificMapGrid[100];
  SpecificMapGrid[0].set_hint("Start");
  SpecificMapGrid[99].set_hint("End");
  SpecificMapGrid[50].set_hint("Move Back 2 Steps");
  SpecificMapGrid[50].set_movingInstruction(-2);
  while(player[0].get_position()<99&&player[1].get_position()<99){
      for(int i=0;i<2;i++){
      int a=rand()%6+1;
      player[i].set_position(a);
      if(SpecificMapGrid[player[i].get_position()].get_hint().length()!=0){
          cout<<SpecificMapGrid[player[i].get_position()].get_hint();
          SpecificMapGrid[player[i].get_position()].set_Player_position(player[i]);
      }
      cout<<i+1<<' '<<player[i].get_position()<<endl;
      }
  }
  
  return 0;
}
