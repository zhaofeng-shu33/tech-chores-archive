#include<iostream>
#include<fstream>
#include<vector>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include <ctime>
#include<chrono>
#include<thread>

bool barrier[20][20];
using namespace std;
bool is_end=0;
const double PI=3.14159;
int ww=400,wh=400;
class Player{
  public:
    friend class MapGrid;
    Player(int pos=0):position(pos){}
  private:
    int position;
    string figure;
  public:
    int get_position(){
        return position;
    }
    string get_figure(){
        return figure;
    }  
    void set_figure(string figur){
        figure=figur;
    }  

    void set_position(int move){
      position+=move;
    }
};
Player player[2];
class MapGrid{
  public:
    MapGrid(string h=""):hint(h){}
    MapGrid(int x,int y,string h=""):location_x(x),location_y(y),hint(h){}
    MapGrid(const MapGrid& mapGrid){
      location_x=mapGrid.location_x;
      location_y=mapGrid.location_y;  
      hint=mapGrid.hint;
    }
  private:
    string hint;
    int movingInstruction;
    int location_x;
    int location_y;
  public:
    string get_hint(){
        return hint;
    }
    void set_location(int x,int y){
       location_x=x;
       location_y=y;
    }  
    void set_hint(string h){
        hint=h;
    }
    int get_movingInstruction(){
        return movingInstruction;
    }
    int get_location_x(){
        return location_x;
    }
    int get_location_y(){
        return location_y;
    }

    void set_movingInstruction(int move){
        movingInstruction=move;
    }

    void set_Player_position(Player p){
        p.set_position(p.get_position()+get_movingInstruction());
    }
};
vector<MapGrid> mapGrid;
void draw_figure(Player player){
  std::chrono::milliseconds timespan(200);
  std::this_thread::sleep_for(timespan);  
  int x=mapGrid[player.get_position()].get_location_x();
  int y=mapGrid[player.get_position()].get_location_y();
  if(player.get_figure()=="circle"){
     glBegin(GL_LINE_LOOP);
          for(int i=0;i<12;i++)
          glVertex2f(x+10+10*cos(i*PI/6),y+10+10*sin(i*PI/6)); 
     glEnd();
  }
  else if(player.get_figure()=="triangle"){
     glColor3f(1,1,0);
     glBegin(GL_LINE_LOOP);
          glVertex2i(x,y);
          glVertex2i(x+20,y);
          glVertex2i(x+10,y+20); 
     glEnd();
  }
     glColor3f(1,1,1);    
}  

void drawGrid(int,int);
void init1(){
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0,ww,0,wh);
  glBegin(GL_LINES);
  for(int i=0;i<20;i++){
    glVertex2i(i*20,0);
    glVertex2i(i*20,400);
    glVertex2i(0,i*20);
    glVertex2i(400,i*20);
  }  
  glEnd();
  for(int i=0;i<10;i++)
      for(int j=0;j<19;j++){
          if(i%2==0){
          drawGrid(20+i*40,j*20);
          barrier[2*i+1][j]=1;
          }  
          else{
          drawGrid(20+i*40,20+j*20);
          barrier[2*i+1][j+1]=1;
          } 
     }
   for(int i=0;i<20;i++)
       for(int j=0;j<20;j++){
           if(!barrier[i][j]&&(i%4==0))
             mapGrid.push_back(MapGrid(i*20,j*20));
           if(!barrier[i][19-j]&&(i%4==2))
             mapGrid.push_back(MapGrid(i*20,380-j*20));
           if(!barrier[i][j]&&(i%2==1))
            mapGrid.push_back(MapGrid(i*20,j*20));
      }
   cout<<"mapGrid size: "<<mapGrid.size()<<endl;  
   srand((unsigned)time(0));
   mapGrid[0].set_hint("Start");
   mapGrid[mapGrid.size()-1].set_hint("End");
   mapGrid[mapGrid.size()/2].set_hint("Move Back 2 Steps");
   mapGrid[mapGrid.size()/2].set_movingInstruction(-2);
   player[0].set_figure("circle"); 
   draw_figure(player[0]);
   player[1].set_figure("triangle");
   draw_figure(player[1]);
}

void drawGrid(int x,int y){//left-down corner glPointSize(5);
  //PointSize(5);
  glColor3f(0,0,0.5);
  glBegin(GL_POLYGON);
  glVertex2i(x,y); 
  glVertex2i(x+20,y); 
  glVertex2i(x+20,y+20); 
  glVertex2i(x,y+20); 
  glEnd();
  glColor3f(1,1,1);  
}
                                                                                                                                             
void display1(void){
 glClear(GL_COLOR_BUFFER_BIT);  
  for(int i=0;i<10;i++)
      for(int j=0;j<19;j++){
          if(i%2==0){
          drawGrid(20+i*40,j*20);
          }  
          else{
          drawGrid(20+i*40,20+j*20);
          } 
  }
 glBegin(GL_LINES);
  for(int i=0;i<20;i++){
    glVertex2i(i*20,0);
    glVertex2i(i*20,400);
    glVertex2i(0,i*20);
    glVertex2i(400,i*20);
  }  
 glEnd();
  for(int i=0;i<2;i++){
      int a=rand()%6+1;
      cout<<"player "<<i+1<<" should move forward "<<a<<" step(s)"<<endl;
      if(player[i].get_position()+a>mapGrid.size()){
      cout<<"player "<<i+1<<" wins the game!"<<endl;
      is_end=1;
      break;
      }
           
      for(int j=0;j<a;j++){
      player[i].set_position(1);
      draw_figure(player[i]);
      }
      
      if(mapGrid[player[i].get_position()].get_hint().length()!=0){
          cout<<i+1<<' '<<mapGrid[player[i].get_position()].get_hint()<<endl;
          mapGrid[player[i].get_position()].set_Player_position(player[i]);
      }
  cout<<"player "<<i+1<<" now has position: "<<player[i].get_position()<<endl;
  }
  glFlush();
} 
void idle(){
  if(!is_end){
  glutPostRedisplay();
  }
  std::chrono::milliseconds timespan(800);
  std::this_thread::sleep_for(timespan);  
}  
void key(unsigned char k,int x,int y){
  if(k=='p'||k=='P') cout<<"you press the pause";
} 
int main(int argc, char* argv[]){
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
  glutInitWindowPosition(800,142);
  glutInitWindowSize(ww,wh);
  glutCreateWindow("Big Wealth");
  glutDisplayFunc(display1);
  init1();
  glutKeyboardFunc(key);
  glutIdleFunc(idle);
  glutMainLoop();
  return 0;
} 
 
