#include<iostream>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
const double Pi=3.14159;
using namespace std;
int ww=400,wh=400;
typedef float position,orientationAngle,velocity,
 orientationChangeRate,linearAcceleration,angularAcceleration;
struct SteeringOutput{
  linearAcceleration ax,az;
//  angularAcceleration alpha;
};  
class Kinematic{
  private:
    position x,z;
   // orientationAngle theta;// 0<=theta<=2Pi;
    velocity vx,vz;
  //  orientationChangeRate omega;
 public:
    Kinematic(position x0,position z0,velocity vx0,velocity vzo):x(x0),z(z0),vx(vx0),vz(vzo){};
    void update(SteeringOutput steering, float time){
      x+=vx*time+0.5*steering.ax*time*time;
      z+=vz*time+0.5*steering.az*time*time;
  //    theta+=omega*time+0.5*steering.alpha*time*time;
      vx+=steering.ax*time;
      vz+=steering.az*time;
  //    omega+=steering.alpha*time;
    };
    float getx(){return x;}
    float getz(){return z;} 
   /* void SetNewOrientation(){
      if(vx*vx+vz*vz>0){
         if(vz>0)
         theta=atan(vx/vz);
         else
         theta=atan(vx/vz)+Pi;
      }
    if(theta<0)
    theta+=2*Pi;
    }  */ 
           
};  
void init1(){
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0,ww,0,wh);
  glBegin(GL_LINES);
    glVertex2i(0,200);
    glVertex2i(400,200);
    glVertex2i(200,0);
    glVertex2i(200,400);
  glEnd();
}
Kinematic myObject(350,200,0,100);
SteeringOutput myAcceleration={-150,0};
void display1(void){
  
  glPointSize(4);
  glColor3f(1,1,0);
  //for(int i=0;i<7000;i++){
      glBegin(GL_POINTS);
        glVertex2f(myObject.getx(),myObject.getz());
      glEnd();
      myObject.update(myAcceleration,0.001);
      myAcceleration.ax=-(myObject.getx()-200);
      myAcceleration.az=-(myObject.getz()-200);
  //}  
  glFlush();
}
void idle(){
  glutPostRedisplay();
}  
int main(int argc, char* argv[]){
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(ww,wh);
  glutCreateWindow("Three-Dimensional Object Representations");
  glutDisplayFunc(display1);
  init1();
  glutIdleFunc(idle);
  glutMainLoop();
  return 0;
} 
 