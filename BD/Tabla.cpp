#include "Tabla.h"
#include <iostream>
#include <sstream>
#include <map>

#define pb push_back

Tam Tabla::tam_registros() const
{
    return tamanho_campo * cant_campos();
}

Tam Tabla::cant_campos() const
{
    Tam n = 0;
    istringstream str(nombres_campos);
    string s;
    while(str >> s){
        n++;
    }
    return n;
}

string ingresar_campo(Tam tc)//tamaño de registros, cantidad de campos
{
    string temp;
    cin >> temp;
    while(temp.size() > tc){//que el tamaño del dato del campo no se mayor al establecido para el campo
        cin >> temp;
    }
    return temp;           
}
Registro *Tabla::genera_registro() 
{
    Registro *ptr_registro = new string;
    for(int i = 0; i < cant_campos()+1; i++){
        *ptr_registro += ingresar_campo(tamanho_campo);
        ptr_registro->pb(' ');
    }
    return ptr_registro;
}

Registro *Tabla::genera_cabecera()
{
    string *ptr_registro = new string(campo_key);
    (*ptr_registro) += " " + nombres_campos;
    return ptr_registro;

}

void Tabla::insertar(Registro *ptr_registro) 
{
    archivo.open(nombre,ostream::app);
    istringstream is(*ptr_registro);
    string format;
    string temp;
    Tam cc = cant_campos() + 1;
    for(int i = 0; i < cc; i++){
        is >> temp; 
        format.append(temp);
        for(int j = 0; 
                            j < tamanho_campo - temp.size();//tamaño de cada campo - size de lo leido = espacio libre en el campo
                                                        j++)
                format.pb(' ');        
        if(i < cc -1) // para no imprimir el ultimo ' '
                format.pb(' ');
    }
    archivo << format << '\n';
    
    delete ptr_registro;    
    archivo.close();
}

bool Tabla::indexado(string campo)
{
    archivo.open(nombre, istream:: in);
    //Tam move = (tamanho_campo+1)*cant_campos();
    //archivo.seekg(move, istream::beg());   
    
    string cabecera_t; istringstream cabecera;
    getline(archivo, cabecera_t); cabecera.str(cabecera_t);
    
    string valores_t; istringstream valores;
    getline(archivo, valores_t); valores.str(valores_t);    
    
    archivo.close();
    
    map<string,string> mapa;
    string val, val2;
    while (cabecera >> val && valores >> val2 ){
        mapa[val] = val2;
    }
    auto it = mapa.find(campo);
    if ( it != mapa.end() && it->second  == "1")
        return true;
    return false;
}


    
