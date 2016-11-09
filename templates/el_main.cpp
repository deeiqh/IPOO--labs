#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>

class Punto
{
private:
    T x, y;
public:
    Punto(T x = 0, T y = 0): x{x}, y{y} {};
    T get_X()
    {
        return x;
    }
    T get_Y()
    {
        return y;
    }
    void set_X( T num)
    {
        x = num;
    }
    void set_Y(T num)
    {
        y = num;
    }
    Punto operator+(Punto &p_2)
    {
        Punto p_3;
        p_3.set_X(p_2.get_X());
        p_3.set_Y(p_2.get_Y());
        return p_3;
    }
    ostream& operator<<(ostream &output)
    {
        output << '(' << x << ", " <<y << ')';
        return output;
    }
    bool operator<(const Punto &punto) const//*1 orden segun elemento x, para que funcionen inset en sets.
    {
        return x < punto.x;
    }
};
        

int main(void)
{
    Punto<int> p_1(1,2);
    Punto<int> p_2(3,4);
    Punto<int> p_3 = p_1 + p_2;
    
    p_3 << cout;
    
    
    vector< Punto<float> > vec1;
    vec1.reserve(1);
    cout << vec1.size();

    Punto<float> p(1.0,1.0);
    vec1.insert(vec1.begin(),p);//asi se inserta en un vector
    cout << vec1.size();
    
    set< vector< Punto<float> > > c;
    c.insert(vec1); //*1 los elementos del conjunto deben guardar orden, para que esto se pueda
                    // hacer se requiere que vector tenga un orden(sus elementos)
    cout << c.size();
    cout << vec1.size();
    cout << c.begin()->size();
       
    vector <Punto <float>> vee (*c.begin());
    cout << vee.size();
    
    Punto <float> pt;
    pt = vee[0];
    
    pt << cout;
    return 0;
}
