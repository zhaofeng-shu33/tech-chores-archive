#ifndef __POINT2D_H__
#define __POINT2D_H__
#include<iostream>
#include<fstream>
#include <cstring>
#include<cmath>

class Point2D{
    public:
        Point2D();
        Point2D(double x, double y);
        Point2D(const Point2D& c);
        ~Point2D();
        void Input_Point();
        void Output_Point();
        void Set_Point(double e, double f);
        void Move_Point(double e, double f);
        double GetX();
        double GetY();
        friend double distance_1(Point2D a, Point2D b);
       // friend Point2D operator + (Point2D a, Point2D b);
        friend class Triangle;
        Point2D& operator ++();
        Point2D  operator +(Point2D Q);
        Point2D  operator ++(int);
    protected:
        double x,y;
};
class Point3D: public Point2D{
    public:
      Point3D(double a, double b, double c);
      double distance_2(Point3D P);
    private:
        double z;
};  
  
class Rectangle2D: public Point2D
{
  public:
    Rectangle2D(Point2D A, double a, double b);
    Rectangle2D(Rectangle2D& rec);
    double GetL();
    double GetW();
    void Output();    
  private:
    double L,W;
};  
double distance_1(Point2D a, Point2D b);
#endif
