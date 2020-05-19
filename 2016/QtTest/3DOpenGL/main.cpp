#include <GL/glu.h>
#include <glut.h>
#include <windows.h>
#include <cmath>
GLsizei winWidth=400,winHeight=400;
int x,y,z;
GLfloat fVers[8][3];
void init(void){
 //glViewport(0,0,winWidth,winHeight);
  glMatrixMode(GL_PROJECTION);
  glOrtho(-winWidth/2,winWidth/2,-winHeight/2,winHeight/2,-100,100);
  glMatrixMode(GL_MODELVIEW);
  gluLookAt(70,0,0,0,0,0,0,0,1);

}
void CalculateVertices(){
    fVers[0][0]=fVers[0][1]=0;
    fVers[0][2]=75;
    for(int i=1;i<8;i++){
        fVers[i][0]=50*cos(3.14*i/3);
        fVers[i][1]=50*sin(3.14*i/3);
        fVers[i][2]=0;
    }
}

void reshape(int newWidth,int newHeight){
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  winWidth=newWidth,winHeight=newHeight;

  glOrtho(-winWidth/2,winWidth/2,-winHeight/2,winHeight/2,-200,200);
  //glViewport(0,0,winWidth,winHeight);
  glMatrixMode(GL_MODELVIEW);
  glClear(GL_COLOR_BUFFER_BIT);
}
void CalculateNormal(GLfloat vertices[3][3],GLfloat* normal){
    GLfloat v1[3],v2[3];
    v1[0]=vertices[0][0]-vertices[1][0];
    v1[1]=vertices[0][1]-vertices[1][1];
    v1[2]=vertices[0][2]-vertices[1][2];
    v2[0]=vertices[1][0]-vertices[2][0];
    v2[1]=vertices[1][1]-vertices[2][1];
    v2[2]=vertices[1][2]-vertices[2][2];
    normal[0]=v1[1]*v2[2]-v1[2]*v2[1];
    normal[1]=v1[0]*v2[2]-v1[2]*v2[0];
    normal[2]=v1[1]*v2[0]-v1[0]*v2[1];

}

void display(void){
    //glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(x,y,z,0,0,0,0,0,1);
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1,0,0);
  glPushMatrix();
  glTranslatef(0,40,-40);
  glutSolidSphere(25,15,15);
  glPopMatrix();
  //glutSolidCube(50);
  glColor3f(1,1,1);
  GLfloat ver[3][3],normal[3];
  glBegin(GL_TRIANGLES);
  for(int i=1;i<7;i++){
      for(int j=0;j<3;j++){
          ver[0][j]=fVers[0][j];
          ver[1][j]=fVers[i][j];
          ver[2][j]=fVers[i+1][j];
      }
      CalculateNormal(ver,normal);
      glNormal3fv(normal);
     glVertex3f(fVers[0][0],fVers[0][1],fVers[0][2]);
     glVertex3f(fVers[i][0],fVers[i][1],fVers[i][2]);
     glVertex3f(fVers[i+1][0],fVers[i+1][1],fVers[i+1][2]);
  }//draws the side surface
  glEnd();

  glBegin(GL_POLYGON);
    glNormal3f(0,0,1);
    for(int i=1;i<7;i++)
     glVertex3f(fVers[i][0],fVers[i][1],0);//draws the bottom surface
  glEnd();

  glFlush();
  glutSwapBuffers();
}
void onKeyboard(int key,int,int){
    switch(key){
    case GLUT_KEY_LEFT:
        x-=2;break;
    case GLUT_KEY_RIGHT:
        x+=2;break;
    case GLUT_KEY_UP:
        y+=2;break;
    case GLUT_KEY_DOWN:
        y-=2;break;
    case GLUT_KEY_PAGE_DOWN:
        z-=2;break;
    case GLUT_KEY_PAGE_UP:
        z+=2;break;
    default:break;
    }
    glutPostRedisplay();
}
void Keyboard(unsigned char ch,int,int){
    if(ch=='d')
       glDisable(GL_LIGHTING);
    else if(ch=='e')
       glEnable(GL_LIGHTING);
    glutPostRedisplay();
}

int main(int argc, char* argv[])
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB|GLUT_DEPTH);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(winWidth,winHeight);

 // init();
  glutCreateWindow("window1");
  glutDisplayFunc(display);
  x=60;y=60;z=60;
  glutReshapeFunc(reshape);
  glutSpecialFunc(onKeyboard);
  glutKeyboardFunc(Keyboard);
  glClearColor(0,0.3,0,1);
  glEnable(GL_LIGHTING);
  GLfloat diffuseLight[]={0.9,0.9,0.9,1};
  GLfloat ambientLight[]={0.2,0.2,0.2,1};
  GLfloat lightPos[]={50,80,50,1};
  glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuseLight);
  glLightfv(GL_LIGHT0,GL_AMBIENT,ambientLight);
  glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
  glEnable(GL_LIGHT0);
  glEnable(GL_NORMALIZE);
  glEnable(GL_COLOR_MATERIAL);
  glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE);
  CalculateVertices();
  glutMainLoop();
  return 0;
  }


