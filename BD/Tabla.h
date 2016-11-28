#ifndef TABLA_H
#define TABLA_H

#include <string>
#include <fstream>
#include <map>

using namespace std;
using Registro = string;
using Tam = unsigned char; // tamaño
using Codigo = unsigned int;
using Cabecera = map<string, bool>;

class Tabla

{
protected:
    string nombre;
    string tipo; // Tabla de tipo Datos, Relación, Index
    string nombres_campos;
    Tam tamanho_campo;
    fstream archivo;    
public:
    Tabla(string nombre, string tipo, string nombres_campos, Tam tamanho_campo):
        nombre(nombre), tipo(tipo),  nombres_campos(nombres_campos), tamanho_campo(tamanho_campo)
        {
            archivo.open(nombre, ostream::out | ostream::binary);
            archivo.close(); 
            Registro *ptr_reg = genera_cabecera();
            insertar(ptr_reg);
            if (tipo != "Indice"){
                Registro *indices = new string;
                for(int i = 0; i < cant_campos(); i++) //se coloca el valor de 0 (no indexado)
                    *indices += " 0";
                insertar(indices);
            }
        };
    Tam tam_registros() const; 
    Tam cant_campos() const;
    virtual Registro *genera_registro(); // se generan para luego escribirlos en la tabla
                                           //un reg de tabla siempre la llena el usuario
                                           // el gen_reg de indice lo hace el sistemA
    virtual Registro *genera_cabecera();
    void insertar(Registro *ptr_registro); // se formatea el reg para luego escribirlo
    bool indexado(string campo);
};

#endif


