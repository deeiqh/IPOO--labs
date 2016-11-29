#include <iostream>
#include <vector>
#include <map>
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
class Stack;

template < typename T>
Stack <T> operator+( const Stack <T> &s1 , const Stack <T> &s2)
{
    Stack <T> r = s1;
    for ( Size i = 0; i < s2.elementos.size(); ++i) {
        r.elementos.push_back(s2.elementos[i]);
    }
    return r ;
}


template <typename T>
class Stack
{
private:
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

    friend Stack <T> operator+( const Stack <T> &s1 , const Stack <T> &s2);
};

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
    Stack<int> pila;
    pila.push(0);
    pila.pop();
    if(pila.empty()) cout << "Bien\n";

    pila.push(1);
    pila.push(2);
    Stack<int> pila2;
    pila2.push(3);
    pila2.push(4);
    Stack<int> pila3;

    pila3 = pila + pila2;
    cout << pila3.pop();
    cout << pila3.pop();


    vector<int> start;
    start.insert(start.begin(), 3,1);
    start.insert(++++++(start.begin()), 2,5);
    start.push_back(4);

    vector<int> endd;
    endd.push_back(2);
    endd.push_back(3);
    endd.push_back(4);
    endd.push_back(4);
    endd.push_back(2);
    endd.push_back(2);

    Graph g(start, endd);
    cout << g.cant_nodos(1 ) << '\n';
    vector<int> ad = g.adyacente(1);
    for(vector<int>::iterator it = ad.begin(); it != ad.end(); it++){
        cout << *it << ' ';
    }
    cout << '\n';

    //static_cast<int> g;

    //static_cast<Triangle *> (p) (double) int
    //dynamic_cast<Triangle *> (p)

    return 0;
}
