#include <math.h>
#define PI 3.14159

typedef double real;

class point {
  real x;
  real y;
public:
  point();
  point(point& o);
  point(real cx, real cy);
  real getX();
  real getY();
};

class segmento {
  point start, end; // punto de inicio y punto final
  real longitud; // longitud del segmento
public:
  segmento();
  segmento(real l);
  segmento(segmento& o);
  segmento(point& pStart, point& pEnd);
  void initLongitud();
  real getLongitud();
  point* getStart();
  point* getEnd();
};

class Poligono {
protected:
  segmento* lados; // puntero a un dato de tipo segmento
  point* vertices; // puntero a un dato de tipo punto
  real area;
  real perimetro;
  int sum_ang_int; // suma de angulos interiores
public:
  Poligono(point* ver,segmento* lad); //constructor personalizado
  virtual void calc_area() = 0;
  void calc_perimetro();
  real getPerimetro();
  real getArea();
};

class Cuadrilatero : public Poligono {
  bool iscuadrado, isrectangulo, istrapecio, istrapeciorec;
public:
  Cuadrilatero(point* ver, segmento* lad, bool trapecio1, bool trapeciorec1);
  void cuadrado();
  void rectangulo();
  void calc_area();
};

class Triangulo : public Poligono {
  bool isisoceles, isregular;
public:
  Triangulo(point* ver, segmento* lad);
  void type_triangulo();
  void calc_area();
};

class Circulo {
  point centro;
  segmento radio, diametro;
  real longitudC, areaC;
public:
  Circulo(point& c,segmento& r);
  void calc_longitudC();
  void calc_areaC();
  real getLongC();
  real getAreaC();
};
