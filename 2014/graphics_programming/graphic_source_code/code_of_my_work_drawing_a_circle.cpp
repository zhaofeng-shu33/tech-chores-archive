#include<iostream>
#include<GL/glu.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
const double Pi=3.14159;
using namespace std;
void init(void){
  glMatrixMode(GL_PROJECTION);
 // gluOrtho2D(0,400,0,300);
   glOrtho(0, 1.5, 0, 1.5, -10, 10);
}
void drawBox()
{
  glClear(GL_COLOR_BUFFER_BIT);
    GLint x=0,y=0,z=0,w=1,h=1,d=1;
    glBegin(GL_QUADS);
        //front
        glVertex3f(x-w, y+h, z+d);
        glVertex3f(x-w, y-h, z+d);
        glVertex3f(x+w, y-h, z+d);
        glVertex3f(x+w, y+h, z+d);

        //bottom
        glVertex3f(x-w, y-h, z+d);
        glVertex3f(x+w, y-h, z+d);
        glVertex3f(x+w, y-h, z-d);
        glVertex3f(x-w, y-h, z-d);

        //back
        glVertex3f(x+w, y+h, z-d);
        glVertex3f(x+w, y-h, z-d);
        glVertex3f(x-w, y-h, z-d);
        glVertex3f(x-w, y+h, z-d);
    
        //top
        glVertex3f(x-w, y+h, z+d);
        glVertex3f(x+w, y+h, z+d);
        glVertex3f(x+w, y+h, z-d);
        glVertex3f(x-w, y+h, z-d);

        //left
        glVertex3f(x-w, y+h, z+d);
        glVertex3f(x-w, y-h, z+d);
        glVertex3f(x-w, y-h, z-d);
        glVertex3f(x-w, y+h, z-d);

        //right
        glVertex3f(x+w, y+h, z+d);
        glVertex3f(x+w, y-h, z+d);
        glVertex3f(x+w, y-h, z-d);
        glVertex3f(x+w, y+h, z-d);
 
        glEnd();
        glFlush();
}
//void reshape
double a=100/sqrt(3.0); 
void cube();
void quad(GLint n1,GLint n2,GLint n3,GLint n4){
   int m=1;
   GLint pt[8][3]={{0,0,0},{0,m,0},{m,0,0},{m,m,0},{0,0,m},{0,m,m},{m,0,m},{m,m,m}};
   glBegin(GL_QUADS);
   glVertex3iv(pt[n1]);
   glVertex3iv(pt[n2]);   
   glVertex3iv(pt[n3]);
   glVertex3iv(pt[n4]);
   glEnd();
   cout<<"I am used/n";
}
void reshape(int width, int height)
{
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.5, 1.5, -1.5, 1.5, -10, 10);
}
void displayBall(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSolidSphere(1.0, 20, 16);
    glFlush();
}    
void lineSegment(void){
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_LINES);
    glVertex2i(196,100);
    glVertex2i(196,150);
    glVertex2i(100,200);
  glEnd();
  //double p[6][2]={{0,150},{a/2,200},{1.5*a,200},{2*a,150},{1.5*a,100},{a/2,100}};
  int n=50;
  double p[n][2];
  for(int i=0;i<n;i++){
      p[i][0]=200+85*cos(i*2*Pi/n);
      p[i][1]=150+50*sin(i*2*Pi/n);
  }  
  glBegin(GL_LINE_LOOP);
    for(int i=0;i<n;i++)
       glVertex2dv(p[i]);   //approximate to the circle.
  glEnd();
  //glRecti(200,100,50,250);
  glFlush();
}  
int main(int argc, char* argv[])
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(50,100);
  glutInitWindowSize(400, 300);
  glutCreateWindow("My first example");
  
  init();
  
  glutDisplayFunc(drawBox); 
  //reshape(1,1);
  glutMainLoop();
  return 0;
} 
void myDisplay(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
  glFlush();
}

/*int main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(400, 400);
  glutCreateWindow("第一个OpenGL程序");
  glutDisplayFunc(&myDisplay);
  glutMainLoop();
   return 0;
}*/
void cube(){
   glClear(GL_COLOR_BUFFER_BIT);
   quad(6,2,3,7);
   quad(5,1,0,4);
   quad(7,3,1,5);
   quad(4,0,2,6);
   quad(2,0,1,3);
   quad(7,5,4,6);
   glFlush();
   }  
 