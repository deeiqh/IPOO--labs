#include "geometry.h"
#include <iostream>
#include <cmath>
using namespace std;

PointArray:: PointArray()
{
    points = new Point[0];
    size = 0;
}
PointArray:: PointArray(const Point points[], const int size)
{
    this->points = new Point[size];
    for (int i = 0; i < size; i++){
        this->points[i] = points[i];
    }
    this->size = size;
}
PointArray:: PointArray(const PointArray &pv)
{
    points = new Point[size];
    for (int i = 0; i < size; i++){
        points[i] = pv.points[i];
    }
    size = pv.size;
}
PointArray:: ~PointArray()
{
    delete[] points;
}
void PointArray:: resize(int n)
{
    Point *points_aux = new Point[n];
    int min;
    if (n<size)
        min = n;
    else
        min = size;
    for(int i = 0; i < min; i++)
        points_aux[i] = points[i];
    delete[] points;
    points = points_aux;
    size = n;     
}
void PointArray:: push_back(const Point &p)
{
    points[size - 1] = p;
    resize(size + 1);
}
void PointArray:: insert(const int position, const Point &p)
{
    resize(size + 1);
    for ( int i = size - 1; i > position ; i--) {
        points[i] = points[i - 1];
    }
    points [position] = p ;    
}
void PointArray:: remove(const int pos)
{
    if (pos >= 0 && pos < size){
        for (int i = pos; i < size-2;i++)
            points[i] = points[i+1];
        resize(size - 1);
    }
            
}
const int PointArray:: get_size()const
{
    return size;
}
void PointArray:: clear()
{
    resize(0);
}
Point *PointArray:: get(const int position)
{
    if (position >= 0 && position < size)
        return points+position;
    else
        return NULL;
}
const Point *PointArray:: get(const int position) const
{
       if (position >= 0 && position < size)
        return points+position;
    else
        return NULL;
}

int Polygon::cant_pol = 0;
Polygon:: Polygon(const Point points[], const int long_arr): points(points, long_arr)
{
    cant_pol++;
}
Polygon:: Polygon(const PointArray &arr): points(arr)
{
    cant_pol++;
}
Polygon:: ~Polygon()
{
    cant_pol--;
}
 
Point constructorPoints[4];
Point *updateConstructorPoints( const Point &p1 , const Point &p2, const Point &p3 , const Point &p4 = Point (0 ,0) ) 
{
    constructorPoints[0] = p1 ;
    constructorPoints[1] = p2 ;
    constructorPoints[2] = p3 ;
    constructorPoints[3] = p4 ;
    return constructorPoints ;
}

Rectangle:: Rectangle(const Point &ll, const Point &ur)
    : Polygon( updateConstructorPoints( ll, Point(ll.getX(), ur.getY()), ur, Point(ur.getX(), ll.getY())), 4)
{}

Rectangle:: Rectangle( const int llx, const int lly, const int urx, const int ury)
    : Polygon( updateConstructorPoints( Point(llx, lly), Point(llx, ury ), Point (urx, ury), Point (urx, lly)), 4)
{}

double Rectangle :: area () const 
{
 int largo = points.get(1) -> getY () - points.get(0) -> getY() ;
 int ancho = points.get(2) -> getX () - points.get(1) -> getX() ;
 return abs(static_cast<double> (largo * ancho) ) ;
}

Triangle:: Triangle( const Point &p1 , const Point &p2 , const Point &p3 )
    :Polygon (updateConstructorPoints(p1 , p2 , p3 ) , 3)
{}

double Triangle :: area () const
{
    int distx0_1 = points . get (0) -> getX () - points . get (1) -> getX () ,
        distx1_2 = points . get (1) -> getX () - points . get (2) -> getX () ,
        distx2_0 = points . get (2) -> getX () - points . get (0) -> getX () ;
    int disty0_1 = points . get (0) -> getY () - points . get (1) -> getY () ,
        disty1_2 = points . get (1) -> getY () - points . get (2) -> getY () ,
        disty2_0 = points . get (2) -> getY () - points . get (0) -> getY () ;
    double a = std :: sqrt ( distx0_1 * distx0_1 + disty0_1 * disty0_1 ) ,
           b = std :: sqrt ( distx1_2 * distx1_2 + disty1_2 * disty1_2 ) ,
           c = std :: sqrt ( distx2_0 * distx2_0 + disty2_0 * disty2_0 ) ;
    double s = ( a + b + c ) / 2;
    return std :: sqrt ( s * (s - a ) * (s - b ) * (s - c ) ) ;
}




































