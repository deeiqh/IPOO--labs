#ifndef FORMAS_H
#define FORMAS_H

#include "punto.h"

class Formas{
protected:
    const char *nombre;
    int cantidad_puntos;
public:
    Formas(const char * nombre, int cantidad_puntos): nombre(nombre), cantidad_puntos(cantidad_puntos){}
    virtual TPunto area() const = 0;
    virtual TPunto perimetro() const = 0;
};

#endif
