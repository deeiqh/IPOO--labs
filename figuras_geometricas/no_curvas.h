#ifndef NO_CURVAS_H
#define NO_CURVAS_H

#include "formas.h"

class No_Curvas: public Formas{
public:
    Punto *puntos;

    No_Curvas(const char *nombre, const int cantidad_puntos):  Formas(nombre, cantidad_puntos), puntos(new Punto[cantidad_puntos]){}

    TPunto area() const override;
    TPunto perimetro() const override;

    ~No_Curvas(){delete[] puntos;}
};



#endif
