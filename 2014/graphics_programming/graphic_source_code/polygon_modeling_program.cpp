#define MAX_POLYGONS 8
#define MAX_VERTICES 10
#include<GL/glu.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<GL/glut.h>
typedef struct polygon{
  int color;
  bool used;
  int xmin,xmax,ymin,ymax;
  int xc,yc;
  int nvertices;
  int x[MAX_VERTICES];
  int y[MAX_VERTICES];
}polygon;
polygon polygons[MAX_POLYGONS];  
bool picking=false,moving=false;
int in_polygon=-1;
int present_color=0;

GLsizei ww=500,wh=500;
using namespace std;
void init(){
  glClearColor(0.5,0.5,0.5,1);
  for(int i=0;i<MAX_POLYGONS;i++)
     polygons[i].used=false;
}
void reshape(int w,int h){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,(GLdouble)w,0,(GLdouble)h);
    glViewport(0,0,w,h);
    ww=w;
    wh=h;
} 
void sub_menu(int index){
  switch(index){
     case 1:
     cout<<"Try to delete a polygon\n";
     picking=true;
     moving=false;
     break;
  }  
}  
void main_menu(int index){
  int i;
  switch(index){
    case 1:
        moving=false;
    for(i=0;i<MAX_POLYGONS;i++)
        if(polygons[i].used==false)
           break;
    if(i==MAX_POLYGONS){
       cout<<"exceed the maximum limit of polygons\n";
    }
    else{
    polygons[i].color=present_color; 
    polygons[i].used=true;
    polygons[i].nvertices=0;
    in_polygon=i;
    picking=false;
    }  
    break;
    case 2:
     moving=false;
      if(in_polygon>=0){
         polygons[in_polygon].xmax=polygons[in_polygon].xmin=polygons[in_polygon].x[0];
         polygons[in_polygon].ymax=polygons[in_polygon].ymin=polygons[in_polygon].y[0];
         polygons[in_polygon].xc=polygons[in_polygon].x[0];
         polygons[in_polygon].yc=polygons[in_polygon].y[0];
         for(i=1;i<polygons[in_polygon].nvertices;i++){
             if(polygons[in_polygon].x[i]<polygons[in_polygon].xmin)
                polygons[in_polygon].xmin=polygons[in_polygon].x[i];
             else if(polygons[in_polygon].x[i]>polygons[in_polygon].xmax)
                polygons[in_polygon].xmax=polygons[in_polygon].x[i];
             if(polygons[in_polygon].y[i]<polygons[in_polygon].ymin)
                polygons[in_polygon].ymin=polygons[in_polygon].y[i];
             else if(polygons[in_polygon].y[i]>polygons[in_polygon].ymax)
                polygons[in_polygon].ymax=polygons[in_polygon].y[i];
             polygons[in_polygon].xc+=polygons[in_polygon].x[i];
             polygons[in_polygon].yc+=polygons[in_polygon].y[i];
         }
         polygons[in_polygon].xc/=polygons[in_polygon].nvertices;
         polygons[in_polygon].yc/=polygons[in_polygon].nvertices;              
    }
     in_polygon=-1;
     glutPostRedisplay();
    break;
  
   case 3:
   moving=true;
   break;
   case 5:exit(0);break;
 }        
}
int pick_polygon(int x,int y){
  for(int i=0;i<MAX_POLYGONS;i++){
      if(polygons[i].used)
         if((x>=polygons[i].xmin)&&(x<=polygons[i].xmax)&&(y>=polygons[i].ymin)&&(y<polygons[i].ymax)){
           in_polygon=i;
           return i;
         }
  }  
  return -1;  
}
void motion(int x,int y){
 // cout<<"Try to move a chosen polygon.";
  int dx,dy;
  if(moving){
    y=wh-y;
    int j=pick_polygon(x,y);
    if(j<0){
      cout<<"not in a polygon and the moving try fails\n";
      return;
    }
    dx=x-polygons[j].xc;
    dy=y-polygons[j].yc;
    for(int i=0;i<polygons[j].nvertices;i++){
        polygons[j].x[i]+=dx;
        polygons[j].y[i]+=dy;
    }
    polygons[j].xc=x;
    polygons[j].yc=y;
    polygons[j].xmin+=dx;
    polygons[j].xmax+=dx;
    polygons[j].ymin+=dy;  
    polygons[j].ymax+=dy;
    cout<<"Try to move a chosen polygon\n";
    glutPostRedisplay();
  }    
}
void mouse(int btn,int state,int x,int y){
  y=wh-y;
  if(btn==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)
     cout<<"curent coordinate: "<<x<<' '<<y<<endl;
  if(btn==GLUT_LEFT_BUTTON&&state==GLUT_DOWN&&!picking&&!moving){
    
    moving=false;
    if(in_polygon>=0){
       cout<<"Try to add one vertertice to polygon\n";
       if(polygons[in_polygon].nvertices==MAX_VERTICES)
          cout<<"Exceed the maximum limit of polygons\n";
       else{
         int i=polygons[in_polygon].nvertices;
         polygons[in_polygon].x[i]=x;
         polygons[in_polygon].y[i]=y;
         polygons[in_polygon].nvertices++;
       }
   }
  }
  if(btn==GLUT_LEFT_BUTTON&&state==GLUT_DOWN&&picking&&!moving){
    cout<<"Try to delete a polygon\n";
    picking=false;
    moving=false;
    int j=pick_polygon(x,y);
    if(j>=0){
      polygons[j].used=false;
      in_polygon=-1;
      glutPostRedisplay();
    }
    else
      cout<<"Not in a polygon and the deleting try fails\n";
  }
}        
         
void display(void){
  glClear(GL_COLOR_BUFFER_BIT);
  for(int i=0;i<MAX_POLYGONS;i++)
      if(polygons[i].used){
         glBegin(GL_POLYGON);
         for(int j=0;j<polygons[i].nvertices;j++)
             glVertex2i(polygons[i].x[j],polygons[i].y[j]);
         glEnd();
      }  
  glFlush();
}  
int main(int argc, char* argv[]){
  glutInit(&argc,argv);
  glutInitWindowPosition(50,100);
  glutInitWindowSize(500,500);
  glutCreateWindow("One");
  glutDisplayFunc(display);
  init();
  
  int s_menu=glutCreateMenu(sub_menu);
  glutAddMenuEntry("delete polygon",1);
  
  glutCreateMenu(main_menu);
  glutAddMenuEntry("new polygon",1);
  glutAddMenuEntry("end polygon",2);
  glutAddMenuEntry("move polygon",3);
  glutAddMenuEntry("nothing",4);
  glutAddMenuEntry("quit",5);
  glutAddSubMenu("Delete",s_menu);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
  
  glutReshapeFunc(reshape);
  glutMouseFunc(mouse);
  glutMotionFunc(motion);
  glutMainLoop();
  return 0;
}  