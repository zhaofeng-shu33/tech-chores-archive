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
const int n=4;
struct wcPt2D{
  double x,y;
};  
void init(void){
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(-winWidth/2,winWidth/2,-winHeight/2,winHeight/2);
}

void reshape(int newWidth,int newHeight){
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0,(GLdouble)newWidth,0,(GLdouble)newHeight);
  glClear(GL_COLOR_BUFFER_BIT);  
 
}
typedef enum{Left=0,Right,Bottom,Top} Boundary;
GLubyte winLeftBitCode=0x01,winRightBitCode=0x02,winBottomBitCode=0x04,winTopBitCode=0x08;
wcPt2D winMin={-120,-100}, winMax={120,100};

GLubyte encode(wcPt2D pt){
  GLubyte code=0x00;
  if(pt.x<winMin.x)
     code=code|winLeftBitCode;
  if(pt.x>winMax.x)
     code=code|winRightBitCode;
  if(pt.y<winMin.y)
     code=code|winBottomBitCode;
  if(pt.y>winMax.y)
     code=code|winTopBitCode;
  return code;
}  
wcPt2D pOut[10];//the length can be adjusted according to the original number of sides of the polygon.
int cnt=0;
    
void lineClip(wcPt2D p1,wcPt2D p2,int winEdge){ //change to triangle region
  GLubyte code1,code2;
  
  double m=0;
  code1=encode(p1);
  code2=encode(p2);  
 //cout<<pIn[0].x<<' '<<pIn[0].y<<endl;
 //cout<<pIn[1].x<<' '<<pIn[1].y<<endl;
  
     if(p2.x!=p1.x)
        m=(p2.y-p1.y)*1.0/(p2.x-p1.x);
            switch(winEdge){
                 case Left:
                   if(code1&winLeftBitCode){
                      if(!(code2&winLeftBitCode)){//p1 lies on the left side of the clipping window
                      pOut[cnt].y=p1.y+(winMin.x-p1.x)*m;
                      pOut[cnt++].x=winMin.x;
                      pOut[cnt++]=p2;  
                      }
                    }
                    
                   else {
                        if(code2&winLeftBitCode){
                           pOut[cnt].y=p1.y+(winMin.x-p1.x)*m;
                           pOut[cnt++].x=winMin.x;
                        }
                        else
                           pOut[cnt++]=p2;
                   }  
                 break;
                 case Right:
                   if(code1&winRightBitCode){
                      if(!(code2&winRightBitCode)){
                      pOut[cnt].y=p1.y+(winMax.x-p1.x)*m;
                      pOut[cnt++].x=winMax.x;
                      pOut[cnt++]=p2;  
                      }
                    }
                    
                   else {
                        if(code2&winRightBitCode){
                           pOut[cnt].y=p1.y+(winMax.x-p1.x)*m;
                           pOut[cnt++].x=winMax.x;
                        }
                        else
                           pOut[cnt++]=p2;
                   }  
                 break;
                 case Bottom:
                   if(code1&winBottomBitCode){
                      if(!(code2&winBottomBitCode)){
                         if(p1.x!=p2.x)  
                            pOut[cnt].x=(winMin.y-p1.y)*1.0/m+p1.x;
                         pOut[cnt++].y=winMin.y;
                         pOut[cnt++]=p2;  
                      }
                    }
                    
                   else {
                        if(code2&winBottomBitCode){
                           pOut[cnt].x=(winMin.y-p1.y)*1.0/m+p1.x;
                           pOut[cnt++].y=winMin.y;
                        }
                        else
                           pOut[cnt++]=p2;
                   }  
                 break;
                case Top:
                   if(code1&winTopBitCode){
                      if(!(code2&winTopBitCode)){
                         if(p1.x!=p2.x)  
                            pOut[cnt].x=(winMax.y-p1.y)*1.0/m+p1.x;
                         pOut[cnt++].y=winMax.y;
                         pOut[cnt++]=p2;  
                      }
                    }
                    
                   else {
                        if(code2&winTopBitCode){
                           pOut[cnt].x=(winMax.y-p1.y)*1.0/m+p1.x;
                           pOut[cnt++].y=winMax.y;
                        }
                        else
                           pOut[cnt++]=p2;
                   }  
                 break;
         }  
      
}  
void polygonClip(wcPt2D pIn[],int n){
  cnt=n;
  for(int j=0;j<4;j++){
    int num=cnt;cnt=0;
    for(int i=0;i<num;i++){
         if(i!=num-1)
            lineClip(pIn[i],pIn[i+1],j);
        else
            lineClip(pIn[num-1],pIn[0],j);
    }
    for(int i=0;i<cnt;i++)
       pIn[i]=pOut[i]; 
  }
 cout<<cnt<<endl;
 cout<<pIn[0].x<<' '<<pIn[0].y<<endl;
 cout<<pIn[1].x<<' '<<pIn[1].y<<endl;
 cout<<pIn[2].x<<' '<<pIn[2].y<<endl;
 cout<<pIn[3].x<<' '<<pIn[3].y<<endl;
   
  glBegin(GL_POLYGON);
    for(int i=0;i<cnt;i++)
        glVertex2d(pIn[i].x,pIn[i].y);
  glEnd();  
}  
void display(void){
  //glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glColor3f(1,1,0);
  
  glBegin(GL_LINE_LOOP);
    glVertex2i(-120,-100);
    glVertex2i(120,-100);
    glVertex2i(120,100);
    glVertex2i(-120,100);
  
  glEnd();
  
  
  wcPt2D pIn[10]={{-100,-130},{170,-40},{-140,80}};
  polygonClip(pIn,3);
  /*glBegin(GL_TRIANGLES);
    glVertex2i(-100,-130);
    glVertex2i(170,-40);
    glVertex2i(-140,80);
  glEnd();
  */
  glFlush();  
}   
        
int main(int argc, char* argv[])
{ 
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(winWidth,winHeight);
  glutCreateWindow("Gasket");
  init();
  glutDisplayFunc(display);
//  glutReshapeFunc(reshape);
  
  glutMainLoop();  
  
  return 0;
} 
   