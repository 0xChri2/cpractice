#include <iostream>
#include <sstream>
#include "sale.h"

using namespace std;

sale::sale(){
    _date = 0;
    _car = "";
    _sales = 0;
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
    car << "Datum: " << _date << ", Marke: " << _car << ", Anzahl: " << _sales << endl;
    return car.str();
}