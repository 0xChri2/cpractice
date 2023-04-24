#ifndef _CAR_H
#define _CAR_H

#include <string>

using namespace std;

class Car{
private:
    string _brand;
    string _model;
    string _year;
    double _speednow;
    double _maxspeed;

    static int _serialnumber;
    int serialnumber;
public:
    Car(string brand, string model, int year, double maxspeed);
    ~Car();
    string getbrand();
    string getmodel();
    int getser();
    string getyear();
    double getspeednow();
    double getmaxspeed();
    double brake(double kmh);
    double acceleration(double kmh);
    void showinfos();
};

#endif