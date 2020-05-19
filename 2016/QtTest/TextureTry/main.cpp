#include <GL/glu.h>
#include <glut.h>

#include <cmath>
GLsizei winWidth=400,winHeight=400;
int x,y,z;
GLfloat fVers[8][3];
GLubyte Image[64][64][4];
void CreateImage(void){
    for(int i=0;i<64;i++)
        for(int j=0;j<64;j++){
            int c=(((i& 0x8)==0)^((j& 0x8)==0))*255;
            Image[i][j][0]=GLubyte(c);
            Image[i][j][1]=GLubyte(c);
            Image[i][j][2]=GLubyte(c);
            Image[i][j][3]=GLubyte(255);
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


void display(void){
    //glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(x,y,z,0,0,0,0,0,1);
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1,0,0);
  glPushMatrix();
  glTranslatef(0,-40,60);
  glutSolidSphere(25,15,15);
  glPopMatrix();
  glColor3f(1,1,1);

  glBegin(GL_QUADS);
     glTexCoord2f(0,0);
     glVertex3f(0,0,0);
     glTexCoord2f(0,1);
     glVertex3f(0,100,0);
     glTexCoord2f(1,1);
     glVertex3f(100,100,0);
     glTexCoord2f(1,0);
     glVertex3f(100,0,0);
  glEnd();
  glFlush();
  glutSwapBuffers();
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
  glClearColor(0,0.3,0,1);
  CreateImage();
  glPixelStorei(GL_UNPACK_ALIGNMENT,1);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
  glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,64,64,0,GL_RGBA,GL_UNSIGNED_BYTE,Image);
  glEnable(GL_TEXTURE_2D);
  glutMainLoop();
  return 0;
  }



