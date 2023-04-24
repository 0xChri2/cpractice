#include <iostream>
#include <string>
#include "car.h"

using namespace std;

int Car::_serialnumber = 0;

Car::Car(string brand, string model, int year, double maxspeed){
    _brand = brand;
    _model = model;
    _year = year;
    _speednow = 0;
    serialnumber = ++_serialnumber;
    _maxspeed = maxspeed;
}

Car::~Car(){

}

string Car::getbrand(){
    return _brand;
}
int Car::getser(){
    return _serialnumber;
};

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
void Car::showinfos(){
    cout << "Brand: " << _brand << endl;
    cout << "Model: " << _model << endl;
    cout << "Year: " << _year << endl;
    cout << "Speednow: " << _speednow<< endl;
    cout << "Max Speed: " << _maxspeed << endl;
    cout << "Serienummer: " << _serialnumber << endl;
}

