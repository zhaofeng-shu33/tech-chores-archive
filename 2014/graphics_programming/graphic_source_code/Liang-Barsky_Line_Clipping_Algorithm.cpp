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
struct wcPt2D{
  double x,y;
};  
void init(void){
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(-winWidth/2,winWidth/2,-

winHeight/2,winHeight/2);
}

void reshape(int newWidth,int newHeight){
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0,(GLdouble)newWidth,0,(GLdouble)newHeight);
  glClear(GL_COLOR_BUFFER_BIT);  
 
}
bool clipTest(double p,double q,double& u1,double& u2){
  double r;
  bool returnValue=true;
  if(p<0.0){
     r=q*1.0/p;
     if(r>u2)
        returnValue=false;
     else if(r>u1)
          u1=r;
  }
  else if(p>0.0){
      r=q*1.0/p;
      if(r<u1)
         returnValue=false;
      else if(r<u2)
         u2=r;
  }
       else if(q<0.0)
            returnValue=false;
  return(returnValue);
}      
void lineClip(wcPt2D winMin,wcPt2D winMax,wcPt2D p1,wcPt2D p2){ //change to triangle region
  double u1=0.0,u2=1.0,dx=p2.x-p1.x,dy;
  
  if(clipTest(-dx,p1.x-winMin.x,u1,u2)&&clipTest(dx,winMax.x-p1.x,u1,u2)){
       dy=p2.y-p1.y;
       if(clipTest(-dy,p1.y-winMin.y,u1,u2)&&clipTest(dy,winMax.y-p1.y,u1,u2)){
         if(u2<1.0){
           p2.x=p1.x+u2*dx;
           p2.y=p1.x+u2*dy;  
         }
         if(u1>0.0){
           p1.x+=u1*dx;
           p1.y+=u1*dy;
         }
           glBegin(GL_LINES);
             glVertex2d(p1.x,p1.y);
             glVertex2d(p2.x,p2.y);
           glEnd();
     
       }
  }      
    
    
     
}  
void display(void){
  //glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glColor3f(1,1,0);
  glBegin(GL_LINE_LOOP);
    glVertex2i(-120,-100);
    glVertex2i(120,-100);
    glVertex2i(120,100);
    glVertex2i(-120,100);
  
  glEnd();
  
  wcPt2D winMin={-120,-100},winMax={120,100},p1={-100,-130},p2={170,-40};
  lineClip(winMin,winMax,p1,p2);
  /*glBegin(GL_LINES);
    glVertex2i(-100,-130);
    glVertex2i(170,-40);
  glEnd();
  */
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
   