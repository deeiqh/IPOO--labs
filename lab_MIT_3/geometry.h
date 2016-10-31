#ifndef GEOMETRY_H
#define GEOMETRY_H

class Point
{
private:
    int x, y;
public:
    Point (int x = 0, int y = 0): x(x), y(y) {}
    int getX() const {return x;}
    int getY() const {return y;}
    void setX( const int x){this->x = x;}
    void setY( const int x){this->y = y;}
};

class PointArray
{
private:
    int size;
    Point *points;
    
    void resize(int n);
    
public:
    PointArray();
    PointArray(const Point points[], const int size);
    PointArray(const PointArray &pv);
    ~PointArray();
    void push_back(const Point &p);
    void insert(const int position, const Point &p);
    void remove(const int pos);
    const int get_size()const;
    void clear();
    Point *get(const int position);
    const Point *get(const int position) const;
};

class Polygon
{
protected:
    PointArray points;
    static int cant_pol;
public:
    Polygon(const Point points[], const int long_arr);
    Polygon(const PointArray &arr);
    ~Polygon();
    virtual double area () const = 0;
    static int getNumPolygons () { return cant_pol ;}
    int getNumSides () const { return points.get_size() ;}
    const PointArray * getPoints () const { return &points ;}

};

class Rectangle: public Polygon
{
public:
    Rectangle(const Point &ll, const Point &ur);
    Rectangle(const int llx , const int lly , const int urx , const int ury );
    virtual double area () const override;
};

class Triangle: public Polygon
{
public :
    Triangle ( const Point &p1 , const Point &p2 , const Point &p3 );
    virtual double area () const override;
};
#endif






































