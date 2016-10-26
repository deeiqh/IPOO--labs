#include "no_curvas.h"
#include <math.h>

TPunto No_Curvas:: area() const
{

}

TPunto longitud_segmento(Punto a, Punto b)
{
    return TPunto (sqrt( pow(b.x - a.x,2) + pow(b.y - a.y,2) ) );
}

TPunto No_Curvas:: perimetro() const
{
    TPunto sum = 0;
    int i;
    for(i = 0; i<cantidad_puntos-1; i++)
        sum += longitud_segmento(puntos[i],puntos[i+1]);
    return sum += longitud_segmento(puntos[i],puntos[0]);;
}
