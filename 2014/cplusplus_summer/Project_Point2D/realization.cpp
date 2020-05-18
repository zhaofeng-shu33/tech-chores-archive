#include "Point2D.h"
using namespace std;
Point2D::Point2D(){}
Point2D::Point2D(double x1, double y1){
         x=x1;
         y=y1;
}    
Point2D::Point2D( const Point2D& c){
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
void Point2D::Move_Point(double e, double f) {
      x+=e;
      y+=f;
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
Point2D& Point2D::operator ++(){
           x++;
           return *this;
}
Point2D  Point2D::Point2D::operator +(Point2D Q){
           return Point2D(x+Q.x,y+Q.y);
}
Point2D  Point2D::operator ++(int){  // return not a reference.
           Point2D P=*this;
           ++(*this);
           return P;
        }
Point3D::Point3D(double a, double b, double c): Point2D(a,b),z(c){}
double Point3D::distance_2(Point3D P){
       return sqrt((x-P.x)*(x-P.x)+(y-P.y)*(y-P.y)+(z-P.z)*(z-P.z));
}   
Rectangle2D::Rectangle2D(Point2D A, double a, double b):L(a),W(b),Point2D(A){}
Rectangle2D::Rectangle2D(Rectangle2D& rec):Point2D(rec),L(rec.L),W(rec.W){}  //copy construction   
 void Rectangle2D::Output(){
      cout<<'('<<GetX()<<','<<GetY()<<')'<<' '<<"Length: "<<L<<" Wide: "<<W<<endl;
 }  
 double Rectangle2D::GetL(){return L;}
 double Rectangle2D::GetW(){return W;}    
