#include <iostream>
#include <vector>
#define minimo(x, y) (x<y ? x:y)

using namespace std;
typedef unsigned int Size;

template <typename T>
T min(const T a, const T b)
{
    if (a<b) return a;
    return b;
}

template <typename T>
class Stack
{
private:
    friend Stack <T> operator+( const Stack <T> &s1 , const Stack <T> & s2);
    vector <T> elementos ;
public :
    bool empty () const
    {
        return elementos.empty();
    }
    void push( const T &e )
    {
        elementos.push_back ( e );
    }
    T pop () {
        T u = elementos.back ();
        elementos.pop_back ();
        return u;
    }
};

template < typename T>
Stack <T> operator+( const Stack <T> &s1 , const Stack <T> &s2)
{
    Stack <T> r = s1;
    for ( Size i = 0; i < s2.elementos.size(); ++i) {
        r.elementos.push_back(s2.elementos[i]);
    }
    return r ;
}
//////////////////grafo
class Graph
{
protected :
    map <int , vector <int > > mapa ;

public :
    Graph ( const vector <int > &origen , const vector <int > &destino )
    {
        for( Size i = 0; i < origen.size (); i++ ) {
            int o = origen[i];
            int d = destino[i];
            mapa[o].push_back(d);
        }
    }

    const vector <int > &adyacente( const int key ) const
    {
        map <int,vector <int > >:: const_iterator it = mapa.find(key);
        if(it !=  mapa.end()) {
            return it-> second ;
        }
        cerr << "No hay nodo";
    }

    int cant_nodos (const int key ) const {
        return adyacente(key).size();
    }
};
////////////////////////
int main()
{
    //static_cast<Triangle *> (p)
    return 0;
}

