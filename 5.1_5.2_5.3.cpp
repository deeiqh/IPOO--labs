#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>

float calcular_pi(const int lanzados);

int main(void){
    int lanzados;
    std::cin >> lanzados;
    std::cout << calcular_pi(lanzados);
    return 0;
}

float calcular_pi(const int lanzados)
{
    srand (time(0));
    int envocados = 0;
    for (int i = 0; i != lanzados; i++){
        float x = rand()/(float)RAND_MAX;
        float y = rand()/(float)RAND_MAX;
        float dentro = sqrt(x*x+y*y);
        if (dentro<1)
            envocados++;
    }
    
    return (envocados*4.0 / lanzados) ;
}