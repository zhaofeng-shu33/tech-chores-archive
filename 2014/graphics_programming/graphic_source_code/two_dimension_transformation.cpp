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
const int n=4;
void init(void){
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(-winWidth/2,winWidth/2,-winHeight/2,winHeight/2);
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
void drawPolygon(){
  int n=7;
  double p[n][2];
  for(int i=0;i<n;i++){
      p[i][0]=200+85*cos(i*2*Pi/n);
      p[i][1]=150+50*sin(i*2*Pi/n);
  }  
  glBegin(GL_POLYGON);
    for(int i=0;i<n;i++)
       glVertex2dv(p[i]); 
  glEnd();
  double theta=Pi/6,p1[n][2];
  glBegin(GL_POLYGON);
    for(int i=0;i<n;i++){
       //p1[i][0]=cos(theta)*p[i][0]-sin(theta)*p[i][1];
       //p1[i][1]=sin(theta)*p[i][0]+cos(theta)*p[i][1];
       p[i][0]/=5;
       p[i][1]/=5;
       glVertex2dv(p[i]);
    }   
  glEnd();
  
}
void translation(double p[][2],double tx,double ty){
  for(int i=0;i<n;i++){
      p[i][0]+=tx;
      p[i][1]+=ty;
   }
}
void rotation(double p[][2],double theta){
  double p1[n][2];
 
    for(int i=0;i<n;i++){
       p1[i][0]=cos(theta)*p[i][0]-sin(theta)*p[i][1];
       p1[i][1]=sin(theta)*p[i][0]+cos(theta)*p[i][1];
       p[i][0]=p1[i][0];
       p[i][1]=p1[i][1];
    }   
 
}
void scaling(double p[][2],double sx,double sy){
  for(int i=0;i<n;i++){
      p[i][0]*=sx;
      p[i][1]*=sy;
   }
}   
void display(void){
  //glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glColor3f(1,1,0);
  
  
  
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
   