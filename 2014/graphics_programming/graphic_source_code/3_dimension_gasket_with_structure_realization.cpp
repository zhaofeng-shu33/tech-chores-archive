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
   GLdouble cor[3];
};
screenPt mid(screenPt& p1,screenPt& p2){
  screenPt p;
  for(int i=0;i<3;i++)
      p.cor[i]=(p1.cor[i]+p2.cor[i])/2;
  return p;
}   
ostream& operator <<(ostream& out,screenPt& p){
   return out<<p.cor[0]<<' '<<p.cor[1]<<' '<<p.cor[2]; 
}  
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

void triangle(screenPt p1,screenPt p2,screenPt p3){
  glVertex3d(p1.cor[0],p1.cor[1],p1.cor[2]);
  glVertex3d(p2.cor[0],p2.cor[1],p2.cor[2]);
  glVertex3d(p3.cor[0],p3.cor[1],p3.cor[2]);
}  

void tetrahedron(screenPt pt[]){
  glColor3f(1,1,1);
  triangle(pt[0],pt[1],pt[2]);
  glColor3f(0,1,0);
  triangle(pt[0],pt[1],pt[3]);
  glColor3f(0,0,1);
  triangle(pt[0],pt[2],pt[3]);
  glColor3f(1,1,0);
  triangle(pt[1],pt[2],pt[3]);
}  
void divide_tetrahedron(screenPt pt[],int n){
   screenPt p[6];
   if(n>0){
     p[0]=mid(pt[0],pt[3]);
     p[1]=mid(pt[0],pt[1]);
     p[2]=mid(pt[0],pt[2]);
     p[3]=mid(pt[1],pt[2]);
     p[4]=mid(pt[1],pt[3]);
     p[5]=mid(pt[2],pt[3]);
     
     
     
     screenPt pq1[4]={pt[0],p[1],p[2],p[0]};
     divide_tetrahedron(pq1,n-1);
     screenPt pq2[4]={p[1],pt[1],p[3],p[4]};  
     divide_tetrahedron(pq2,n-1);
     screenPt pq3[4]={p[2],p[3],pt[2],p[5]};
     divide_tetrahedron(pq3,n-1);
     screenPt pq4[4]={p[0],p[4],p[5],pt[3]};
     divide_tetrahedron(pq4,n-1);
   }
   else tetrahedron(pt);  
}    
void SierpinskiGasket2(int n){ //three dimension
  screenPt pt[4]={{0,0,1},{0,0.9428,-0.3333},{-0.8165,-0.4714,-0.3333},{0.8165,-0.4714,-0.3333}};
  glBegin(GL_TRIANGLES);
    divide_tetrahedron(pt,n);
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
   