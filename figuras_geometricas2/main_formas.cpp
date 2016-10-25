#include <iostream>
#include "formas.h"
#include "PuntosArray.h"
#include "curvas.h"
#include "no_curvas.h"

using namespace std;

int main(void)
{

    Curvas elipse("elipse");
    elipse.puntos[0].x = 0;
    elipse.puntos[0].y = 0;
    elipse.puntos[1].x = 3;
    elipse.puntos[2].x = 3;

    No_Curvas triangulo("triangulo",3);
    triangulo.puntos[0].x = 0;
    triangulo.puntos[0].y = 0;
    triangulo.puntos[1].x = 0;
    triangulo.puntos[1].y = 4;
    triangulo.puntos[2].x = 4;
    triangulo.puntos[2].y = 0;

    cout << elipse.area()<<'\n';
    cout << triangulo.perimetro()<<'\n';


    return 0;
}
