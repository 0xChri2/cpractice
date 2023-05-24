#ifndef CAR_VEHICLE_H
#define CAR_VEHICLE_H
#include <string>
#include <iostream>

using namespace std;

class vehicle{
protected:
    string _brand;
    string _model;
    string _year;
    double _speednow;
    double _maxspeed;

    static int _serialnumber;
    int serialnumber;
public:
    vehicle(string brand, string model, int year, double maxspeed){
        _brand = brand;
        _model = model;
        _year = year;
        _speednow = 0;
        serialnumber = ++_serialnumber;
        _maxspeed = maxspeed;
    }
    ~vehicle();
    string getbrand();
    string getmodel();
    int getser();
    string getyear();
    double getspeednow();
    double getmaxspeed();
    virtual double brake(double kmh) = 0;
    virtual double acceleration(double kmh) = 0;
    virtual void showinfos() = 0;
};
vehicle::~vehicle(){

}
int vehicle::_serialnumber = 0;
string vehicle::getbrand(){
    return _brand;
}
int vehicle::getser(){
    return _serialnumber;
};

string vehicle::getmodel(){
    return _model;
}

string vehicle::getyear(){
    return _year;
}
double vehicle::getspeednow(){
    return _speednow;
}
double vehicle::getmaxspeed(){
    return _maxspeed;
}


class car : public vehicle{
public:
    car(string brand, string model, int year, double maxspeed): vehicle(brand, model, year, maxspeed){
    }
    ~car(){}
    double brake(double kmh){
        if((_speednow - kmh) <= 0){
            _speednow = 0;
        }else{
            _speednow -= kmh;

        }
        return _speednow;
    }
    double acceleration(double kmh){
        if((_speednow + kmh) >= _maxspeed){
            _speednow = _maxspeed;
        }else {
            _speednow += kmh;
        }
        return _speednow;
    }
    void showinfos(){
        cout << "Brand: " << _brand << endl;
        cout << "Model: " << _model << endl;
        cout << "Year: " << _year << endl;
        cout << "Speednow: " << _speednow<< endl;
        cout << "Max Speed: " << _maxspeed << endl;
        cout << "Serienummer: " << _serialnumber << endl;
    }
};


class ecar : public car {
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


ecar::ecar(string brand, string model, int year, double maxspeed,double maxcapacity, double capacitynow, double effizenz) : car(brand, model, year, maxspeed) {
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
    cout << "Speednow: " << car::_speednow<< endl;
    cout << "Max Speed: " << car::_maxspeed << endl;
    cout << "Serienummer: " << car::_serialnumber << endl;
    cout << "Max Kapazität: " << _maxcapacity << endl;
    cout << "Akutelle Kapazität: " << _capacitynow << endl;
    cout << "Effizenz: " << _effizenz << endl;
    cout << "Reichweite: " << ecar::getrange() << endl;

}

#endif //CAR_VEHICLE_H
