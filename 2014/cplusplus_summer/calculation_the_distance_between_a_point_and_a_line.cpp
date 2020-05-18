#include<iostream>
#include<fstream>
#include <cstring>
#include<cmath>

using namespace std;
class Point2D{
    public:
        Point2D();
        Point2D(double x, double y);
        Point2D(Point2D& c);
        ~Point2D();
        void Input_Point();
        void Output_Point();
        void Set_Point(double e, double f);
        double GetX();
        double GetY();
        friend double distance_1(Point2D a, Point2D b);
        friend class Line2D;
    private:
        double x,y;
};
class Line2D{  // ax+by+c=0
  public:
    Line2D(double a1, double b1,double c1){
      a=a1;b=b1;c=c1;
    }
    static double dist(Line2D li, Point2D A){
     double temp1=li.a*A.GetX()+li.b*A.GetY()+li.c, temp2=sqrt(li.a*li.a+li.b*li.b);
     return abs(temp1)/temp2;
    }  
    friend double dist(Line2D li,Point2D A);
  private:
     double a,b,c;
};
double dist(Line2D li,Point2D A){
     double temp1=li.a*A.GetX()+li.b*A.GetY()+li.c, temp2=sqrt(li.a*li.a+li.b*li.b);
     return abs(temp1)/temp2;
}  
int main(){
  Point2D *B=new Point2D[2];
  (*B).Set_Point(1,2);
  (*(B+1)).Set_Point(3,4);
  cout<<B->GetX()<<' '<<(*(B+1)).GetX();
  char ch;
  cin>>ch;
  return 0;
}    
Point2D::Point2D(){}
Point2D::Point2D(double x1, double y1){
         x=x1;
         y=y1;
}    
Point2D::Point2D(Point2D& c){
         x=c.x;
         y=c.y;
}    
Point2D::~Point2D(){}
void Point2D::Input_Point(){
     cin>>x>>y;
}    
void Point2D::Output_Point(){
     cout<<'('<<x<<','<<y<<')';
}    
void Point2D::Set_Point(double e, double f){
            x=e;y=f;
        }    
double Point2D::GetX(){
            return x;
        }
double Point2D::GetY(){
            return y;
   }
double distance_1(Point2D a, Point2D b){
      double x1=a.x-b.x,y1=a.y-b.y;
      return sqrt(x1*x1+y1*y1);
}             
