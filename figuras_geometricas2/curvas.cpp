#include "curvas.h"
#define PI  3.1415



TPunto Curvas:: area() const
{
    return TPunto(PI)*(puntos[1].x)*(puntos[2].x);
}

TPunto Curvas:: perimetro() const
{
    return TPunto(PI)*(puntos[1].x)*(puntos[1].x);
}
