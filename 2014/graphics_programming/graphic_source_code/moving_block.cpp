//you can move the block using w a s d, which mean respectively upwards,leftwards,downwards and rightwards.

#include<iostream>
#include<GL/glu.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<ctime>

double Pi=3.14159;
//const int n=51000;
using namespace std;
GLsizei winWidth=400,winHeight=400;
int radius=10;
int ID1,ID2;
struct screenPt{
   double x;
   double y;
};
void init(void){
  // glClear(GL_COLOR_BUFFER_BIT);
  glViewport(0,0,winWidth,winHeight);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0,winWidth,0,winHeight);
}

void reshape(int newWidth,int newHeight){
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0,(GLdouble)newWidth,0,(GLdouble)newHeight,-100,100);
  winWidth=newWidth,winHeight=newHeight;
  glViewport(0,0,winWidth,winHeight);
  glClear(GL_COLOR_BUFFER_BIT);  
} 
void drawCircle(int x,int y){
  int n=50;
  y=winHeight-y;
  double p[n][2];
  for(int i=0;i<n;i++){
      p[i][0]=x+radius*cos(i*2*Pi/n);
      p[i][1]=y+radius*sin(i*2*Pi/n);
  }  
  glBegin(GL_POLYGON);
    for(int i=0;i<n;i++)
       glVertex2dv(p[i]); 
  glEnd();
  glFlush();
}
void mouse(int button,int state,int x,int y){
  if(button==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)
     drawCircle(x,y);
}

void sub_menu(int id){
  switch(id){
    case 2: radius+=10;break;
    case 3: radius-=10;break;
    case 4: glutIconifyWindow();
    break;
  }  
  glutPostRedisplay();
}  
void top_menu(int id){
  switch(id){
    case 1: exit(0);break;
  }  
  //glutPostRedisplay();
}

void TranslateRectangle(double x,double y,screenPt min,screenPt max){
  glColor3f(0,0,0);
  glRectd(min.x,min.y,max.x,max.y);
  glColor3f(1,1,0);
  glTranslated(x,y,0);
  glRectd(min.x,min.y,max.x,max.y);
  glFlush();
}
 
screenPt min1={20,30},max1={120,100};      
void key(unsigned char k,int x,int y){
  if(k=='w')TranslateRectangle(0,40,min1,max1);
  if(k=='s')TranslateRectangle(0,-40,min1,max1);
  if(k=='a')TranslateRectangle(-40,0,min1,max1);
  if(k=='d')TranslateRectangle(40,0,min1,max1);
}

void display1(void){
  glClear(GL_COLOR_BUFFER_BIT);
  glRectd(min1.x,min1.y,max1.x,max1.y);
  glFlush();
}            
int main(int argc, char* argv[])
{ 
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB|GLUT_DEPTH);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(winWidth,winHeight);
  
  
  
  
  
  init();
  ID1=glutCreateWindow("window1");
  glutDisplayFunc(display1);
  
  int menu2=glutCreateMenu(sub_menu);
  glutAddMenuEntry("increase circle radius",2);
  glutAddMenuEntry("decrease circle radius",3);
  glutAddMenuEntry("Full Screen",4);
  
  glutCreateMenu(top_menu);
  glutAddMenuEntry("quit",1);
  glutAddSubMenu("Resize",menu2);
  
  glutAttachMenu(GLUT_RIGHT_BUTTON);
  
    
  glutReshapeFunc(reshape); 
  glutMouseFunc(mouse);
  glutMotionFunc(drawCircle);
  glutKeyboardFunc(key);
  
  
  
  glutMainLoop();  
  
  return 0;
} 
   