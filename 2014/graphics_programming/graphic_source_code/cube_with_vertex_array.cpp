#include<iostream>
#include<GL/glu.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
const double Pi=3.14159;
using namespace std;
void init(void){
  glMatrixMode(GL_PROJECTION);
  glOrtho(-1.5, 1.5, -1.5, 1.5, -10, 10);
}

void cube(){
   glClear(GL_COLOR_BUFFER_BIT);
   glRotatef(30,1,1,1);
   int m=1;
   GLint pt[8][3]={{0,0,0},{0,m,0},{m,0,0},{m,m,0},{0,0,m},{0,m,m},{m,0,m},{m,m,m}};
   glEnableClientState(GL_VERTEX_ARRAY);
   glVertexPointer(3,GL_INT,0,pt);
   GLubyte vertIndex[]={0,2,3,1,0,4,6,2,0,4,5,1,3,7,5,4,6,7,3};
   glDrawElements(GL_LINE_STRIP,19,GL_UNSIGNED_BYTE,vertIndex);
   glDisableClientState(GL_VERTEX_ARRAY);
   
   /*glBegin(GL_LINES);
   glVertex3iv(pt[6]);
   glVertex3iv(pt[7]);
   glEnd();*/
   glFlush();
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
 