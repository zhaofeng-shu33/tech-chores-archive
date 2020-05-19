#include<iostream>
#include<vector>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<chrono>
#include<thread>

const double Pi=3.1415926;
using namespace std;
int ww=400,wh=100;
int radius=8;
const double alpha=0.4;
double beta=1;//tangential resolution
vector<double> rx;
vector<double> ry;

typedef double position,orientationAngle,velocity,
rotationalVelocity,linearAcceleration,angularAcceleration;
  
class Kinematic{
  private:
    position x,y;
    orientationAngle theta;// 0<=theta<=2Pi;
    velocity vx,vy;
    linearAcceleration ax,ay;   
    rotationalVelocity omega;
 public:
    Kinematic(position x0,position y0,velocity vx0,velocity vy0,rotationalVelocity omega0=0,
    orientationAngle theta0=0,linearAcceleration ax=0,linearAcceleration ay=0  ):
      x(x0),y(y0),vx(vx0),vy(vy0),theta(theta0),ax(0),ay(-9.8)
      {
        setNewOrientation(vx0,vy0);
        omega=0;
       // omega=sqrt(vx*vx+vy*vy)/radius;
      }
    void update(double time){
      x+=vx*time+0.5*ax*time*time;
      y+=vy*time+0.5*ay*time*time;
  //    theta+=omega*time+0.5*steering.alpha*time*time;
      vx+=ax*time;
      vy+=ay*time;
  //    omega+=steering.alpha*time;
    };
    double getx(){return x;}
    double gety(){return y;}
    double getvx(){return vx;}
    double getvy(){return vy;}
    double getomega(){return omega;}
    float getTheta(){return theta;} 
    void  setvx(double vnewx){vx=vnewx;}
    void setvy(double vnewy){vy=vnewy;}
    void setomega(double omeganew){omega=omeganew;}
    void setNewOrientation(double x1,double y1){
      if(x1*x1+y1*y1>0){
         if(x1>0)
         theta=atan(y1/x1);
         else
         theta=atan(y1/x1)+Pi;
      }
    if(theta<0)
    theta+=2*Pi;
    }
    void setNewVelocity(double theta1){
      double v=sqrt(vx*vx+vy*vy);
      vx=v*cos(theta1);
      vy=v*sin(theta1);
    }     
};
void init1(){
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(-ww/2,ww/2,-wh/2,wh/2);
  glBegin(GL_LINES);
    //glVertex2i(0,200);
    //glVertex2i(400,200);
    glVertex2i(200,0);
    glVertex2i(200,400);
  glEnd();
}
Kinematic object(100,100,-5,-5);
void drawObject(void){
  glPointSize(5);
  glColor3f(1,0,0);
  glBegin(GL_POINTS);
  glVertex2f(object.getx(),object.gety());
  glEnd();
  glColor3f(1,1,1);  
}
                                                                                                                                             
void display1(void){
  drawObject();
  rx.push_back(object.getx());
  ry.push_back(object.gety());
  glBegin(GL_POINTS);    
    for(int i=0;i<rx.size();i++)
        glVertex2f(rx[i],ry[i]);
  glEnd();
  glFlush();
  object.update(0.1);
  std::chrono::milliseconds timespan(100);
  std::this_thread::sleep_for(timespan); 
  glClear(GL_COLOR_BUFFER_BIT);  
}

void idle(){
  glutPostRedisplay();
}  
void ProcessMouse(int buttton,int state,int x,int y){
  object.setNewOrientation(x-object.getx(),wh-y-object.gety());
  object.setNewVelocity(object.getTheta());  
}  
int main(int argc, char* argv[]){
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
  glutInitWindowPosition(200,200);
  glutInitWindowSize(ww,wh);
  glutCreateWindow("Three-Dimensional Object Representations");
  glutDisplayFunc(display1);
  init1();
  glutMouseFunc(ProcessMouse);
  glutIdleFunc(idle);
  glutMainLoop();
  return 0;
} 
 
