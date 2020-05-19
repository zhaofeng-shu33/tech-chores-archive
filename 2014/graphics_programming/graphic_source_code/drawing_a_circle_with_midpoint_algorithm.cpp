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
void circlePlotPoints(int x,int y,int xc,int yc,int radius){
  
  setPixel(xc+x,yc+y);
  setPixel(xc+-x,yc+y);
  setPixel(xc+x,yc+-y);
  setPixel(xc+-x,yc+-y);
  setPixel(xc+y,yc+x);
  setPixel(xc+-y,yc+x);
  setPixel(xc+y,yc+-x);
  setPixel(xc+-y,yc+-x);
}              
void circleMidpoint(int xc,int yc,int radius){
  int p=1-radius,x=0,y=radius;
  circlePlotPoints(x,y,xc,yc,radius);
  while(x<y){
    if(p<0)p+=2*x+3;
    else{
      p+=2*x-2*y+4;
      y--;
    }
    x++;
    circlePlotPoints(x,y,xc,yc,radius);
  }
} 
void drawCircle(){
  int n=50;
  double p[n][2];
  for(int i=0;i<n;i++){
      p[i][0]=200+85*cos(i*2*Pi/n);
      p[i][1]=150+50*sin(i*2*Pi/n);
  }  
  glBegin(GL_POLYGON);
    for(int i=0;i<n;i++)
       glVertex2dv(p[i]); 
  glEnd();
}     
void display(void){
  //glClear(GL_COLOR_BUFFER_BIT);
  int xc=100,yc=100,radius=100;
  circleMidpoint(xc,yc,radius);
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
   