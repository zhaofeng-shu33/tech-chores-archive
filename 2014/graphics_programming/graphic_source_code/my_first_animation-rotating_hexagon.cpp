#include<iostream>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
const double Pi=3.14159;
using namespace std;
int winWidth=200,winHeight=200;
double rotTheta=0;
int regHex;
struct screenPt{
  double x,y;
};  
void init1(){
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0,winWidth,0,winHeight);
}  
void init2(void){
  glMatrixMode(GL_PROJECTION);
  glOrtho(-winWidth,winHeight,-winHeight,winHeight, -10, 10);
  regHex=glGenLists(1);
  double hexTheta=0;
  screenPt hexVertex;
  glNewList(regHex,GL_COMPILE);
    glBegin(GL_POLYGON);
      for(int i=0;i<6;i++){
          hexTheta=i*Pi/3;
          hexVertex.x=80*cos(hexTheta);
          hexVertex.y=80*sin(hexTheta);
          glVertex2d(hexVertex.x,hexVertex.y);
      }
    glEnd();  
  glEndList();
}
void rotateHex(){
  rotTheta+=3;
  if(rotTheta>360)
     rotTheta-=360;
  glutPostRedisplay();
}  
void displayHex(void){
  glClear(GL_COLOR_BUFFER_BIT);
  glPushMatrix();
  glRotatef(rotTheta,0,0,1);
  glCallList(regHex);
  glPopMatrix();
  glutSwapBuffers();
  glFlush();
} 
void display(void){
  glBegin(GL_LINES);
    glVertex2i(10,20);
    glVertex2i(90,20);
    glVertex2i(20,10);
    glVertex2i(20,90);
  glEnd();
  glFlush();
}  
void myKey(unsigned char key, int x, int y){
  if(key=='r')
     glutIdleFunc(rotateHex);
  if(key=='n')
     glutIdleFunc(NULL);
}
void myMouse(int btn,int state,int x,int y){
  y=winHeight-y;
  if(btn==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)
     cout<<x<<' '<<y<<endl;
}    
int main(int argc, char* argv[])
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_DOUBLE| GLUT_RGB);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(winWidth,winHeight);
  glutCreateWindow("My first example");
  init2();
  glutDisplayFunc(displayHex);
  glutKeyboardFunc(myKey);
  glutMouseFunc(myMouse);
  glutMainLoop();
  return 0;
} 
 