#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QTextStream>
#include<QStringList>
#include<QTextCodec>
#include <ctime>
#include<GL/glu.h>
#include<GL/glu.h>
#include<glut.h>
#include<windows.h>
#include<QDebug>
#include <QTextStream>
QTextStream cout1(stdout);

Widget* currentInstance;
Widget::Widget(QWidget *parent,int total_weight) :
    QWidget(parent),total_weight(0),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    srand((unsigned)time(0));
    QFile nounData(":/NounSource.txt");
    nounData.open(QIODevice::ReadOnly);
    QTextStream out(&nounData);
    int tmp=1;
    while(!out.atEnd()){
    QString str=out.readLine(75);
    QStringList strList=str.split("\t");
    Nounlist.push_back(Noun(strList.first()," ",tmp,strList[1]));
    for(int i=2;i<strList.size();i++)
        Nounlist[tmp-1].set_example_sentence(strList[i]);
    this->set_total_weight(this->get_total_weight()+Nounlist[tmp-1].get_weight());
    tmp++;
    }
  //  ui->lineEdit->setFocus();

}

Widget::~Widget()
{
    delete ui;
}
int Widget::renew(){
    int n=generate_random_number();
    ui->textBrowser->append(QString("Das ist ___ %1.").arg(Nounlist[n-1].get_spell()));
    return n;
}

double Widget::distribution_function(int n){//n takes 1 ~ maximum length of Nounlist
    int sum=0;
    for(int t=1;t<=n;t++)
        sum+=Nounlist[t-1].get_weight();
    return sum*1.0/get_total_weight();
}
int Widget::generate_random_number(){  //generate random number from 1 to total_weight
   double tmp;
   for(int t=0;t<5;t++)
        tmp=(rand()%1000)*1.0/1000;//a random number generated from interval 0 to 1
   for(int t=1;t<get_total_weight();t++){
       if(tmp<distribution_function(1))
          return 1;
       if((distribution_function(t)<=tmp)&&(tmp<distribution_function(t+1)))
          return t+1;
   }
}

void Widget::on_lineEdit_editingFinished()
{
    QString checkString= ui->lineEdit->text();
    if(checkString.length()==0){
       ui->textBrowser->clear();
       set_current_random_number(renew());
       ui->lineEdit->setFocus();
       return;
    }
    ui->lineEdit->clear();
    int n=get_current_random_number();
    QString current_gender=Nounlist[n-1].get_gender();
    int current_weight=Nounlist[n-1].get_weight();
    if(((current_gender=="das"||current_gender=="der")&&checkString=="ein")||(current_gender=="die"&&checkString=="eine")){
        ui->textBrowser->append("Congratulations,your Answer is right!");
        if(current_weight>=10){
         Nounlist[n-1].set_weight(current_weight-10);
         set_total_weight(get_total_weight()-10);
       }
    }
    else{
        ui->textBrowser->append("Sorry,your answer is wrong.");
        Nounlist[n-1].set_weight(current_weight+20);
        set_total_weight(get_total_weight()+20);
        }
    if(Nounlist[n-1].whether_have_example_sentence())
    ui->textBrowser->append(QString("An example sentence:<font color='red'> %1 <font>").arg(Nounlist[n-1].get_example_sentence_randomly()));

    ui->textBrowser->append("Press Enter to continue");
    return;
}

GLsizei winWidth=400,winHeight=400;
void init(void){
  glViewport(0,0,winWidth,winHeight);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0,winWidth,0,winHeight);
}

                                // win the game, otherwise you lose the game.

void reshape(int newWidth,int newHeight){
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0,(GLdouble)newWidth,0,(GLdouble)newHeight);
  winWidth=newWidth,winHeight=newHeight;
  glViewport(0,0,winWidth,winHeight);
  glClear(GL_COLOR_BUFFER_BIT);
}
screenPt min1={280,30},max1={380,75};
screenPt pt[16]={{10,10},{190,10},{190,135},{210,135},{210,10},
  {390,10},{390,190},{120,190},{120,210},{390,210},
  {390,390},{210,390},{210,265},{190,265},{190,390},{10,390}};//construct 16 points which constitute the boundary of the maze.
