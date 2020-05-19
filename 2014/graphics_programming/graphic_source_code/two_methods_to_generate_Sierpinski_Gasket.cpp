#include<iostream>
#include<GL/glu.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<ctime>

double Pi=3.14159;
//const int n=51000;
using namespace std;
GLsizei winWidth=400,winHeight=400;
struct screenPt{
   GLdouble x;
   GLdouble y;
};
void init(void){
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0,winWidth,0,winHeight);
}

void reshape(int newWidth,int newHeight){
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0,(GLdouble)newWidth,0,(GLdouble)newHeight);
  glClear(GL_COLOR_BUFFER_BIT);  
 // gluOrtho2D(0,winWidth,0,winHeight);
}
/*void SierpinskiGasket1(int x0,int y0){
  screenPt p[3]={{100,100},{300,100},{200,300}};
  glBegin(GL_LINE_LOOP);
     glVertex2d(p[0].x,p[0].y);
     glVertex2d(p[1].x,p[1].y);
     glVertex2d(p[2].x,p[2].y);
  glEnd();     //draw a triangle;
  screenPt pt[n+1];
  pt[0].x=x0;
  pt[0].y=y0;
  srand(time(0));
  for(int i=0;i<n;i++){
      int r=rand()%3;
      pt[i+1].x=(pt[i].x+p[r].x)*1.0/2;
      pt[i+1].y=(pt[i].y+p[r].y)*1.0/2;
  }
  glBegin(GL_POINTS);
    for(int i=0;i<=n;i++){
        glVertex2d(pt[i].x,pt[i].y);
        //glRasterPos2d(pt[i].x,pt[i].y);
        //glutBitmapCharacter(GLUT_BITMAP_9_BY_15,char(i+48));
        //cout<<pt[i].x<<' '<<pt[i].y<<endl;
    }  
  glEnd();   
} */ 

void triangle(screenPt a,screenPt b,screenPt c){
  glVertex2d(a.x,a.y);
  glVertex2d(b.x,b.y);
  glVertex2d(c.x,c.y);
}  
void divide_triangle(screenPt a,screenPt b,screenPt c,int n){
    screenPt ab,ac,bc;
    if(n>0){
      ab.x=(a.x+b.x)*1.0/2;
      ac.x=(a.x+c.x)*1.0/2;
      bc.x=(b.x+c.x)*1.0/2;
      ab.y=(a.y+b.y)*1.0/2;
      ac.y=(a.y+c.y)*1.0/2;
      bc.y=(b.y+c.y)*1.0/2;
      divide_triangle(a,ab,ac,n-1);
      divide_triangle(ab,b,bc,n-1);
      divide_triangle(ac,bc,c,n-1);
    }
    else triangle(a,b,c);    
}  
void SierpinskiGasket2(int n){
  screenPt p[3]={{100,100},{300,100},{200,300}};
  glBegin(GL_TRIANGLES);
    divide_triangle(p[0],p[1],p[2],n);
  glEnd();
}  
void display(void){
  //glClear(GL_COLOR_BUFFER_BIT);
   cout<<"Enter the division time:\n";
   int n;
   cin>>n;
  SierpinskiGasket2(n);
  glFlush();  
}   
        
int main(int argc, char* argv[])
{ 
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(winWidth,winHeight);
  glutCreateWindow("draw curves");
  init();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();  
  
  return 0;
} 
   