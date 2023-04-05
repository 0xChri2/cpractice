//
// Created by Christoph Riedel on 05.04.23.
//
#include <iostream>
#include <string>
#include "Car.h"

using namespace std;

Car::Car(string brand, string model, string year, double maxspeed){
    _brand = brand;
    _model = model;
    _year = year;
    _speednow = 0;
    _maxspeed = maxspeed;
}

string Car::getbrand(){
    return _brand;
}

string Car::getmodel(){
    return _model;
}

string Car::getyear(){
    return _year;
}
double Car::getspeednow(){
    return _speednow;
}
double Car::getmaxspeed(){
    return _maxspeed;
}
double Car::brake(double kmh){
    if((_speednow - kmh) <= 0){
        _speednow = 0;
    }else{
        _speednow -= kmh;

    }
    return _speednow;
}
double Car::acceleration(double kmh){
    if((_speednow + kmh) >= _maxspeed){
        _speednow = _maxspeed;
    }else {
        _speednow += kmh;
    }
    return _speednow;
}
void Car::showinfo(){
    cout << "Brand: " << _brand << endl;
    cout << "Model: " << _model << endl;
    cout << "Year: " << _year << endl;
    cout << "Speednow: " << _speednow<< endl;
    cout << "Max Speed: " << _maxspeed << endl;
}

