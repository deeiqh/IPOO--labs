#include<iostream>

using namespace std;
using Key = int;
using Data = int;
using Size = int;

class Nodo
{
public:
    Key key;
    Data *data;
    Nodo *sgte;
    Nodo(Key key = 0, Data *data = NULL): key(key), data(data), sgte(NULL) {}
};

class Lista_E: public Nodo
{
public:
    Nodo *lista;
    Lista_E(): lista(NULL){}
    void print() const
    {
        if (lista == NULL) 
            cout << "NULL" << '\n';
        else{
            cout << lista->key << " -> ";
            Nodo *current = lista->sgte;
            for(;current != NULL; current = current->sgte){
                cout << current->key << " -> ";
            }
            cout << "NULL" << '\n';
        }
    }
    Lista_E *insert(Key key, Data *data)
    {
        Nodo *nodo = new Nodo(key,data); //IMPORTANTE CREAR DINAMICAMENTE
        if (lista == NULL){
            lista = nodo;
            return this;
        }
        if (nodo->key <= lista->key){
            nodo->sgte = lista;
            lista = nodo;
            return this;
        }
        Nodo **ptr_current = &(lista->sgte);
        for(;*ptr_current != NULL && (*ptr_current)->key <= nodo->key; ptr_current = &((*ptr_current)->sgte));
        nodo->sgte = *ptr_current;
        *ptr_current = nodo;
        return this;            
    }
};
template <typename T>
class Vector
{
private:
    T data;
    Vector *sgte;
    Size tamanho;
    Size capacidad;
public:
    Vector(Size size = 0): sgte(NULL), tamanho(0), capacidad(0)
    {
        if (size >0){
            Vector** ptr_Sig = &sgte;
            for (int i = 0; i<size; i++){
                Vector *v = new Vector;
                *ptr_Sig = v;
                ptr_Sig = &(v->sgte);
                capacidad++;
            }
        }
    };
    Vector* insert(Size pos, T data)
    {
        Vector *vec = new Vector;
        vec->data = data;
        if (pos = 0){
            vec->sgte = this;
            return vec;
        }
        Vector **ptr_cur = &(this->sgte);
        int i;
        for(i=1; i <= capacidad && i != pos;i++){
             ptr_cur = &((*ptr_cur)->sgte);
        }
        if (i == pos){
            vec->sgte = *ptr_cur;
            *ptr_cur = vec;
        }
        else{// i > capacidad            
            for(int posi=capacidad+1; posi != pos; posi++){
                Vector *vec2 = new Vector;
                *ptr_cur = vec2;
                ptr_cur = &((*ptr_cur)->sgte);
            }
            *ptr_cur = vec;
            return this;
        }
        
        
        
        
    }
};

int main(void)
{
    
    Lista_E le;
    
    Data data;
    le.insert(0,&data)->insert(13,&data)->insert(8,&data)->insert(-7,&data)->insert(18,&data)->insert(8,&data);
    
    //cout<< (le.lista)->sgte->sgte->key;
    
    le.print();
   
    Vector<int> vec(4);
    Data d;
    vec.insert(3,d);

    
    
    
    return 0;
}
