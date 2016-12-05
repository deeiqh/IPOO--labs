#ifndef INDICE_H
#define INDICE_H

//#include <map>
#include <fstream>
#include "Tabla.h"

using namespace std;
//using Indice_ = map<string, Codigo>;

class Indice: public Tabla

{
private:
    Tam orden_campo;
public:    
    Indice(Tabla *tabla_origen, string campo):
        Tabla("Indice_" + tabla_origen->getNombre() + "_" + campo, "Indice", tabla_origen->getCampoKey(), campo,
                tabla_origen->getTamanho_campos())
        {
            orden_campo = orden(tabla_origen, campo);
            /*
            Tam orden_campo(tabla_origen, campo);
            Registro *orden = string("0 ");
            *orden += to_string(orden_campo);
            insertar(orden);
             */
        };
        
    Tam orden(Tabla *tabla_origen, string campo);
    Registro *genera_registro(Registro *reg);
    void indexar(Registro *ptr_ri = NULL);
    Tam get_ordenCampo(){return orden_campo;};
    void actualizar_td(Tabla *tabla_datos);
};

#endif

           