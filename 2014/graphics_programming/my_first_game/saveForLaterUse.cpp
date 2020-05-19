#include<iostream>
#include<GL/glu.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<ctime>
using namespace std;
GLsizei winWidth=400,winHeight=400;
bool state=false,condition=true; //If state turns true, the game is over. If condition is true, you
void init(void){
  glViewport(0,0,winWidth,winHeight);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0,winWidth,0,winHeight);
}
                                // win the game, otherwise you lose the game.

struct screenPt{
   double x;
   double y;
};
void reshape(int newWidth,int newHeight){
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0,(GLdouble)newWidth,0,(GLdouble)newHeight);
  winWidth=newWidth,winHeight=newHeight;
  glViewport(0,0,winWidth,winHeight);
  glClear(GL_COLOR_BUFFER_BIT);  
}
screenPt min1={280,30},max1={380,75};      
screenPt pt[16]={{10,10},{190,10},{190,135},{210,135},{210,10},
  {390,10},{390,190},{120,190},{120,210},{390,210},
  {390,390},{210,390},{210,265},{190,265},{190,390},{10,390}};//construct 16 points which constitute the boundary of the maze.

void TranslateRectangle(double x,double y,screenPt& min,screenPt& max){
  glColor3f(0,0,0);
  glRectd(min.x,min.y,max.x,max.y);//Clear the original figure of the agent rectangle.
  
  glColor3f(1,1,0);//Set the color of the agent rectangle to yellow.
  min.x+=x;
  min.y+=y;
  max.x+=x;
  max.y+=y;
  glRectd(min.x,min.y,max.x,max.y);
  //translate the rectangle along the vector (x,y);
  glBegin(GL_LINE_LOOP);
    for(int i=0;i<16;i++)
        glVertex2d(pt[i].x,pt[i].y);
  glEnd();
  //Reconstruct the boundary line of the maze, in case that the line may be wiped out by the rectangle.
  glFlush();
}
 

void intersect(screenPt pt[]){
  if( (min1.x<=10||max1.x>=390||min1.y<=10||max1.y>=390)
     
  ||(max1.x>=120&&max1.y>=190&&min1.y<=210)
   
  ||(max1.x>=190&&min1.x<=210&&(min1.y<=135||max1.y>=265)) ){
     glutIconifyWindow();
     glutSetWindow(2);
     glutShowWindow();
     state=true;
     condition=false;
   }  
   
  if(max1.x>300&&min1.x<350&&max1.y>300&&min1.y<350){
  cout<<"Succeed";
  glutSetWindow(2);
  glutShowWindow();
  state=true;
  }  
}      
void key(unsigned char k,int x,int y){
  if(k=='w'||k=='W')TranslateRectangle(0,5,min1,max1);
  if(k=='s'||k=='S')TranslateRectangle(0,-5,min1,max1);
  if(k=='a'||k=='A')TranslateRectangle(-5,0,min1,max1);
  if(k=='d'||k=='D')TranslateRectangle(5,0,min1,max1);
  intersect(pt);
}
void display2(void){
  glClear(GL_COLOR_BUFFER_BIT);
  
  if(state==false)    
     glutIconifyWindow();//Initially the other window is hiden.
  if(condition==true){
    glRasterPos2i(200,200);
    char win[]="Winner";
    for(int i=0;i<6;i++)
      glutBitmapCharacter(GLUT_BITMAP_9_BY_15,win[i]);
  }
  else{
    glRasterPos2i(200,200);
    char loser[]="Loser";
    for(int i=0;i<5;i++)
      glutBitmapCharacter(GLUT_BITMAP_9_BY_15,loser[i]);
  }  
  glFlush();
}            
void display1(void){
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_LINE_LOOP);
    for(int i=0;i<16;i++)
        glVertex2d(pt[i].x,pt[i].y);
  glEnd();
  glRecti(300,300,350,350);
  
  glColor3f(1,0,0);
  glRasterPos2i(300,325);
  char exit[]="Exit";
  for(int i=0;i<4;i++)
      glutBitmapCharacter(GLUT_BITMAP_9_BY_15,exit[i]);
 
  glColor3f(1,1,0);
  glRectd(min1.x,min1.y,max1.x,max1.y);
  
  
  
  glFlush();
}

int main(int argc, char* argv[])
{ 
 // glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB|GLUT_DEPTH);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(winWidth,winHeight);
  
  init();
  glutCreateWindow("window1");
  glutDisplayFunc(display1);
  glutReshapeFunc(reshape); 
  
 
  glutKeyboardFunc(key);
  
  glutInitWindowPosition(700,100);
  int ID=glutCreateWindow("new Window");

  glutDisplayFunc(display2);
  glutReshapeFunc(reshape); 
  glutMainLoop();  
  
  return 0;
} 
   
