#include<iostream>
#include<GL/glu.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
const double Pi=3.14159;
using namespace std;
void cube();
void init(void){
  glMatrixMode(GL_PROJECTION);
  glOrtho(-1.5, 1.5, -1.5, 1.5, -10, 10);
}

void quad(GLint n1,GLint n2,GLint n3,GLint n4){
   int m=1;
   //glColor4f(0,0,0,0);
   GLint pt[8][3]={{0,0,0},{0,m,0},{m,0,0},{m,m,0},{0,0,m},{0,m,m},{m,0,m},{m,m,m}};
   glBegin(GL_LINE_LOOP);
   glVertex3iv(pt[n1]);
   glVertex3iv(pt[n2]);   
   glVertex3iv(pt[n3]);
   glVertex3iv(pt[n4]);
   glEnd();
}
int main(int argc, char* argv[])
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(400, 300);
  glutCreateWindow("My first example");
  init();
  glutDisplayFunc(cube); 
  glutMainLoop();
  return 0;
} 
void cube(){
   glClear(GL_COLOR_BUFFER_BIT);
   glRotatef(60,1,1,1);          
   quad(6,2,3,7);
   quad(5,1,0,4);
   quad(7,3,1,5);
   quad(4,0,2,6);
   quad(2,0,1,3);
   quad(7,5,4,6);
   glFlush();
   }  
 