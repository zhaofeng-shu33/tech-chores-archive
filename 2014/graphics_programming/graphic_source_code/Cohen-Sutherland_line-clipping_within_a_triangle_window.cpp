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
GLubyte winLeftBitCode=0x01,winRightBitCode=0x02,winBottomBitCode=0x04;
int k=2,b=120,d=-100;
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
  gluOrtho2D(0,(GLdouble)newWidth,0,

(GLdouble)newHeight);
  glClear(GL_COLOR_BUFFER_BIT);  
 
}
GLubyte encode(wcPt2D pt){
  GLubyte code=0x00;
  if(pt.y>k*pt.x+b)
     code=code|winLeftBitCode;
  if(pt.y>-k*pt.x+b)
     code=code|winRightBitCode;
  if(pt.y<d)
     code=code|winBottomBitCode;
  return code;
}  
void swapPts(wcPt2D* p1, wcPt2D* p2){
  wcPt2D tem;
  tem=*p1;
  *p1=*p2;
  *p2=tem;
}
void swapCodes(GLubyte* c1,GLubyte* c2){
  GLubyte tem;
  tem=*c1;
  *c1=*c2;
  *c2=tem;
}    
void lineClip(wcPt2D p1,wcPt2D p2){ //change to triangle region
  GLubyte code1,code2;
  double m;
  bool done=false,plotline=false;
  while(!done){
     code1=encode(p1);
     code2=encode(p2);
     if(!bool(code1|code2)){
        done=true;
        plotline=true;
      }
      else
         if(bool(code1&code2))  
            done=true;
         else{
            if(!bool(code1)){
               swapPts(&p1,&p2);
               swapCodes(&code1,&code2);
            }    
            if(p2.x!=p1.x)
               m=(p2.y-p1.y)*1.0/(p2.x-p1.x);
            if(code1&winLeftBitCode){
               if(p2.x!=p1.x)
                  p1.x=(-b+p1.y-p1.x*m)*1.0/(k-m);
               p1.y=k*p1.x+b;
            }
            else
               if(code1&winRightBitCode){
                  if(p2.x!=p1.x)
                  p1.x=(-b+p1.y-p1.x*m)*1.0/(-k-m);
                  p1.y=-k*p1.x+b;
               }
               else
                  if(code1&winBottomBitCode){
                     if(p2.x!=p1.x)
                        p1.x+=(d-p1.y)*1.0/m;
                     p1.y=d;
                  }
                 
           
         }  
        
  
  
  } 
  if(plotline){
     glBegin(GL_LINES);
       glVertex2d(p1.x,p1.y);
       glVertex2d(p2.x,p2.y);
     glEnd();
  }   
}  
void display(void){
  //glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glColor3f(1,1,0);
  glBegin(GL_LINE_LOOP);
    glVertex2i(-110,-100);
    glVertex2i(110,-100);
    glVertex2i(0,120);
  
  glEnd();
  
  wcPt2D p1={-100,-130},p2={170,-40};
  lineClip(p1,p2);
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
   