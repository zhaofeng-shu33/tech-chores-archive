#include<iostream>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
const double Pi=3.14159;
using namespace std;

int winWidth=500,winHeight=500;
double theta=0;
int r=200;
struct screenPt{
  double x,y;
};
void drawCircle(){
  int n=50;
  double p[n][2];
  for(int i=0;i<n;i++){
      p[i][0]=r*cos(i*2*Pi/n);
      p[i][1]=r*sin(i*2*Pi/n);
  }  
  glBegin(GL_LINE_LOOP);
    for(int i=0;i<n;i++)
       glVertex2dv(p[i]); 
  glEnd();
}  
void init1(){
  glClear(GL_COLOR_BUFFER_BIT);
  
  //glMatrixMode(GL_MODELVIEW);
 
}  
void startRotate(){
  theta+=0.0002;
  if(theta>360)
     theta-=360;
  glutPostRedisplay();
}  
void display1(void){
  //glPushMatrix();
  //Here we do not use the clear function thus we can animate the process of drawing a circle!!
  glColor3f(1,1,1);
  //drawCircle();
  glRotatef(theta,0,0,1);
  glPointSize(4);
  glColor3f(1,1,0);
  glBegin(GL_POINTS);
    glVertex2d(r*cos(theta),r*sin(theta));
  glEnd();
  //glRecti(0,0,100,100);
 // glPopMatrix();
 // glutSwapBuffers();
  glFlush();
  glutSwapBuffers();
}

void myMouse2(int btn,int state,int x,int y){
  y=winHeight-y;
  if(btn==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)
     glutIdleFunc(startRotate);
   
  if(btn==GLUT_RIGHT_BUTTON&&state==GLUT_DOWN) 
     glutIdleFunc(NULL);
}

void reshape(int newWidth,int newHeight){
  glViewport(0,0,newWidth,newHeight);
  glMatrixMode(GL_PROJECTION);
  glOrtho(-winWidth/2,winWidth/2,-winHeight/2,winHeight/2,-100,100);
  glMatrixMode(GL_MODELVIEW);
  glClear(GL_COLOR_BUFFER_BIT);
}  
int n=60; 
void myTimer(int v){
  glutPostRedisplay();
  glutTimerFunc(1000/n,myTimer,v); 
}  
int main(int argc, char* argv[]){
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_DOUBLE| GLUT_RGB);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(winWidth,winHeight);
  glutCreateWindow("Three-Dimensional Object Representations");
  glutDisplayFunc(display1);
  init1();
  
  
  /*glutInitWindowPosition(800,100);
  glutCreateWindow("Rotate a Hexagon");
  glutDisplayFunc(displayHex);
  init2();
  
  */
  glutReshapeFunc(reshape);
 // glutTimerFunc(100,myTimer,n);
  //glutKeyboardFunc(myKey);
 glutMouseFunc(myMouse2);
  
  glutMainLoop();
  return 0;
} 
 