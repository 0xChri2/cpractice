#ifndef RATIONAL_EXTRATIONAL_H
#define RATIONAL_EXTRATIONAL_H
#include "rational.h"
#include <iostream>
#include <cmath>

class extrational : public Rational{
private:
    double zaehler, nenner;
public:
    extrational(double z = 1, double n = 1){
        zaehler = z;
        nenner = n;
    }
    ~extrational(){}
    double getZaehler() const{
        return zaehler;
    }
    double getNenner() const{
        return nenner;
    }
    void kehrwert() {
        double t = zaehler;
        zaehler = nenner;
        nenner = t;
    }
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, std::fmod(a, b));
    }
    void kuerzen() {
        double ggT = gcd(zaehler, nenner);

        // Kürzen von Zähler und Nenner
        zaehler /= ggT;
        nenner /= ggT;
    }
    extrational add(const extrational &x) const {
        extrational r;
        r.zaehler = zaehler * x.nenner + nenner * x.zaehler;
        r.nenner = nenner * x.nenner ;
        r.kuerzen ();
        return r;
    }
    extrational sub(const extrational &x) const {
        extrational r = *this;
        return r . add (-x);
    }

    extrational mul(const extrational &x) const {
        return extrational (zaehler * x.zaehler , nenner * x.nenner);
    }

    extrational div(const extrational & x) const {
        extrational r = x ;
        r.kehrwert (); // x.kehrwert () würde const verletzen !!
        return mul (r);
    }
    extrational operator+(const extrational &x) const{
        return add(x);
    }
    extrational operator-() const {
        return extrational(-zaehler ,nenner);
    }


    extrational operator -(const extrational & x) const {
        return sub(x);
    }

    extrational operator *(const extrational & x) const {
        return mul(x);
    }

    extrational operator /(const extrational & x) const {
        return div(x);
    }
};

#endif //RATIONAL_EXTRATIONAL_H
