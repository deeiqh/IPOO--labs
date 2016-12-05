
#include <iostream>
#include <string>

using namespace std;

#define imp_l(l1) ( cout << l1.tipo << '\n'<< '\t' <<l1.marca << '\t' << "Rank: " << l1.rank << '\n'  )
#define imp_u(u1) ( cout << u1.tipo << '\n'<< '\t' <<u1.marca << '\t' << "Rank: " << u1.rank << "\tFusionable: " <<  u1.fusionable << "\tDescripción: "<< *u1.descripcion <<'\n' )
#define imp_m(u1) ( cout << u1.tipo << '\n'<< '\t' <<u1.marca << '\t' << "Rank: " << u1.rank << "\tDorada: " <<  u1.dorada << "\tDescripción: "<< *u1.descripcion <<'\n' )

class Portatil //Prototipo
{
public:
    string marca;
    string tipo; 
    string rank;       
    
public:
    Portatil(string marca, string tipo, string rank): marca(marca), tipo(tipo), rank(rank) {};
    
    virtual Portatil *clone() = 0;
    
};

class Laptop: public Portatil //PrototipoConcreto
{
public:
    
public:
    Laptop(string marca, string rank): Portatil(marca, "Laptop", rank) {};
    
    virtual Laptop *clone() override
    {
        return new Laptop(marca, rank);
    };
};

class Ultrabook: public Portatil //PrototipoConcreto
{
public:
    bool fusionable;
    string *descripcion;
    
public:
    Ultrabook(string marca, string rank, bool fusionable, string *desc):
        Portatil(marca, "Ultrabook", rank), fusionable(fusionable), descripcion(desc) {};
    
    virtual Ultrabook *clone() override
    {
        return new Ultrabook(marca, rank, fusionable, descripcion);
    };
};

class MacBook: public Portatil //PrototipoConcreto
{
public:
    bool dorada;
    string *descripcion;
    
public:
    MacBook(string marca, string rank, bool dorada, string *desc):
        Portatil(marca, "MacBook", rank), dorada(dorada), descripcion(desc) {};
    
    virtual MacBook *clone() override
    {
        string *descripcion_nueva = new string;
        return new MacBook(marca, rank, false, descripcion_nueva);
    };
};

int main(void)

{
    cout << "ORIGINAL: \n";
    Laptop l1("HP","Alto"); // ingresar marca y rank    
    imp_l(l1);
    
    cout << "CLON: \n";
    Laptop *l2 = l1.clone(); //clona marca, tipo, rank    
    Laptop l2_temp = *l2;
    imp_l(l2_temp);
    
    cout << "-------------------------------\n";
    cout << "ORIGINAL: \n";
    string *descripcion2 = new string("La nueva Ultrabook peruana de este 2017");
    Ultrabook u1("Mc","Altísimo",true,descripcion2); // ingresar marca, rank, fusionable, descripcion 
    imp_u(u1);
    
    cout << "CLON: \n";
    Ultrabook *u2 = u1.clone(); // clona marca, tipo, rank, fusionable, descripcion    
    *u2->descripcion = "He arrasado con todo";
    Ultrabook u2_temp = *u2;
    imp_u(u2_temp); 
    
    cout << "ORIGINAL: \n";
    imp_u(u1);
    
    cout << "-------------------------------\n";
    cout << "ORIGINAL: \n";
    string *descripcion = new string("Mejorando cada vez más");
    MacBook m1("Apple", "Bajo", true, descripcion);
    imp_m(m1);
    
    cout << "CLON: \n";
    MacBook *m2 = m1.clone(); // clona marca, tipo, rank, fusionable, descripcion  
    *m2->descripcion = "No he podido arrasar";
    MacBook m2_temp = *m2;
    imp_m(m2_temp);
    
    cout << "ORIGINAL: \n";
    imp_m(m1);
    
    delete l2;
    delete u2;
    delete m2;
    
    return 0;
}

