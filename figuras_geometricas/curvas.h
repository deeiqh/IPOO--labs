#ifndef CURVAS_H
#define CURVAS_H

#include "formas.h"


class Curvas: public Formas{
public:

    Punto *puntos;
    Curvas(const char *nombre, const int cantidad_puntos = 3): Formas(nombre, cantidad_puntos), puntos(new Punto[cantidad_puntos]){}
    // cantidad_puntos es 3 porque se asumira que el primer elemento es el punto, el segundo el eje mayor y el tercero el eje menor
    TPunto area() const override;
    TPunto perimetro() const override;
    ~Curvas(){delete[] puntos;}
};


#endif

