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
    ecar(string brand, string model, int year, double maxspeed, double maxcapacity, double capacitynow, double effizenz);
    ~ecar();
    double getrange();
    double getcurrentcapacity();
    double getmaxcapacity();
    void showinfos() override;

private:
   double _capacitynow;
   double _maxcapacity;
   double _effizenz;
};


ecar::ecar(string brand, string model, int year, double maxspeed,double maxcapacity, double capacitynow, double effizenz) : Car(brand, model, year, maxspeed) {
    _maxcapacity = maxcapacity;
    _capacitynow = capacitynow;
    _effizenz = effizenz;
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

void ecar::showinfos() {
    cout << "Brand: " << _brand << endl;
    cout << "Model: " << _model << endl;
    cout << "Year: " << _year << endl;
    cout << "Speednow: " << Car::_speednow<< endl;
    cout << "Max Speed: " << Car::_maxspeed << endl;
    cout << "Serienummer: " << Car::_serialnumber << endl;
    cout << "Max Kapazität: " << _maxcapacity << endl;
    cout << "Akutelle Kapazität: " << _capacitynow << endl;
    cout << "Effizenz: " << _effizenz << endl;
    cout << "Reichweite: " << ecar::getrange() << endl;

}
#endif //CAR_ELEKTRICCAR_H
