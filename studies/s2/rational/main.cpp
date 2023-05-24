#include <iostream>
#include "rational.h"
#include "extrational.h"
using namespace std;

int main (void) {
    Rational a (2) , b (1 , 3) , c ;

    c = a + b;
    cout << " a + b = " << c << endl ;

    c = a - b;
    cout << " a - b = " << c << endl ;

    c = a * b;
    cout << " a * b = " << c << endl ;

    c = a / b;
    cout << " a / b = " << c << endl ;

    if ( a < b )
        cout << " a < b " << endl ;

    if ( a > b )
        cout << " a > b " << endl ;

    if ( a == b )
        cout << " a == b " << endl ;

    cout << "c.zaehler = " << c.getZaehler () << endl ;
    cout << "c.nenner = " << c.getNenner () << endl ;

    extrational d (2) , e (1 , 3) , f ;

    f = d + e;
    cout << " d + e = " << f << endl ;

    f = d - e;
    cout << " d - e = " << f << endl ;

    f = d * e;
    cout << " d * e = " << f << endl ;

    f = d / e;
    cout << " d / e = " << f << endl ;

    if ( d < e )
        cout << " d < e " << endl ;

    if ( d > e )
        cout << " d > e " << endl ;

    if ( d == e )
        cout << " d == e " << endl ;

    cout << "f.zaehler = " << f.getZaehler () << endl ;
    cout << "f.nenner = " << f.getNenner () << endl ;

    return 0;
}
