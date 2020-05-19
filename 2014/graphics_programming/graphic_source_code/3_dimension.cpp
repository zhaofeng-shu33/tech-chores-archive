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
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glEnable(GL_DEPTH_TEST);
  glMatrixMode(GL_PROJECTION);
  glOrtho(-2,2,-2,2,-10,10);
}

/*void reshape(int newWidth,int newHeight){
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0,(GLdouble)newWidth,0,(GLdouble)newHeight,-100,100);
  glClear(GL_COLOR_BUFFER_BIT);  
 // gluOrtho2D(0,winWidth,0,winHeight);
}*/
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

void triangle(double a[],double b[],double c[]){
  glVertex3dv(a);
  glVertex3dv(b);
  glVertex3dv(c);
}  

void tetrahedron(double a[],double b[],double c[],double d[]){
  glColor3f(1,1,1);
  triangle(a,b,c);
  glColor3f(0,1,0);
  triangle(a,b,d);
  glColor3f(0,0,1);
  triangle(a,c,d);
  glColor3f(1,1,0);
  triangle(b,c,d);
}  
void divide_tetrahedron(double a[],double b[],double c[],double d[],int n){
   double ab[3],bc[3],cd[3],ac[3],ad[3],bd[3];
   if(n>0){
     for(int i=0;i<3;i++) ab[i]=(a[i]+b[i])/2;
     for(int i=0;i<3;i++) bc[i]=(b[i]+c[i])/2;
     for(int i=0;i<3;i++) cd[i]=(c[i]+d[i])/2;
     for(int i=0;i<3;i++) ac[i]=(a[i]+c[i])/2;
     for(int i=0;i<3;i++) ad[i]=(a[i]+d[i])/2;
     for(int i=0;i<3;i++) bd[i]=(b[i]+d[i])/2;
     divide_tetrahedron(a,ab,ac,ad,n-1);
     divide_tetrahedron(ab,b,bc,bd,n-1);
     divide_tetrahedron(ad,bd,cd,d,n-1);
     divide_tetrahedron(ac,bc,c,cd,n-1);
   }
   else tetrahedron(a,b,c,d);  
}    
void SierpinskiGasket2(int n){ //three dimension
  double a[3]={0,0,1},b[3]={0,0.9428,-0.3333},c[3]={-0.8165,-0.4714,-0.3333},d[3]={0.8165,-0.4714,-0.3333};
  glBegin(GL_TRIANGLES);
    divide_tetrahedron(a,b,c,d,n);
  glEnd();
}  
void display(void){
  //glClear(GL_COLOR_BUFFER_BIT);
   cout<<"Enter the division time:\n";
   //int n;
   //cin>>n;
  int n=3;
  SierpinskiGasket2(n);
  glFlush();  
}   
        
int main(int argc, char* argv[])
{ 
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB|GLUT_DEPTH);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(winWidth,winHeight);
  glutCreateWindow("Gasket");
  init();
  glutDisplayFunc(display);
//  glutReshapeFunc(reshape);
  
  glutMainLoop();  
  
  return 0;
} 
   