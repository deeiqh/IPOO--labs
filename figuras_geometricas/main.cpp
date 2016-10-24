#include <iostream>
#include "geometry.h"

using namespace std;

// real(double)
// point, segmento, Poligono(Abstracto), Cuadrilatero(__,__,(bool) si es que es trapecio,(bool) si es que es trapecio recto)

int main() {
  segmento lasts; // ultimo punto y ultimo segmento para poder usar condicionales que el valor sea igual a '0.0' (linea 48)
  // Creando un Cuadrado --------------------------------------------------------------------
  point p1(2.0,3.0), p2(2.0,8.0), p3(7.0,8.0), p4(7.0,3.0), puntos_sq[] {p1,p2,p3,p4};
  segmento s1(p1,p2), s2(p2,p3), s3(p3,p4), s4(p4,p1), lados_sq[] {s1,s2,s3,s4,lasts};
  Cuadrilatero square1(puntos_sq,lados_sq,false,false); // square1(__,__,si es que es trapecio,si es que es trapecio recto)
  cout << "Cuadrado: " << endl;
  cout << " → Perimetro = " << square1.getPerimetro() << endl;
  cout << " → Area = " << square1.getArea() << endl;
  // Creando un Rectangulo ------------------------------------------------------------------
  point a1(2.0,3.0), a2(2.0,6.0), a3(7.0,6.0),a4(7.0,3.0), puntos_rc[] {a1,a2,a3,a4};
  segmento l1(a1,a2), l2(a2,a3), l3(a3,a4), l4(a4,a1), lados_rc[] {l1,l2,l3,l4,lasts};
  Cuadrilatero rectangulo1(puntos_rc,lados_rc,false,false); // rectangulo1(__,__,si es que es trapecio,si es que es trapecio recto)
  cout << "Rectangulo: " << endl;
  cout << " → Perimetro = " << rectangulo1.getPerimetro() << endl;
  cout << " → Area = " << rectangulo1.getArea() << endl;
  // Creando un Trapecio ---------------------------------------------------------------------
  point t1(2.0,3.0), t2(3.0,6.0), t3(6.0,6.0), t4(7.0,3.0), puntos_t[] {t1,t2,t3,t4};
  segmento lt1(t1,t2), lt2(t2,t3), lt3(t3,t4), lt4(t4,t1), lados_t[] {lt1,lt2,lt3,lt4,lasts};
  Cuadrilatero trapecio1(puntos_t,lados_t,true,false); // trapecio1(__,__,si es que es trapecio,si es que es trapecio recto)
  cout << "Trapecio: " << endl;
  cout << " → Perimetro = " << trapecio1.getPerimetro() << endl;
  cout << " → Area = " << trapecio1.getArea() << endl;
  // Creando un Circulo ----------------------------------------------------------------------
  point c1;
  real radio = 5.0;
  segmento r1(radio);
  Circulo circulo1(c1,r1);
  cout << "Circulo: " << endl;
  cout << " → Longitud = " << circulo1.getLongC() << endl;
  cout << " → Area = " << circulo1.getAreaC() << endl;
  // Creando un Triangulo --------------------------------------------------------------------
  point ta1(2.0,3.0), ta2(4.0,5.0), ta3(6.0,3.0), points_ta[] {ta1,ta2,ta3};
  segmento tl1(ta1,ta2), tl2(ta2,ta3), tl3(ta3,ta1), lados_ta[] {tl1,tl2,tl3,lasts};
  Triangulo triangulo1(points_ta,lados_ta);
  cout << "Triangulo: " << endl;
  cout << " → Perimetro = " << triangulo1.getPerimetro() << endl;
  cout << " → Area = " << triangulo1.getArea() << endl;
  return 0;
}