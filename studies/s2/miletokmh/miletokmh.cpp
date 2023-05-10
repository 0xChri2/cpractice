#include <iostream>
#include <string>
#include "miletokmh.h"

using namespace std;

umrechnen::umrechnen(double milen) {
    _milen = milen;
    _kmh = 0;
    _anzahl = 0;
}

double umrechnen::miletokmh(double milen) {
    try {
        if (milen < 0){
            throw string("Fehler: negative Zahl");
        }
    }
    catch (string &e) {
        cout << "Fehler: negative Zahl" << endl;
        return 0;
    }
    double _kmh = milen * 1.609344;
    return _kmh;
}

void umrechnen::ausgabe(double milen) {
    cout << "Meilen: " << milen << endl;
    cout << "KM/H: " << miletokmh(milen) << endl;
}
