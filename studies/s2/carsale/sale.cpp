#include <iostream>
#include <sstream>
#include "sale.h"

using namespace std;

sale::sale(int date, string car,  int sales){
    _car = car;
    _date = date;
    _sales = sales;
}
sale::~sale(){

}

string sale::getcar() {
    return _car;
}

int sale::getsales() {
    return _sales;
}

int sale::getdate() {
    return _date;
}

string sale::tostring() {
    ostringstream car;
    car << "Datum: " << _date << ", Marke: " << _car << ", Anzahl: " << _sales;
    return car.str();
}