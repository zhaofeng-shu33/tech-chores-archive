#include<iostream>
#include "D:/C++/Dev-Cpp/include/GL/gl.h"
#include "D:/C++/Dev-Cpp/include/GL/glu.h"
#include "D:/C++/Dev-Cpp/include/GL/glut.h"
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<fstream>
#include <ctime>
#include <windows.h>
const double Pi=3.14159, R = 8.314;
using namespace std;
int ww=400,wh=400;
unsigned long m=1;
const unsigned long  n=2147483647,g=16807;
void init1(){
  srand((unsigned)time(0));
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(-1,5,-2,3);
  glPointSize(8);

}
void display1(void){
  GLfloat cp[9][3]={{0,0},{1,1},{2.5,1},{4.6,-0.5},{3,-1.4},{1.3,-1.4},{0,0},{1,1},{2.5,1}};
  glColor3f(1,0,0);
  glBegin(GL_POINTS);
    glVertex2fv(cp[0]);
    glVertex2fv(cp[1]);
    glVertex2fv(cp[2]);
    glVertex2fv(cp[3]);
    glVertex2fv(cp[4]);
    glVertex2fv(cp[5]);
  glEnd();
  glColor3f(1,1,1);
  GLfloat kv[14]={0,1,2,3,4,5,6,7,8,9,10,11,12,13};
  GLUnurbsObj* BSpline;
  BSpline=gluNewNurbsRenderer();
  gluBeginCurve(BSpline);
    gluNurbsCurve(BSpline,9,kv,3,cp[0],2,GL_MAP1_VERTEX_3);
  gluEndCurve(BSpline); 

  glColor3f(1,1,0);
  gluBeginCurve(BSpline);
    gluNurbsCurve(BSpline,11,kv,3,cp[0],3,GL_MAP1_VERTEX_3);
  gluEndCurve(BSpline); 

  glColor3f(1,0,1);
  gluBeginCurve(BSpline);
    gluNurbsCurve(BSpline,13,kv,3,cp[0],4,GL_MAP1_VERTEX_3);
  gluEndCurve(BSpline); 
   
  glFlush();
 }
int main(int argc, char* argv[]){
 
  cout<<"Hello"<<endl;
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(ww,wh);
  glutCreateWindow("Three-Dimensional Object Representations");
  glutDisplayFunc(display1);
  init1();
  glutMainLoop();
  char ch;
  cin>>ch;
  return 0;
} 
 
