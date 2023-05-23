#include <iostream>
#include "rational.h"
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

    return 0;
}
