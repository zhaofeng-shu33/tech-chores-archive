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
const float LifeTimeSpan=2.0f;//second;
using namespace std;
                               // win the game, otherwise you lose the game.

struct screenPt{
   double x;
   double y;
};

void reshape(int newWidth,int newHeight){
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0,(GLdouble)newWidth,0,(GLdouble)newHeight);
  winWidth=newWidth,winHeight=newHeight;
  glViewport(0,0,winWidth,winHeight);
  glClear(GL_COLOR_BUFFER_BIT);  
}

class Particle{
  private: 
    float pos_x;
    float pos_y;
    float generatedTime;
    float angle;
    float angleIncrementSpeed;
  public:
    float get_pos_x(){return pos_x;}
    float get_pos_y(){return pos_y;}
    float get_angle(){return angle;}
    float get_existingTime(){return glutGet(GLUT_ELAPSED_TIME)/1000.0f-generatedTime;}
    Particle(float new_pos_x,float new_pos_y,float prescribedIncrementSpeed=0.0003f){
      pos_x=new_pos_x;pos_y=new_pos_y;
      generatedTime=glutGet(GLUT_ELAPSED_TIME)/1000.0f;
      angle=atan2(new_pos_y-200,new_pos_x-200);
      angleIncrementSpeed=prescribedIncrementSpeed;
    }
    void set_pos_x(float new_pos_x){pos_x=new_pos_x;}
    void set_pos_y(float new_pos_y){pos_y=new_pos_y;}
    void set_angle(float new_angle){angle=new_angle;}
    void update(){
      angle+=angleIncrementSpeed;
      pos_x=200+100*cos(angle);
      pos_y=200+100*sin(angle);
      draw();
    }  
    void draw(){
      glBegin(GL_POINTS);
      glVertex2f(pos_x,pos_y);
      glEnd();
    }  
};

class ParticleManager{
  private:
     int numLimitOfParticle;
     deque<Particle*> ParticleList;
  public:
     ParticleManager(int prescribedNumLimitOfParticle){numLimitOfParticle=prescribedNumLimitOfParticle;}
     ParticleManager(){numLimitOfParticle=1;}
     bool checkFull(){return (numLimitOfParticle<=ParticleList.size());}
     void GenerateNewParticle(float new_pos_x=300.0f,float new_pos_y=200.0f) {
       Particle* newParticle=new Particle(new_pos_x,new_pos_y);
       ParticleList.push_front(newParticle);
     }
     void RemoveOverLifeTimeParticle() {
       if(ParticleList.size()>0)
            ParticleList.pop_back();
     }
     bool checkHoldingOverLifeTimeParticle(){
       if(ParticleList.size()>0)
       return ParticleList.back()->get_existingTime()>LifeTimeSpan;
       else
       return false;
     }
     void updateParticlePosition(){
       if(ParticleList.size()>0){ 
       for(deque<Particle*>::iterator myParticle=ParticleList.begin();myParticle!=ParticleList.end();myParticle++){
              //use iterator 'myParticle' to update the angle of every particle;
              (*myParticle)->update();
       }
       }    
     }  
};
ParticleManager* myParticleManager;


//Particle* myParticle;
void init(void){
  glViewport(0,0,winWidth,winHeight);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0,winWidth,0,winHeight);
  myParticleManager=new ParticleManager(2); 
  myParticleManager->GenerateNewParticle();
  //myParticle=new Particle(300,300,glutGet(GLUT_ELAPSED_TIME)/1000.0f);
}
 
void display(void){
  
 glClear(GL_COLOR_BUFFER_BIT);
 // glColor3f(0.0f,0.0f,0.0f);
 // myParticle.draw();
 // glColor3f(255.0f,255.0f,255.0f);
  if(myParticleManager->checkHoldingOverLifeTimeParticle()){
    myParticleManager->RemoveOverLifeTimeParticle(); 
  }  
  if(!myParticleManager->checkFull()){
       float phi=rand()*1.0f/1000.0f;
       myParticleManager->GenerateNewParticle(200+100*cos(phi),200+100*sin(phi));
       cout<<"Debug";
  } 
  myParticleManager->updateParticlePosition();   
  
  glPointSize(10.0);
  glBegin(GL_POINTS);
  glVertex2i(200,200);
  glEnd();
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
   
