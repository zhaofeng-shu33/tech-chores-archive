#define MAX_POLYGONS 8
#define MAX_VERTICES 10
#include<GL/glu.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<GL/glut.h>
using namespace std;
GLsizei ww=500,wh=500;
int nCtrlPts=4,nBezCurvePts=1000;
struct wcPt2D{
  double x,y;
};  
void init(){
  //glClearColor(0.5,0.5,0.5,1);
  glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(5,5,5,0,0,0,0,0,1);
 
    glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    glOrtho(-3,3,-3,3,-30,30);
   // glOrtho(-ww/2,-wh/2,ww/2,wh/2,-300,300);
}
void reshape(int w,int h){
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    //gluLookAt(1,1,1,0,0,0,0,0,1);
    glOrtho(-w/2,-h/2,w/2,h/2,-300,300);
    glMatrixMode(GL_MODELVIEW);
} 
void display1(void){
  glClear(GL_COLOR_BUFFER_BIT);
  wcPt2D ctrlPts[4]={{-40,-40},{-10,200},{10,-200},{40,40}};
  glPointSize(4);
  int* C=new int[nCtrlPts];
  int n=nCtrlPts-1;
  for(int i=0;i<=n;i++){
     C[i]=1;
     for(int j=n;j>=n-i+1;j--)
         C[i]*=j;
     for(int j=1;j<=i;j++)
         C[i]/=j;
  }
  double u,bezBlendFunc;;
  for(int i=0;i<=nBezCurvePts;i++){
      u=i*1.0/nBezCurvePts;
      wcPt2D bezCurvePt={0,0};
      for(int j=0;j<nCtrlPts;j++){
          bezBlendFunc=C[j]*pow(u,j)*pow(1-u,n-j);
          bezCurvePt.x+=ctrlPts[j].x*bezBlendFunc;
          bezCurvePt.y+=ctrlPts[j].y*bezBlendFunc;
      }
      glBegin(GL_POINTS);
        glVertex2d(bezCurvePt.x,bezCurvePt.y);
      glEnd();
     // cout<<bezCurvePt.x<<' '<<bezCurvePt.y<<endl;
  }
  delete [] C;    
  glPointSize(10);
  glColor3f(1,0,0);
     glBegin(GL_POINTS);
     for(int i=0;i<4;i++)
     glVertex2d(ctrlPts[i].x,ctrlPts[i].y);
     glEnd();                 
  glFlush();
}
void display2(void){
  glBegin(GL_LINES);
    glVertex3i(200,0,0);
    glVertex3i(-200,0,0);
    glVertex3i(0,200,0);
    glVertex3i(0,-200,0);
    glVertex3i(0,0,200);
    glVertex3i(0,0,0); 
  glEnd();
  
  glRasterPos3i(1,0,0);
  glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'x');
  glRasterPos3i(0,1,0);
  glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'y');
  glRasterPos3i(0,0,1);
  glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'z');
  


 /* double ctrlPts[4][3]={{-0.4,-0.4,0},{-0.1,2,0},{0.1,-2,0},{0.4,0.4,0}};
  glMap1d(GL_MAP1_VERTEX_3,0,1,3,4,*ctrlPts);
  glEnable(GL_MAP1_VERTEX_3);
  glBegin(GL_LINE_STRIP);
    for(int i=0;i<=50;i++)
        glEvalCoord1d(i*1.0/50);
  glEnd();  
 */
  double ctrlPts[4][4][3]={{{-1.5,-1.5,4},{-0.5,-1.5,2},{-0.5,-1.5,-1},{1.5,-1.5,2}},
  {{-1.5,-0.5,1},{-0.5,-0.5,2},{0.5,-0.5,0},{1.5,-0.5,-1}},
  {{-1.5,0.5,4},{-0.5,0.5,0},{0.5,0.5,3},{1.5,0.5,4}},
  {{-1.5,1.5,-2},{-0.5,1.5,-2},{0.5,1.5,0},{1.5,1.5,-1}}}; 
  glPointSize(10);
  glColor3f(0.5,0.5,0.5);
  glBegin(GL_POINTS);
  for(int i=0;i<4;i++)
      for(int j=0;j<4;j++)
         glVertex3dv(ctrlPts[i][j]);
  glEnd();                 
  glMap2d(GL_MAP2_VERTEX_3,0,1,3,4,0,1,12,4,&ctrlPts[0][0][0]);
  glEnable(GL_MAP2_VERTEX_3);
  for(int i=0;i<=8;i++){
    glBegin(GL_LINE_STRIP);
    for(int j=0;j<=40;j++)
        glEvalCoord2d(j*1.0/40,i*1.0/8);
    glEnd();
    glBegin(GL_LINE_STRIP);
    for(int j=0;j<=40;j++)
        glEvalCoord2d(i*1.0/8,j*1.0/40);
    glEnd();
  }  
 glFlush();      
}    
int main(int argc, char* argv[]){
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowPosition(50,100);
  glutInitWindowSize(ww,wh);
  glutCreateWindow("One");
  glutDisplayFunc(display2);
  init();
  
 // glutReshapeFunc(reshape);
  glutMainLoop();
  return 0;
}  