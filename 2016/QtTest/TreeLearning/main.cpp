#include<QCoreApplication>
#include <GL/glu.h>
#include <GL/glut.h>

#include "MinHeap.h"
void drawString(const char* str) {
    static int isFirstCall = 1;
    static GLuint lists;

    if( isFirstCall ) { // 如果是第一次调用，执行初始化
                        // 为每一个ASCII字符产生一个显示列表
        isFirstCall = 0;

        // 申请MAX_CHAR个连续的显示列表编号
        lists = glGenLists(128);

        // 把每个字符的绘制命令都装到对应的显示列表中
        wglUseFontBitmaps(wglGetCurrentDC(), 0, 128, lists);
    }
    // 调用每个字符对应的显示列表，绘制每个字符
    for(; *str!='\0'; ++str)
        glCallList(lists + *str);
}
void drawNumber(int n){
    QString str(n+48);
    drawString(str.toAscii());
}



GLsizei winWidth=400,winHeight=400;
void init(void){
  glViewport(0,0,winWidth,winHeight);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0,winWidth,0,winHeight);
}
void reshape(int newWidth,int newHeight){
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0,(GLdouble)newWidth,0,(GLdouble)newHeight);
  winWidth=newWidth,winHeight=newHeight;
  glViewport(0,0,winWidth,winHeight);
  glClear(GL_COLOR_BUFFER_BIT);
}

element a[5];
MinHeap<int> myTree;
void display(void){
  glClear(GL_COLOR_BUFFER_BIT);
 // glRecti(300,300,350,350);
  //BinTreeNode<int> myNode(5,tmp);
  //tmp=myNode.get_Point();
  glColor3f(1,1,1);
  for(int i=0;i<5;i++){
      int data;
      myTree.RemoveMin(data);
      cout<<data<<' '<<endl;
      glRasterPos2i(a[i].x,a[i].y);
      drawNumber(data);
  }
  glFlush();
}

int main(int argc, char* argv[])
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB|GLUT_DEPTH);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(winWidth,winHeight);

  init();
  glutCreateWindow("window1");
  for(int i=0;i<5;i++)a[i].num=6-i;//2~6
  a[0].x=200;a[0].y=350;
  a[1].x=160;a[1].y=330;
  a[2].x=240;a[2].y=330;
  a[3].x=140;a[3].y=300;
  a[4].x=180;a[4].y=300;

  cout<<"Please enter the data of the tree:"<<endl;
  //cin>>tmp;
  for(int i=0;i<5;i++){
    myTree.Insert(a[i].num);
  }
  cout<<endl;
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);

  glutReshapeFunc(reshape);
  glutMainLoop();
  return 0;
  }

