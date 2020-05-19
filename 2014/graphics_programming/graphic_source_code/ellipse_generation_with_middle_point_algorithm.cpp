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
 
}
void setPixel(int x,int y){
   glBegin(GL_POINTS);
     glVertex2i(x,y);
   glEnd();
   glFlush();
   //cout<<x<<' '<<y<<' ';
}
void ellipsePlotPoints(int x,int y,int xc,int yc){
  
  setPixel(xc+x,yc+y);
  setPixel(xc-x,yc+y);
  setPixel(xc+x,yc-y);
  setPixel(xc-x,yc-y);
  }              
void ellipseMidpoint(int xc,int yc,int rx,int ry){
  double p=ry*ry-rx*rx*ry+0.25*rx*rx;
  int x=0,y=ry;
   ellipsePlotPoints(x,y,xc,yc);
  while(ry*ry*x<rx*rx*y){
    x++;
    if(p<0)p+=2*ry*ry*x+ry*ry;
    else{
      y--;
      p+=2*ry*ry*x+ry*ry-2*rx*rx*y;
    }
      ellipsePlotPoints(x,y,xc,yc);
  }
  p=ry*ry*(x+0.5)*(x+0.5)+rx*rx*(y-1)*(y-1)-rx*rx*ry*ry;
  while(y>0){
    y--;
    if(p>0)p+=-2*rx*rx*y+rx*rx;
    else{
      x++;
      p+=-2*rx*rx*y+rx*rx+2*ry*ry*x;
    }  
      ellipsePlotPoints(x,y,xc,yc);
  }
}   
void display(void){
  //glClear(GL_COLOR_BUFFER_BIT);
  int xc=200,yc=200,rx=150,ry=100;
  ellipseMidpoint(xc,yc,rx,ry);
  //drawCircle();
  glFlush();  
}   
        
int main(int argc, char* argv[])
{ 
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(winWidth,winHeight);
  glutCreateWindow("Gasket");
  init();
  glutDisplayFunc(display);
//  glutReshapeFunc(reshape);
  
  glutMainLoop();  
  
  return 0;
} 
   