//
// Created by Christoph Riedel on 07.04.23.
//
#include <iostream>
#include <string>
#include "miletokmh.h"

using namespace std;

umrechnen::umrechnen(double milen, double kmh, double anzahl) {
    milen = _milen;
    kmh = _kmh;
    anzahl = _anzahl;
}

double umrechnen::miletokmh(double milen, int anzahl) {
    double kmh = milen * 1.609344;

}

void umrechnen::ausgabe(double milen, int anzahl) {
    
}