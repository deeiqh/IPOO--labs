#include <iostream>
#include "geometry.h"
using namespace std;

void printAttributes ( Polygon *); 

int main(void)
{
    cout << " Coordenadas de rectangulo, ll y ur: " ;
    int llx , lly , urx , ury ;
    cin >> llx >> lly >> urx >> ury ;
    Point ll ( llx , lly ) , ur ( urx , ury ) ;
    
    Rectangle rect ( ll , ur ) ;
    
    printAttributes (&rect ) ;
    
    cout << " Coordenadas del triángulo: " ;
    int x1 , y1 , x2 , y2 , x3 , y3 ;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 ;
    Point p1 ( x1 , y1 );
    Point p2 ( x2 , y2 );
    Point p3 ( x3 , y3 );
    Triangle tri (p1 , p2 , p3 ) ;
    printAttributes (&tri) ;
   

    return 0;
}

void printAttributes ( Polygon * ptr) 
{
    cout << "Área: " << ptr->area() << '\n';
    cout << "Puntos :\n";
    const PointArray * pa = ptr-> getPoints () ;
    for ( int i = 0; i < pa-> get_size() ; i++) 
        cout << " ( " << pa-> get ( i ) -> getX () << " , " << pa-> get ( i ) -> getY () << " )\n" ;

}
