#include "curvas.h"
#define PI  3.1415



TPunto Curvas:: area() const
{
    return TPunto(PI*(puntos[1].x)*(puntos[2].x));
}

TPunto Curvas:: perimetro() const
{
    return TPunto( 2.0 * PI * ( sqrt( pow(puntos[1].x,2) + pow(puntos[2].x,2) / 2.0) ) );
}
