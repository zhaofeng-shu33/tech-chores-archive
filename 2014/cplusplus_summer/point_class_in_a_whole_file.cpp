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
class Polygon: public Point2D{
    public:
        virtual ~Polygon(){}
        virtual double area()=0;
        virtual double perimeter()=0;
}; 
class Triangle: public Polygon{
    public:
        Triangle(Point2D X1,Point2D X2,Point2D X3): X(X1),Y(X2),Z(X3){}
        ~Triangle(){}
          
        double area(){
          double a1,a2,a3;
          a1=distance_1(X,Y);
          a2=distance_1(X,Z);
          a3=distance_1(Y,Z);
          double p=(a1+a2+a3)/2;
          return sqrt(p*(p-a1)*(p-a2)*(p-a3));
          }
        double perimeter(){
          double a1,a2,a3;
          a1=distance_1(X,Y);
          a2=distance_1(X,Z);
          a3=distance_1(Y,Z);
          return (a1+a2+a3);
          }
    private:
         Point2D X,Y,Z;

};
class Rectangle: public Polygon{
    public:                                                                              //by X1~X3.                                                                                                                   
    Rectangle(Point2D X1,Point2D X2,Point2D X3): X1(X1),X2(X2),X3(X3){}//X1~X3 was input counterclockwise,
    ~Rectangle(){}                                                                                    //so the fourth vertex of rectangle can be determined
    double area(){
          double a1=distance_1(X1,X2);
          double a2=distance_1(X2,X3);
          return a1*a2;
          }
    double perimeter(){
          double a1=distance_1(X1,X2);
          double a2=distance_1(X2,X3);
          return 2*(a1+a2);
         }
    private:
        Point2D X1,X2,X3;
};        
int main(){
  Point2D B1(-1,0),B2(2,0),B3(2,4);
  Polygon* my_polygon=new Rectangle(B1,B2,B3);
  cout<<my_polygon->perimeter()<<' ';
  cout<<my_polygon->area();
  delete my_polygon;
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
