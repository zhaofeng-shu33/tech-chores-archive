#include<iostream>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
const double Pi=3.14159;
using namespace std;

int winWidth=500,winHeight=500;
double rotTheta=0;
int regHex;
struct screenPt{
  double x,y;
};  
void init1(){
  glClear(GL_COLOR_BUFFER_BIT);
  //glMatrixMode(GL_MODELVIEW);
  
  
  }  
void init2(void){
  glMatrixMode(GL_PROJECTION);
  glOrtho(-winWidth,winHeight,-winHeight,winHeight, -10, 10);
  regHex=glGenLists(1);
  double hexTheta=0;
  screenPt hexVertex;
  glNewList(regHex,GL_COMPILE);
    glBegin(GL_POLYGON);
      for(int i=0;i<6;i++){
          hexTheta=i*Pi/3;
          hexVertex.x=80*cos(hexTheta);
          hexVertex.y=80*sin(hexTheta);
          glVertex2d(hexVertex.x,hexVertex.y);
      }
    glEnd();  
  glEndList();
}
void rotateHex(){
  rotTheta+=3;
  if(rotTheta>360)
     rotTheta-=360;
  glutPostRedisplay();
}  
void displayHex(void){
  glClear(GL_COLOR_BUFFER_BIT);
  //glPushMatrix();
  glRotatef(rotTheta,0,0,1);
  glCallList(regHex);
 // glPopMatrix();
 // glutSwapBuffers();
  glFlush();
  glutSwapBuffers();
}
double theta[3]={0,0,0}; 
void display(void){
  
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  gluLookAt(5,5,5,0,0,0,0,0,1);
  glBegin(GL_LINES);
    glVertex3i(100,0,0);
    glVertex3i(-100,0,0);
    glVertex3i(0,100,0);
    glVertex3i(0,-100,0);
    glVertex3i(0,0,100);
    glVertex3i(0,0,-100);
  glEnd();
  glRasterPos3i(1,0,0);
  glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'x');  
  glRasterPos3i(0,1,0);
  glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'y');  
  glRasterPos3i(0,0,1);
  glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'z');  
  
  glColor3f(1,1,0);
  
  GLUquadricObj* cylinder1;
  cylinder1=gluNewQuadric();
  gluQuadricDrawStyle(cylinder1,GLU_LINE);
  gluCylinder(cylinder1,0.75,0.75,1,8,8);
  
  glRotatef(theta[0],1,0,0);
  glRotatef(theta[1],0,1,0);
  glRotatef(theta[2],0,0,1);
  
  glPushMatrix();
  glTranslatef(0,0,2);
  glutWireTeapot(0.5);
  glPopMatrix();
  
  glPushMatrix();
  glTranslatef(2,0,0);
  GLUquadricObj* disk1;
  disk1=gluNewQuadric();
  gluQuadricDrawStyle(disk1,GLU_LINE);
  gluPartialDisk(disk1,0.2,0.8,6,6,-30,60);
  glFlush();
  gluDeleteQuadric(cylinder1);
  gluDeleteQuadric(disk1);
  
  glutSwapBuffers();
}  
void myKey(unsigned char key, int x, int y){
  if(key=='r')
     glutIdleFunc(rotateHex);
  if(key=='n')
     glutIdleFunc(NULL);
}
void drawRectangle(int x,int y){
  y=winHeight-y;
  glRecti(x,y,x+10,y+20);
  glFlush();
}    

void myMouse2(int btn,int state,int x,int y){
  y=winHeight-y;
  if(btn==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)
     glutIdleFunc(rotateHex);
   
  if(btn==GLUT_RIGHT_BUTTON&&state==GLUT_DOWN) 
     glutIdleFunc(NULL);
  glutPostRedisplay();
}int axis=-1;
void startSpin(){
  if(axis==-1) return;
  else{
    theta[axis]+=0.1;//manipulate the velocity!
    if(theta[axis]>360){
       theta[axis]-=360;
       //axis=-1;
    }  
  //cout<<theta[axis]<<endl;
  glutPostRedisplay();
  }
}    
void myMouse1(int btn,int state,int x,int y){
   if(btn==GLUT_LEFT_BUTTON&&state==GLUT_DOWN){
      axis=0;
      glutIdleFunc(startSpin);
   }  
   if(btn==GLUT_RIGHT_BUTTON&&state==GLUT_DOWN){ axis=-1;
      glutIdleFunc(startSpin);
   }  
}


void reshape(int newWidth,int newHeight){
  glViewport(0,0,newWidth,newHeight);
  glMatrixMode(GL_PROJECTION);
  glOrtho(-2,2,-2,2,-100,100);
  glMatrixMode(GL_MODELVIEW);
  glClear(GL_COLOR_BUFFER_BIT);
}  
int n=60; 
void myTimer(int v){
  glutPostRedisplay();
  glutTimerFunc(1000/n,myTimer,v); 
}  
int main(int argc, char* argv[]){
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_DOUBLE| GLUT_RGB);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(winWidth,winHeight);
  glutCreateWindow("Three-Dimensional Object Representations");
  init1();
  glutDisplayFunc(display);
  
  
  /*glutInitWindowPosition(800,100);
  glutCreateWindow("Rotate a Hexagon");
  glutDisplayFunc(displayHex);
  init2();
  
  */
  glutReshapeFunc(reshape);
 // glutTimerFunc(100,myTimer,n);
  //glutKeyboardFunc(myKey);
  glutMouseFunc(myMouse1);
  
  //glutMotionFunc(drawRectangle);
  glutMainLoop();
  return 0;
} 
 