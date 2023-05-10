//
// Created by Christoph Riedel on 10.05.23.
//

#ifndef CAR_ELEKTRICCAR_H
#define CAR_ELEKTRICCAR_H
#include "car.h"
#include <iostream>

using namespace std;

class ecar : public Car {
public:
    ecar(string brand, string model, int year, double maxspeed, ,double maxcapacity, double capacitynow, double effizenz);
    ~ecar();
    double getrange();
    double getcurrentcapacity();
    double getmaxcapacity();
private:
   double _capacitynow;
   double _maxcapacity;
   double _effizenz;
};


ecar::ecar(string brand, string model, int year, double maxspeed, ,double maxcapacity, double capacitynow, double effizenz) : Car(brand, model, year, maxspeed) {
    _maxcapacity = maxcapacity;
    _capacitynow = capacitynow;
    _effizenz = effizenz
}

ecar::~ecar() {}

double ecar::getrange() {
    return (_capacitynow / _effizenz) * 100;
}

double ecar::getcurrentcapacity() {
    return _capacitynow;
}

double ecar::getmaxcapacity() {
    return _maxcapacity;
}


#endif //CAR_ELEKTRICCAR_H
