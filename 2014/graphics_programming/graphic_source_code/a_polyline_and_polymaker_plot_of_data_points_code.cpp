#include<iostream>
#include<GL/glu.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
using namespace std;
GLsizei winWidth=600,winHeight=500;
void init(void){
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0,winWidth,0,winHeight);
}
void reshape(int newWidth,int newHeight){
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0,(GLdouble)newWidth,0,(GLdouble)newHeight);
  glClear(GL_COLOR_BUFFER_BIT);  
 // gluOrtho2D(0,winWidth,0,winHeight);
}
int m=30,n=40;
/*void display(void){
  glRasterPos2i(m,n);
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'A');
  glFlush();
} */
void display(void){
  glClear(GL_COLOR_BUFFER_BIT);
  char mon[]="JanFebMarAprMayJunJulAugSepOctNovDec";
  int posx=20,posy=20;
  for(int i=0;i<12;i++){
      glRasterPos2i(50*i+posx,posy);
      for(int j=0;j<3;j++)
          glutBitmapCharacter(GLUT_BITMAP_9_BY_15,mon[3*i+j]);
  }
  int data[]={420,342,324,310,262,185,190,196,217,240,312,438};
  glBegin(GL_LINE_STRIP);
     for(int i=0;i<12;i++)
        glVertex2i(posx+50*i,data[i]);
  glEnd(); 
  for(int i=0;i<12;i++){
      glRasterPos2i(50*i+posx-2,data[i]-4);
      glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'*');
  }  
  glFlush();
}   
   
int main(int argc, char* argv[])
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(winWidth,winHeight);
  glutCreateWindow("This tests the location of characters of bitmap font");
  init();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();  
  
  return 0;
} 
   