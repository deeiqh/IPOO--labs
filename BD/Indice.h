#ifndef INDICE_H
#define INDICE_H

//#include <map>

using namespace std;
//using Indice_ = map<string, Codigo>;

class Indice: public Tabla

{
private:
public:
    Indice(string nombre, string nombres_campos, Tam tamanho_campo):
        Tabla(nombre, "Indice", nombres_campos, tamanho_campo)
        {
            
        };
    virtual Registro *genera_registro () override;
    virtual Registro *genera_cabecera() override;
};

#endif

           