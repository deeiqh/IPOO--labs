#ifndef CURVAS_H
#define CURVAS_H

#include "formas.h"


class Curvas: public Formas{
public:

    Punto *puntos;
    Curvas(const char *nombre, const int cantidad_puntos = 3): Formas(nombre, cantidad_puntos), puntos(new Punto[cantidad_puntos]){}

    TPunto area() const override;
    TPunto perimetro() const override;
    ~Curvas(){delete[] puntos;}
};


#endif

