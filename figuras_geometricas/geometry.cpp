#include <math.h>
#include "geometry.h"
#include <cstdlib>
#include <stdio.h>



// class point
// Constructores para point
point::point(): x(0.0), y(0.0) {}
point::point(point& o): x(o.x), y(o.y) {}
point::point(real cx, real cy): x(cx), y(cy) {}
// Metodos de point
real point::getX() {return x;}
real point::getY() {return y;}

// class segmento
// Constructores para segmento
segmento::segmento(): longitud(0.0) {}
segmento::segmento(real l): longitud(l) {}
segmento::segmento(segmento& o): start(o.start), end(o.end), longitud(o.longitud) {}
segmento::segmento(point& pStart, point& pEnd): start(pStart), end(pEnd) {initLongitud();}
// Metodos para segmento
void segmento::initLongitud(){
  real rx, ry;
  rx = pow((end.getX() - start.getX()),2);
  ry = pow((end.getY() - start.getY()),2);
  real r = sqrt(rx + ry);
  longitud = r;
}
real segmento::getLongitud() {return longitud;}
point* segmento::getStart() {return &start;}
point* segmento::getEnd() {return &end;}

// class Poligono
// Constructores para Poligono
Poligono::Poligono(point* ver,segmento* lad): lados(lad), vertices(ver) {calc_perimetro();}
// Metodos para Poligono
void Poligono::calc_perimetro(){
  real sum = 0.0;
  segmento* temp = lados; // para que lados siga apuntando a la misma direccion : &lados[0]
  while (temp->getLongitud() != 0)
    sum += (temp++)->getLongitud(); // mientras que temp si se mueve por las diferentes posiciones
  perimetro = sum;
}
real Poligono::getPerimetro() {return perimetro;}
real Poligono::getArea() {return area;}

// class Cuadrilatero
// Constructores para Cuadrilatero
Cuadrilatero::Cuadrilatero(point* ver, segmento* lad, bool trapecio1, bool trapeciorec1): Poligono(ver,lad), istrapecio(trapecio1), istrapeciorec(trapeciorec1) {
  cuadrado();
  rectangulo();
  calc_area();
}
// Metodos para Cuadrilatero
void Cuadrilatero::cuadrado(){
  real a = lados->getLongitud();
  segmento* temp = lados;
  while (temp->getLongitud() != 0.0){
    if ((temp++)->getLongitud() != a){
      iscuadrado = false;
      return;
    }
  }
  iscuadrado = true;
  isrectangulo = false;
  istrapecio = false;
  istrapeciorec = false;
}
void Cuadrilatero::rectangulo(){
  real a = lados->getLongitud(), b = (lados+1)->getLongitud();
  segmento* temp = lados;
  temp +=2;
  if (temp->getLongitud() == a && (temp+1)->getLongitud() == b){
    isrectangulo = true;
    iscuadrado = false;
    istrapecio = false;
    istrapeciorec = false;
  }
  else
    isrectangulo = false;
}
void Cuadrilatero::calc_area(){
  if (iscuadrado){
    area = pow(lados->getLongitud(),2);
  }
  else if (isrectangulo){
    area = lados->getLongitud() * (lados+1)->getLongitud();
  }
  else if (istrapecio){
    segmento* temp_seg = lados;
    segmento* bmayor = lados;
    real altura;
    while (temp_seg->getLongitud() != 0){
      if ((temp_seg++)->getLongitud() > bmayor->getLongitud())
        bmayor = temp_seg;
    }
    segmento* bmenor = (bmayor+1)->getLongitud() == 0.0 || (bmayor+2)->getLongitud() == 0.0? bmayor - 2: bmayor + 2;
    point* temp_pointB = bmayor->getStart();
    point* temp_pointb = bmenor->getStart();
    altura = abs(temp_pointb->getY() - temp_pointB->getY());
    area = (bmayor->getLongitud() + bmenor->getLongitud()) * altura / 2;
  }
}

// Clase Triangulo
// Constructores para Triangulo
Triangulo::Triangulo(point *ver, segmento *lad) : Poligono(ver,lad), isisoceles(false), isregular(false) {
  type_triangulo();
  calc_area();
}
// Metodos para Triangulo
void Triangulo::type_triangulo(){
  segmento* temp = lados;
  real a = temp->getLongitud();
  int equals = 0;
  while (temp - lados != 2)
    if ((temp++)->getLongitud() == a)
      equals += 1;
  if (equals == 2)
    isisoceles = true;
  else if (equals == 3)
    isregular = true;
}
void Triangulo::calc_area(){
  segmento* temp = lados;
  if (!isregular){
    point* temp_p = vertices;
    point* start = temp->getStart();
    point* end = temp->getEnd();
    for (int i = 0; i < 2; i++){
      temp_p++;
    }
    real xmedio = (start->getX() + end->getX())/2, ymedio = (start->getY() + end->getY())/2;
    point m(xmedio,ymedio);
    segmento altura(*temp_p,m);
    area = (temp->getLongitud() * altura.getLongitud()) / 2;
  }
  else
    area = (sqrt(3)/4) * pow(temp->getLongitud(),2);
}

// Clase Circulo
// Constructores para Circulo
Circulo::Circulo(point& c, segmento& r): centro(c), radio(r), diametro(r.getLongitud()*2) {
  calc_longitudC();
  calc_areaC();
}
// Metodos para Circulo
void Circulo::calc_longitudC(){
  longitudC = 2 * PI * radio.getLongitud();
}
void Circulo::calc_areaC(){
  areaC = PI * pow(radio.getLongitud(),2);
}
real Circulo::getAreaC() {return areaC;}
real Circulo::getLongC() {return longitudC;}