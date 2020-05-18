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
        void operator =(Point2D R){
          x=R.x;y=R.y;
        }  
        friend double distance_1(Point2D a, Point2D b);
        friend class Line2D;
    private:
        double x,y;
};
class Polygon: public Point2D{
    public:
        Polygon(Point2D a[],int size){
           for(int i=0;i<size;i++)
              P[i]=a[i]; 
        }
        virtual ~Polygon(){}
        virtual double area()=0;
        virtual double perimeter()=0;
   
    protected:
        Point2D P[4];
};
class Triangle: public Polygon{
    public:
        Triangle(Point2D a[]): Polygon(a,3){}
        ~Triangle(){}
        double area(){
          double a1,a2,a3;
          a1=distance_1(P[0],P[1]);
          a2=distance_1(P[1],P[2]);
          a3=distance_1(P[0],P[2]);
          double p=(a1+a2+a3)/2;
          return sqrt(p*(p-a1)*(p-a2)*(p-a3));
          }
        double perimeter(){
          double a1,a2,a3;
          a1=distance_1(P[0],P[1]);
          a2=distance_1(P[1],P[2]);
          a3=distance_1(P[0],P[2]);
          return (a1+a2+a3);
          }

};  
class Rectangle: public Polygon{
    public:                                                                              
    Rectangle(Point2D a[]): Polygon(a,4){}
    ~Rectangle(){}                                                                                    
    double area(){
          double a1,a2;
          a1=distance_1(P[0],P[1]);
          a2=distance_1(P[1],P[2]);
          return a1*a2;
          }
    double perimeter(){
          double a1,a2;
          a1=distance_1(P[0],P[1]);
          a2=distance_1(P[1],P[2]);
          return 2*(a1+a2);
         }
};        
int main(){
  Point2D B[4]; 
  B[0].Set_Point(-1,0);
  B[1].Set_Point(2,0);
  B[2].Set_Point(2,1);
  B[3].Set_Point(-1,1);
  Polygon* my_polygon=new Rectangle(B);
  cout<<my_polygon->perimeter()<<' '<<my_polygon->area();
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
