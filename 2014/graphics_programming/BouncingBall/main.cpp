#include<iostream>
#include<fstream>
#include<vector>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>

const double Pi=3.1415926;
using namespace std;
int ww=100,wh=400;
int radius=8;
int timeOfCollision=0;
bool enabled=1;
const double alpha=0.4;
double beta=1;//tangential resolution
vector<double> rx;
vector<double> ry;

typedef double position,orientationAngle,velocity,
rotationalVelocity,linearAcceleration,angularAcceleration,rotationAngle;

class Kinematic{
  private:
    position x,y;
    orientationAngle theta;// 0<=theta<=2Pi;
    velocity vx,vy;
    linearAcceleration ax,ay;   
    rotationalVelocity omega;
    rotationAngle angle;
 public:
    Kinematic(position x0,position y0,velocity vx0,velocity vy0,rotationalVelocity omega0=0,
    orientationAngle theta0=0,linearAcceleration ax=0,linearAcceleration ay=0,rotationAngle angle=0):
      x(x0),y(y0),vx(vx0),vy(vy0),theta(theta0),ax(0),ay(-9.8),angle(0)
      {
        setNewOrientation(vx0,vy0);
        omega=0;
       // omega=sqrt(vx*vx+vy*vy)/radius;
      }
    void update(double time){
      x+=vx*time+0.5*ax*time*time;
      y+=vy*time+0.5*ay*time*time;
      angle+=omega*time;
      vx+=ax*time;
      vy+=ay*time;
    };
    double getx(){return x;}
    double gety(){return y;}
    double getvx(){return vx;}
    double getvy(){return vy;}
    double getomega(){return omega;}
    double getangle(){return angle;}
    float getTheta(){return theta;} 
    void  setx(double newx){x=newx;}
    void sety(double newy){y=newy;}
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
  gluOrtho2D(0,ww,0,wh);
  glBegin(GL_LINES);
    //glVertex2i(0,200);
    //glVertex2i(400,200);
    glVertex2i(200,0);
    glVertex2i(200,400);
  glEnd();
  cout<<"�����ǿ���̨�������С��ÿ����ײ�����Ҫ������Լ��ˮƽ��������Ϊ����\n��ֱ��������Ϊ����ת��������ʱ��Ϊ��.ͼ�ν������½Ǵӱ�Ϊ(0,0).\n";
  cout<<"���¼����ϵ�P�������û��澲ֹ���ٰ�һ��P����ָ�����"<<endl; 
  cout<<"���潫չʾ���Ĵ���ײǰС����˶��켣�����Կ����趨�ĳ�ʼ�����ܷ���С���ڵڶ�����ײ����ԭ·�����س�ʼ��."<<endl; 
}
Kinematic object(0,400,35,-20);//horizontal distance x=100;
void drawObject(void){
  glBegin(GL_POLYGON);
    for(int i=0;i<12;i++)
    glVertex2d(object.getx()+radius*cos(Pi*i/6),object.gety()+radius*sin(Pi*i/6));
  glEnd();
  glPointSize(5);
  glBegin(GL_POINTS);
  glColor3f(1,0,0);
  glVertex2f(object.getx()+radius*cos(object.getTheta()),object.gety()+radius*sin(object.getTheta()));
  glColor3f(0,1,0);
  glVertex2f(object.getx()+radius*cos(object.getangle()),object.gety()+radius*sin(object.getangle())); 
  glEnd();
  glColor3f(1,1,1);  
}
                                                                                                                                             
