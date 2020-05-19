#include<iostream>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<time.h>
const double Pi=3.14159;
using namespace std;
int ww=400,wh=400;
static int cnt;  
static clock_t first;
typedef double position,orientationAngle,velocity,
 orientationChangeRate,linearAcceleration,angularAcceleration;
double CalFrequency()
{
     static double save;
     static clock_t current;
     double timegap;
     if(cnt < 50 ){     
     ++cnt;
     return save;
     }  
     cnt = 100;
     current = clock();
     cout<<endl<<current<<endl;
     timegap = (current-first)/(double)CLOCKS_PER_SEC;
     save = 50.0/timegap;
     return save;
}
struct SteeringOutput{
  linearAcceleration ax,az;
//  angularAcceleration alpha;
};
  
class Kinematic{
  private:
    position x,z;
    orientationAngle theta;// 0<=theta<=2Pi;
    velocity vx,vz;
  //  orientationChangeRate omega;
 public:
    Kinematic(position x0,position z0,velocity vx0,velocity vzo,orientationAngle theta0):x(x0),z(z0),vx(vx0),vz(vzo),theta(theta0){};
    void update(SteeringOutput steering, double time){
      x+=vx*time+0.5*steering.ax*time*time;
      z+=vz*time+0.5*steering.az*time*time;
  //    theta+=omega*time+0.5*steering.alpha*time*time;
      vx+=steering.ax*time;
      vz+=steering.az*time;
  //    omega+=steering.alpha*time;
    };
    double getx(){return x;}
    double getz(){return z;}
    double getvx(){return vx;}
    double getvz(){return vz;}
    float getTheta(){return theta;} 
    void  setvx(double vnewx){vx=vnewx;}
    void setvz(double vnewz){vz=vnewz;}
    void setNewOrientation(){
      if(vx*vx+vz*vz>0){
         if(vx>0)
         theta=atan(vz/vx);
         else
         theta=atan(vz/vx)+Pi;
      }
    if(theta<0)
    theta+=2*Pi;
    }   
};
int maxSpeed=30;
void pursuit(Kinematic& pursuer,Kinematic& pursued){
  position relativeDisplacementx,relativeDisplacementz;
  relativeDisplacementx=pursued.getx()-pursuer.getx();  
  relativeDisplacementz=pursued.getz()-pursuer.getz();
  //if(relativeDisplacementx==0)cout<<"Error!";
 // cout<<relativeDisplacementx<<endl;
  double relativeDisplacementLength=sqrt(pow(relativeDisplacementx,2.0)+pow(relativeDisplacementz,2.0)),
  pursuerCurrentSpeed=relativeDisplacementLength/2;//sqrt(pow(pursuer.getvx(),2.0)+pow(pursuer.getvz(),2.0));
  if(pursuerCurrentSpeed>maxSpeed)
     pursuerCurrentSpeed=maxSpeed;
  pursuer.setvx(pursuerCurrentSpeed*relativeDisplacementx/relativeDisplacementLength);
  pursuer.setvz(pursuerCurrentSpeed*relativeDisplacementz/relativeDisplacementLength);
  pursuer.setNewOrientation();  
}  
void init1(){
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0,ww,0,wh);
  glBegin(GL_LINES);
    //glVertex2i(0,200);
    //glVertex2i(400,200);
    glVertex2i(200,0);
    glVertex2i(200,400);
  glEnd();
  first=clock();
  cout<<first<<endl;
}
Kinematic pursued(0,200,8,0,0),pursuer(8,8,0,maxSpeed,Pi/2);
SteeringOutput myAcceleration={0,0};
//void specialRotation(double rx,double rz,double angle,double x,double z){
//  double xnew=(x-rx)*cos(angle)+(z-rz)*sin(angle)+rx;
  
void drawPursuer(void){
  //double tmpx,tmpz,tmpAngle=Pi/2-pursuer.getTheta();
  glPushMatrix();
  glTranslatef(pursuer.getx(),pursuer.getz(),0);
  glRotatef(270+pursuer.getTheta()*180/Pi,0,0,1); 
  glTranslatef(-pursuer.getx(),-pursuer.getz(),0);
  glBegin(GL_POLYGON);
    glVertex2d(pursuer.getx()-8,pursuer.getz()-8);
    glVertex2d(pursuer.getx()+8,pursuer.getz()-8);
    glVertex2d(pursuer.getx()+8,pursuer.getz()+8);
    glVertex2d(pursuer.getx(),pursuer.getz()+16);
    glVertex2d(pursuer.getx()-8,pursuer.getz()+8);
  glEnd();
  glPopMatrix();    
 // glLoadIdentity();
  
}
void drawPursued(void){
    glBegin(GL_POLYGON);
    glVertex2d(pursued.getx(),pursued.getz()+8);
    glVertex2d(pursued.getx()+24,pursued.getz());
    glVertex2d(pursued.getx(),pursued.getz()-8);
    glEnd();
}  
void display1(void){
     
  glClear(GL_COLOR_BUFFER_BIT);
  if(fabs(pursuer.getz()-200)>0.01||fabs(pursuer.getx()-pursued.getx())>0.01){
       
       drawPursuer();
       glColor3f(1,1,0);
       drawPursued();  
       
    pursued.update(myAcceleration,0.001);
    pursuer.update(myAcceleration,0.001);
    pursuit(pursuer,pursued);
  }
  glFlush();
}
void idle(){
  glutPostRedisplay();
  if(cnt!=100)
  cout<<CalFrequency()<<' '; 
}  
int main(int argc, char* argv[]){
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
  glutInitWindowPosition(200,200);
  glutInitWindowSize(ww,wh);
  glutCreateWindow("Three-Dimensional Object Representations");
  glutDisplayFunc(display1);
  init1();
  glutIdleFunc(idle);
  glutMainLoop();
  return 0;
} 
 