void intersect(){
  if( (min1.x<=10||max1.x>=390||min1.y<=10||max1.y>=390)

  ||(max1.x>=120&&max1.y>=190&&min1.y<=210)

  ||(max1.x>=190&&min1.x<=210&&(min1.y<=135||max1.y>=265)) ){
     currentInstance->ui->textBrowser_2->append("You knocked on the wall and the game is over.");
  }

  if(max1.x>300&&min1.x<350&&max1.y>300&&min1.y<350){
      currentInstance->ui->textBrowser_2->append("You arrived at the Exit and the game is over.");
  }
}

void TranslateRectangle(double x,double y,screenPt& min,screenPt& max){
  glColor3f(0,0,0);
  glRectd(min.x,min.y,max.x,max.y);//Clear the original figure of the agent rectangle.

  glColor3f(1,1,0);//Set the color of the agent rectangle to yellow.
  min.x+=x;
  min.y+=y;
  max.x+=x;
  max.y+=y;
  glRectd(min.x,min.y,max.x,max.y);
  //translate the rectangle along the vector (x,y);
  glBegin(GL_LINE_LOOP);
    for(int i=0;i<16;i++)
        glVertex2d(pt[i].x,pt[i].y);
  glEnd();
  intersect();
  //Reconstruct the boundary line of the maze, in case that the line may be wiped out by the rectangle.
  glFlush();
}


void Widget::display1(){
  ui->lineEdit_2->setFocus();
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_LINE_LOOP);
    for(int i=0;i<16;i++)
        glVertex2d(pt[i].x,pt[i].y);
  glEnd();
  glRecti(300,300,350,350);

  glColor3f(1,0,0);
  glRasterPos2i(300,325);
  char exit[]="Exit";
  for(int i=0;i<4;i++)
      glutBitmapCharacter(GLUT_BITMAP_9_BY_15,exit[i]);

  glColor3f(1,1,0);
  glRectd(min1.x,min1.y,max1.x,max1.y);
  glFlush();
}
extern "C"
void display1CallBack(){
    currentInstance->display1();
}
void key(unsigned char k,int x,int y){
  if(k=='w'||k=='W')TranslateRectangle(0,5,min1,max1);
  if(k=='s'||k=='S')TranslateRectangle(0,-5,min1,max1);
  if(k=='a'||k=='A')TranslateRectangle(-5,0,min1,max1);
  if(k=='d'||k=='D')TranslateRectangle(5,0,min1,max1);
  intersect();
}
void Widget::on_pushButton_clicked()
{
    ui->lineEdit_2->setFocus();
    //glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(winWidth,winHeight);
    glutInitWindowPosition(700,100);
    init();


    glutCreateWindow("new Window");
    setUpCallBack();
    glutDisplayFunc(::display1CallBack);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(key);

    glutMainLoop();
}
void Widget::setUpCallBack(){
    currentInstance=this;
}
int get_steps(QString str){
    if(str=="eins")
       return 1;
    if(str=="zwei")
       return 2;
    if(str=="drei")
       return 3;
    if(str=="vier")
       return 4;
    if(str==QString::fromUtf8("f\u00FCnf")){
       return 5;
   }
    if(str=="sechs")
       return 6;
    if(str=="sieben")
       return 7;
    if(str=="acht")
       return 8;
    if(str=="neun")
       return 9;
    return 100;
}

void Widget::on_lineEdit_2_editingFinished()
{
   instruction=ui->lineEdit_2->text();
   ui->lineEdit_2->clear();
   QStringList strlist=instruction.split(",");
   ui->textBrowser_2->append(instruction);
   int step=get_steps(strlist.last());
  // ui->textBrowser_2->append(QString("%1,%2").arg(strlist[0]).arg(strlist[1]));
   if(step>9||step<0){
       ui->textBrowser_2->append("Illegal Input");
       return;
   }
   if(strlist.first()=="links")TranslateRectangle(-step,0,min1,max1);
   else if(strlist.first()=="rechts")TranslateRectangle(step,0,min1,max1);
   else if(strlist.first()=="ober")TranslateRectangle(0,step,min1,max1);
   else if(strlist.first()=="unter")TranslateRectangle(0,-step,min1,max1);
   else ui->textBrowser_2->append("Illegal Input");
}
