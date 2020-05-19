#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<cstring>
using namespace std;
GLsizei ww=500,wh=500;
struct wcPt2D{
  double x,y;
};
void
bitmap_output(double x, double y,double z, char *string)
{
  int len, i;

  glRasterPos3f(x,y,z);
  len = (int) strlen(string);
  for (i = 0; i < len; i++) {
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, string[i]);
  }
}
  
void init(){
  //glClearColor(0.5,0.5,0.5,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(5,5,5,0,0,0,0,0,1);
 
    glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    double m=2;
   // gluPerspective(80,1,0,2);
    glOrtho(-m,m,-m,m,-30,30);
    glMatrixMode(GL_MODELVIEW);
   // glOrtho(-ww/2,-wh/2,ww/2,wh/2,-300,300);
}
void reshape(int w,int h){
    glViewport(0,0,w,h);
   ww=w;
   wh=h;
} 
double angle1=0,angle2=40,angle3=0; //angle1 represents precession;angle2 represents nutation and angle3 represents rotation around the 
void display1(void){                //symmetric axis of the cone.
  glClear(GL_COLOR_BUFFER_BIT);
  glLineWidth(1);
  glColor3f(0.5,0.5,0.5);
  glTranslatef(0.7,0.7,0);
  glBegin(GL_LINES);
    glVertex3i(5,0,0);
    glVertex3i(-5,0,0);
    glVertex3i(0,5,0);
    glVertex3i(0,-5,0);
    glVertex3i(0,0,5);
    glVertex3i(0,0,0); 
  glEnd();
  glRasterPos3i(1,0,0);
  glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'x');
  glRasterPos3i(0,1,0);
  glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'y');
  glRasterPos3i(0,0,1);
  glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'z');
  glLineWidth(2);
  bitmap_output(1.5,-1.3,2.5,"The rotation rate is four times than the precession rate");
  glPushMatrix();
  glRotatef(angle1,0,0,1);
  glRotatef(angle2,0,1,0);
  glRotatef(angle3,0,0,1);
  
  glColor3f(1,1,1);
  glBegin(GL_LINES);
    glVertex3i(5,0,0);
    glVertex3i(0,0,0);
    glVertex3i(0,5,0);
    glVertex3i(0,0,0);
    glVertex3i(0,0,5);
    glVertex3i(0,0,0); 
  glEnd();
  
  bitmap_output(1,0,0,"X\'");
  bitmap_output(0,1,0,"Y\'");
  bitmap_output(0,0,1,"Z\'");
  glLineWidth(2);
 
  
  glTranslatef(0,0,2.3);
  glScalef(1,1,-1);
  glutWireCone(0.8,2.3,8,6);
  glPopMatrix();
  
 /* glPushMatrix(); 
  glRotatef(angle1,0,0,1);
  glBegin(GL_LINES);
    glVertex3i(5,0,0);
    glVertex3i(0,0,0);
    glVertex3i(0,5,0);
    glVertex3i(0,0,0);
    glVertex3i(0,0,5);
    glVertex3i(0,0,0); 
  glEnd();
  
  glColor3f(1,1,0);
  glRotatef(angle2,0,1,0);
  glBegin(GL_LINES);
    glVertex3i(5,0,0);
    glVertex3i(0,0,0);
    glVertex3i(0,5,0);
    glVertex3i(0,0,0);
    glVertex3i(0,0,5);
    glVertex3i(0,0,0); 
  glEnd();
  glRotatef(angle3,0,0,1);
  
  glPopMatrix();  
 */ 
  
 
 
 glTranslatef(-0.7,-0.7,0);
 glFlush();
 angle1+=0.01;
 angle3+=0.04;
 glutPostRedisplay(); 
}    
int main(int argc, char** argv){
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowPosition(50,100);
  glutInitWindowSize(ww,wh);
  glutCreateWindow("One");
  glutDisplayFunc(display1);
  init();
  glutReshapeFunc(reshape);
  
  
  
  glutMainLoop();
  return 0;
}  
