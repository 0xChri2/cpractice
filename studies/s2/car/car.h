#ifndef _CAR_H
#define _CAR_H

#include <string>;

using namespace std;

class Car{
private:
    string _brand;
    string _model;
    string _year;
    double _speednow;
    double _maxspeed;

public:
    Car(string brand, string model, string year, double maxspeed);
    ~Car();
    string getbrand();
    string getmodel();
    string getyear();
    double getspeednow();
    double getmaxspeed();
    double brake(double kmh);
    double acceleration(double kmh);
    void showinfo();
};

#endif