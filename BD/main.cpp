
#include "Tabla.h"
//#include "Indice.h"

using namespace std;


int main(void)
{
    string campos = "DNI CUI Apellido";
    Tabla t_datos_personales("datos_personales","Datos",campos,15);
    
    Registro *ptr_registro = t_datos_personales.genera_registro();

    t_datos_personales.insertar(ptr_registro);
    
    //if (!t_datos_personales.idexado("Apellido"))
    //    t_datos_personales.indexar("Apellido");
    
    
    
    
    
    
    return 0;
}

