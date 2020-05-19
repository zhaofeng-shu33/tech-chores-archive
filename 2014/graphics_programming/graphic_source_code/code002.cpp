#include<iostream>
#include<GL/glu.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
const double Pi=3.14159;
int n=60;
using namespace std;
GLsizei winWidth=400,winHeight=400;
GLint card;
class screenPt{
  private:
     GLdouble x,y;
  public:
     screenPt():x(0),y(0){}
     void setCoords(GLdouble xCoord,GLdouble yCoord){
       x=xCoord;
       y=yCoord;
     }
     GLdouble getx() {
       return x;
     }
     GLdouble gety(){
       return y;
     }
};      
void init(void){
  
  screenPt pt,center;
  GLdouble theta,r;
  center.setCoords(winWidth/2,winHeight/2);
  card=glGenLists(1);
  glNewList(card,GL_COMPILE_AND_EXECUTE);
    glBegin(GL_POLYGON);
        for(int i=0;i<n;i++){
            theta=2*Pi*i/n;
            r= 100*(1-cos(theta));
            pt.setCoords(center.getx()+r*cos(theta),center.gety()+r*sin(theta));
            glVertex2d(pt.getx(),pt.gety());
        }  
    glEnd();
  glEndList();  

    

}
void display(void);
void cardioid(void){
  glClear(GL_COLOR_BUFFER_BIT);    
  glCallList(card);  
  glFlush();
}
void reshape(int newWidth,int newHeight){
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0,(GLdouble)newWidth,0,(GLdouble)newHeight);
  glClear(GL_COLOR_BUFFER_BIT);  
 // gluOrtho2D(0,winWidth,0,winHeight);
  
}    
int main(int argc, char* argv[])
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(winWidth,winHeight);
  glutCreateWindow("This test shows the shape of the cardioid.");
  init();
  glutDisplayFunc(cardioid);
  glutReshapeFunc(reshape);
  glutMainLoop();
  return 0;
} 
void display(void){
  glClear(GL_COLOR_BUFFER_BIT);
  GLubyte bitShape[20]={0x1c,0x00,0x1c,0x00,0x1c,0x00,0x1c,0x00,0x1c,0x00,0xff,0x80,0x7f,0x00,0x3e,0x00,0x1c,0x00,0x08,0x00};
  glPixelStorei(GL_UNPACK_ALIGNMENT,1);
  glRasterPos2i(30,40);
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'A');
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'B');
  //cout<<glutBitmapWidth(GLUT_BITMAP_TIMES_ROMAN_24,'B');
  //glBitmap(9,10,0,0,70,70,bitShape);
  glFlush();
}   