#include<iostream>
#include<GL/glu.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<ctime>
using namespace std;
double Pi=3.14159;
GLsizei winWidth=400,winHeight=400;

typedef double wcPt3D[3];
typedef double Matrix3x3[3][3];
Matrix3x3 rotationMatrix;
void init(void){
 // gluLookAt(101,131,-1,100,130,0,0,0,1);
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glOrtho(-winWidth/2,winWidth/2,-winHeight/2,winHeight/2,-800,800);
}
void reshape(int newWidth,int newHeight){
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-(GLdouble)newWidth/2,(GLdouble)newWidth/2,-(GLdouble)newHeight/2,(GLdouble)newHeight/2,-800,800);
  winWidth=newWidth,winHeight=newHeight;
  glClear(GL_COLOR_BUFFER_BIT);  
}
void matrix3x3SetIdentity(Matrix3x3 mat){
  for(int row=0;row<3;row++)
     for(int col=0;col<3;col++)
         mat[row][col]=(row==col);
}  
void rotate3D(wcPt3D p,double angle){
  rotationMatrix[0][0]=p[0]*p[0]*(1-cos(angle))+cos(angle);
  rotationMatrix[1][0]=p[1]*p[0]*(1-cos(angle))+p[2]*sin(angle);
  rotationMatrix[2][0]=p[2]*p[0]*(1-cos(angle))-p[1]*sin(angle); 
  rotationMatrix[0][1]=p[0]*p[1]*(1-cos(angle))-p[2]*sin(angle);
  rotationMatrix[1][1]=p[1]*p[1]*(1-cos(angle))+cos(angle);
  rotationMatrix[2][1]=p[2]*p[1]*(1-cos(angle))+p[0]*sin(angle);         
  rotationMatrix[0][2]=p[0]*p[2]*(1-cos(angle))+p[1]*sin(angle);
  rotationMatrix[1][2]=p[1]*p[2]*(1-cos(angle))-p[0]*sin(angle);
  rotationMatrix[2][2]=p[2]*p[2]*(1-cos(angle))+cos(angle);  
       
}
wcPt3D myTriangle[3]={{0,0,0},{100,30,0},{100,130,0}};
  int n=3;
void rotatePolygon(wcPt3D verts[],int n){
  glColor3f(0,0,0);
  glBegin(GL_LINE_LOOP);
    for(int i=0;i<n;i++)
       glVertex3dv(myTriangle[i]);
  glEnd();
  glColor3f(1,1,1);
  
  
  wcPt3D vertsRot[n];
  for(int i=0;i<n;i++)
      for(int j=0;j<3;j++)
          vertsRot[i][j]=verts[i][0]*rotationMatrix[j][0]+verts[i][1]*rotationMatrix[j][1]+verts[i][2]*rotationMatrix[j][2];
  glBegin(GL_LINE_LOOP);
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
        verts[i][j]=vertsRot[i][j];
        }  
       glVertex3dv(vertsRot[i]);
    }  
  glEnd();
}
    
void display1(void){
  glClear(GL_COLOR_BUFFER_BIT);
  glRasterPos3i(0,0,70);
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'A');
  glRasterPos3i(-100,-100,0);
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'B');
  glRasterPos3i(100,-100,0);
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'C');
  glRasterPos3d(0,200/sqrt(3.0),0);
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'D');
  glRasterPos3i(0,0,100);
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'z');
  glRasterPos3i(100,0,0);
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'x');
  glRasterPos3i(0,100,0);
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'y');



  glBegin(GL_LINES);
    glVertex3i(-200,0,0);
    glVertex3i(200,0,0);
    glVertex3i(0,-200,0);  
    glVertex3i(0,200,0);
    glVertex3i(0,0,-200);
    glVertex3i(0,0,200);  
  glEnd();      
  wcPt3D point[4]={{-100,-100,0},{100,-100,0},{0,200/sqrt(3.0),0},{0,0,70}};

 // glRotatef(30,1,1,0);
  glBegin(GL_LINES);
    for(int i=0;i<3;i++){
       glVertex3dv(point[i]);
       glVertex3dv(point[3]);
    }  
  glEnd();
  
  glBegin(GL_LINE_LOOP);
     for(int i=0;i<3;i++)
        glVertex3dv(point[i]);
  glEnd();

  glFlush();
}
void mykey(unsigned char key,int x,int y){
  if(key=='r'){
     wcPt3D p={0,0,1};
     rotate3D(p,Pi/6);
     rotatePolygon(myTriangle,n);
  }  
  if(key=='t'){ 
     wcPt3D p={0,0,1};
     rotate3D(p,-Pi/6);
     rotatePolygon(myTriangle,n);
  }  
        
  glFlush();
    
}
int main(int argc, char* argv[])
{ 
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB|GLUT_DEPTH);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(winWidth,winHeight);
  
  glutCreateWindow("window1");
  glutDisplayFunc(display1);
  init();
  glutReshapeFunc(reshape); 
  glutKeyboardFunc(mykey);
 
  glutMainLoop();  
  
  return 0;
} 
   