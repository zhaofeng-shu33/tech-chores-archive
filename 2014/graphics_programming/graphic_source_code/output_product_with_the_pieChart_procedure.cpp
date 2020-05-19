#include<iostream>
#include<GL/glu.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
double Pi=3.14159;
using namespace std;
GLsizei winWidth=500,winHeight=500;
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
  int n=50;
  double p[n][2];
  for(int i=0;i<n;i++){
      p[i][0]=250+100*cos(i*2*Pi/n);
      p[i][1]=250+100*sin(i*2*Pi/n);
  }  
  glBegin(GL_LINE_LOOP);
    for(int i=0;i<n;i++)
       glVertex2dv(p[i]);   //approximate to the circle.
  glEnd();
  int data[]={420,342,324,310,262,185,190,196,217,240,312,438};
  int sum=0;
  double angle[12];
  for(int i=0;i<12;i++)
      sum+=data[i];
  angle[0]=2*Pi*data[0]*1.0/sum;
  for(int i=1;i<12;i++)
      angle[i]=angle[i-1]+2*Pi*data[i]*1.0/sum;
  
  
  for(int i=0;i<12;i++){
      glBegin(GL_LINES);
        glVertex2d(250+100*cos(angle[i]),250+100*sin(angle[i]));
        glVertex2d(250,250);
      glEnd();
    if(i>0){
      double theta=(angle[i-1]+angle[i])/2;
      if(abs(i-6)>3){
      glRasterPos2d(250+100*cos(theta),250+100*sin(theta));
     }  
      else
      glRasterPos2d(250+120*cos(theta),250+120*sin(theta));
      
      for(int j=0;j<3;j++)
      glutBitmapCharacter(GLUT_BITMAP_9_BY_15,mon[3*i+j]);
    }  
  }
  glRasterPos2d(250+100*cos(angle[0]/2),250+100*sin(angle[0]/2));
  for(int j=0;j<3;j++)   
      glutBitmapCharacter(GLUT_BITMAP_9_BY_15,mon[j]);
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
   