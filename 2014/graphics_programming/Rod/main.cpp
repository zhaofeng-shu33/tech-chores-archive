#include<iostream>
#include<GL/glu.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<ctime>
#include<deque>
int winWidth(400);
int winHeight(400);
const double pi=3.15926;//second;
using namespace std;
                               // win the game, otherwise you lose the game.

struct screenPt{
   double x;
   double y;
};

void reshape(int newWidth,int newHeight){
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-1*(GLdouble)newWidth/2,(GLdouble)newWidth/2,-1*(GLdouble)newHeight/2,(GLdouble)newHeight/2);
  winWidth=newWidth,winHeight=newHeight;
  glViewport(0,0,newWidth,newHeight);
  glClear(GL_COLOR_BUFFER_BIT);  
}

class Rod{
  private: 
    float r;
    float L;
    float angle;
    float angleVelocity;
  public:
    float get_angle(){return angle;}
    Rod(float rnew,float Lnew,float anglenew,float angleVelocitynew){
      r=rnew;
      L=Lnew;
      angle=anglenew*pi/180.0;
      angleVelocity=angleVelocitynew;
    }
    void update_angle(float time_elapsed){angle+=time_elapsed*angleVelocity;}  
     void draw(){
      glBegin(GL_LINES);
      glColor3f(255.0f,255.0f,0.0f);
      glVertex2f(2*L*cos(angle),0);
      glVertex2f(0,2*L*sin(angle));
      glColor3f(255.0f,255.0f,255.0f);
      glVertex2f(0,0);
      glVertex2f(L*cos(angle),L*sin(angle));
      glEnd();
    }  
};




Rod myRod(1,100,45,0.001);
void init(void){
  glViewport(0,0,winWidth,winHeight);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(-1*(GLdouble)winWidth/2,(GLdouble)winWidth/2,-1*(GLdouble)winHeight/2,(GLdouble)winHeight/2);
}
 
void display(void){
  
 glClear(GL_COLOR_BUFFER_BIT);
  glLineWidth(5);
  myRod.update_angle(0.1);
  
  myRod.draw();
  glBegin(GL_LINES);
  glVertex2i(-200,0);
  glVertex2i(200,0);
  glVertex2i(0,-200);
  glVertex2i(0,200);
  glEnd(); 
  
//  glPointSize(10.0);
   glFlush();
  glutSwapBuffers ();
  // GLfloat myPointSize;
  // glGetFloatv(GL_POINT_SIZE,&myPointSize);
}

void idle(){
 // calculateFPS();
  glutPostRedisplay();
}
int main(int argc, char* argv[])
{ 
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB|GLUT_DEPTH);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(winWidth,winHeight);
  
  init();
  glutCreateWindow("window");
  glutDisplayFunc(display);
  glutReshapeFunc(reshape); 
  glutIdleFunc(idle);

 
  glutMainLoop();  
  
  return 0;
} 
   