void display1(void){
  //cout<<object.getomega()<<endl;
  drawObject();
  rx.push_back(object.getx());
  ry.push_back(object.gety());
  glBegin(GL_POINTS);    
    for(int i=0;i<rx.size();i++)
        glVertex2f(rx[i],ry[i]);
  glEnd();
  if (object.gety()<=radius&&object.getvy()<0)
     { 
       double tem=object.getvx();
       object.setvx(-(beta*alpha-1)*object.getvx()/(alpha+1)-alpha*(1+beta)*object.getomega()*radius/(alpha+1));
       object.setomega(-(1+beta)*tem/(radius*(alpha+1))+(alpha-beta)*object.getomega()/(alpha+1));
       object.setvy(-object.getvy());
       object.setNewOrientation(object.getvx(),-object.getvy());      
       cout<<"��ײ�����ˮƽ�ٶ�Ϊ��"<<object.getvx()<<" ��ֱ�ٶ�Ϊ�� "<<object.getvy()<<endl;
       cout<<" ת�����ٶ�Ϊ��"<<object.getomega()<<" ��ֱ����Ϊ "<<object.gety()<<endl; 
       timeOfCollision++;
       }
  else if(object.gety()>=wh-radius&&object.getvy()>0)
     { 
       double tem=object.getvx();
       object.setvx(-(beta*alpha-1)*object.getvx()/(alpha+1)+alpha*(1+beta)*object.getomega()*radius/(alpha+1));
       object.setomega((1+beta)*tem/(radius*(alpha+1))+(alpha-beta)*object.getomega()/(alpha+1));
       object.setvy(-object.getvy());
       object.setNewOrientation(object.getvx(),-object.getvy());      
       cout<<"��ײ�����ˮƽ�ٶ�Ϊ��"<<object.getvx()<<" ��ֱ�ٶ�Ϊ�� "<<object.getvy()<<endl;
       cout<<" ת�����ٶ�Ϊ��"<<object.getomega()<<" ��ֱ����Ϊ "<<object.gety()<<endl; 
       timeOfCollision++;
       }
  else if((object.getx()<=radius&&object.getvx()<0))
     {
       double tem=object.getvy();
       object.setvy(-(beta*alpha-1)*object.getvy()/(alpha+1)+alpha*(1+beta)*object.getomega()*radius/(alpha+1));
       object.setomega((1+beta)*tem/(radius*(alpha+1))+(alpha-beta)*object.getomega()/(alpha+1));
       object.setvx(-object.getvx());
       cout<<"��ײ�����ˮƽ�ٶ�Ϊ��"<<object.getvx()<<" ��ֱ�ٶ�Ϊ�� "<<object.getvy()<<endl;
       cout<<" ת�����ٶ�Ϊ��"<<object.getomega()<<" ��ֱ����Ϊ "<<object.gety()<<endl; 
       timeOfCollision++;
       }
   else if(object.getx()>=ww-radius&&object.getvx()>0){
       double tem=object.getvy();
       object.setvy(-(beta*alpha-1)*object.getvy()/(alpha+1)-alpha*(1+beta)*object.getomega()*radius/(alpha+1));
       object.setomega(-(1+beta)*tem/(radius*(alpha+1))+(alpha-beta)*object.getomega()/(alpha+1));
       object.setvx(-object.getvx());
       cout<<"��ײ�����ˮƽ�ٶ�Ϊ��"<<object.getvx()<<" ��ֱ�ٶ�Ϊ�� "<<object.getvy()<<endl;
       cout<<" ת�����ٶ�Ϊ��"<<object.getomega()<<" ��ֱ����Ϊ "<<object.gety()<<endl;    
       timeOfCollision++;
   }  
  else  { //cout<<object.getvx()<<' ';
    object.setNewOrientation(object.getvx(),object.getvy());
  }  
         
  while(timeOfCollision>3){
  cout<<"You can reset the parameter:"<<endl;
  cout<<"Please input the initial horizontal velocity and vertical velocity: "<<endl;
  cout<<"Input form is num+space+num"<<endl;
  double horizontal_velocity,vertical_velocity;
  cin>>horizontal_velocity;
  cin>>vertical_velocity;
  cout<<"Horizontal velocity is: "<<horizontal_velocity<<' '<<"and vertical velocity is: "<<vertical_velocity<<endl;
  if(horizontal_velocity<0||horizontal_velocity>1000||vertical_velocity>0&&vertical_velocity<-1000){
     cout<<"Illegal Input!"<<endl;
     continue;
   }  
  else{
    object.setvx(horizontal_velocity);
    object.setvy(vertical_velocity);
  }
  timeOfCollision=0;
  object.setx(0);
  object.sety(400);
  object.setomega(0);  
  rx.clear();
  ry.clear();
  }
  glFlush();
  object.update(0.1);
  glClear(GL_COLOR_BUFFER_BIT);  
}

void idle(){
  Sleep(100); 
  if(timeOfCollision<=3&&enabled){ 
  glutPostRedisplay();
  }  
}  
void ProcessMouse(int buttton,int state,int x,int y){
  object.setNewOrientation(x-object.getx(),wh-y-object.gety());
  object.setNewVelocity(object.getTheta());  
} 
void key(unsigned char k,int x,int y){
  if(k=='p'||k=='P')enabled=(1-enabled);
} 
int main(int argc, char* argv[]){
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
  glutInitWindowPosition(800,142);
  glutInitWindowSize(ww,wh);
  glutCreateWindow("Three-Dimensional Object Representations");
  glutDisplayFunc(display1);
  init1();
 // glutMouseFunc(ProcessMouse);
  glutKeyboardFunc(key);
  glutIdleFunc(idle);
  glutMainLoop();
  return 0;
} 
 
