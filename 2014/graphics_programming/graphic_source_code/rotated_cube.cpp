#include<iostream>
#include<GL/glu.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
const double Pi=3.14159;
using namespace std;
void display(void){
  glClear(GL_COLOR_BUFFER_BIT);
  //glColor4f(0,0,1,1);           
  glRotatef(60,1,1,1);          
  glutWireCube(0.99); 
  glFlush();


}  
int main(int argc, char* arv[]){
  glutInit(&argc,arv);
  glutInitWindowPosition(300,300);
  glutInitWindowSize(200,200);
  glutCreateWindow("my second example");
  glutDisplayFunc(display);
  glutMainLoop();


}  