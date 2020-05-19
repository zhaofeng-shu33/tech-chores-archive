#include<iostream>
#include<GL/glu.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
double Pi=3.14159;
using namespace std;
GLsizei winWidth=600,winHeight=500;
struct screenPt{
   GLdouble x;
   GLdouble y;
};
typedef enum{ limacon=1,cardioid,threeLeaf,fourLeaf,spiral} curveName;
void lineSegment(screenPt pt1, screenPt pt2){
  glBegin(GL_LINES);
      glVertex2d(pt1.x,pt1.y);
      glVertex2d(pt2.x,pt2.y);
  glEnd();
}    
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
void drawCurve(GLint);
void display(void){
  GLint curveNum;
  glClear(GL_COLOR_BUFFER_BIT);
  cout<<"enter the integer value corresponding to\n";
  cout<<"one of the following curve names.\n";
  cout<<"Press any other key to exit.\n";
  cout<<"\n1-limacon, 2-cardioid, 3-threeLeaf, 4-fourLeaf, 5-spiral:  ";
  cin>>curveNum;
  if(curveNum==1||curveNum==2||curveNum==3||curveNum==4||curveNum==5)
     drawCurve(curveNum);
  else 
     exit(0);
  glFlush();  
}   
        
int main(int argc, char* argv[])
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(winWidth,winHeight);
  glutCreateWindow("draw curves");
  init();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();  
  
  return 0;
} 
void drawCurve(GLint curveNum){
  GLint a=175,b=60;
  if(curveNum==cardioid){
     curveNum=limacon;
     b=a;
  }  
  GLfloat r,theta,dtheta=1.0/a;
  GLint x0=200,y0=250;
  screenPt curvePt[2];
  curvePt[0].x=x0;
  curvePt[0].y=y0;
  switch(curveNum){
    case limacon: curvePt[0].x+=a+b;break;
    case threeLeaf: curvePt[0].x+=a;break;
    case fourLeaf: curvePt[0].x+=a;break;
    case spiral: break;
    default: break;
  }
  theta=dtheta;
  while(theta<2*Pi){
       switch(curveNum){
           case limacon: 
              r=a*cos(theta)+b;    break;
           case threeLeaf: 
              r=a*cos(3*theta);    break;
           case fourLeaf:
              r=a*cos(2*theta);    break;
           case spiral: 
              r=(a/4.0)*theta;     break;
           default: break;
      }
      curvePt[1].x=x0+r*cos(theta);
      curvePt[1].y=y0+r*sin(theta);
      glBegin(GL_POINTS);
        glVertex2d(curvePt[1].x,curvePt[1].y);
      glEnd();
      theta+=dtheta;
  }  
       
  
  
  
  
}     
   