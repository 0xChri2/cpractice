#include "rational.h"

// Konstruktor wirft ggf . NaN - Ausnahme
Rational::Rational(int z , int n) {
    if (n == 0)
        throw "NaN exception";
    zaehler = z;
    nenner = n;
    kuerzen ();
}

void Rational::kehrwert() {
    int t = zaehler;
    zaehler = nenner;
    nenner = t;
}

void Rational::kuerzen() {
    // Algorithmus nach Euklid
    int r;
    int p = zaehler;
    int q = nenner;
    do {
        r = p % q;
        p = q;
        q = r;
    } while (r != 0);
    zaehler /= p;
    nenner /= p;
}

Rational Rational::add(const Rational &x) const {
    Rational r;
    r.zaehler = zaehler * x.nenner + nenner * x.zaehler;
    r.nenner = nenner * x.nenner ;
    r.kuerzen ();
    return r;
}

Rational Rational::sub(const Rational &x) const {
    Rational r = *this;
    return r . add (-x);
}

Rational Rational::mul(const Rational &x) const {
    return Rational (zaehler * x.zaehler , nenner * x.nenner);
}

Rational Rational::div(const Rational & x) const {
    Rational r = x ;
    r.kehrwert (); // x.kehrwert () würde const verletzen !!
    return mul (r);
}

int Rational::getZaehler() const {
    return zaehler;
}

int Rational::getNenner() const {
    return nenner;
}

Rational Rational::operator-() const {
    return Rational(-zaehler ,nenner);
}

Rational Rational::operator +(const Rational & x) const {
    return add(x);
}

Rational Rational::operator -(const Rational & x) const {
    return sub(x);
}

Rational Rational::operator *(const Rational & x) const {
    return mul(x);
}

Rational Rational::operator /(const Rational & x) const {
    return div(x);
}

bool Rational::operator <(const Rational& x) const {
    return zaehler * x.nenner < nenner * x.zaehler ;
}

bool Rational::operator >(const Rational& x) const {
    return zaehler * x.nenner > nenner * x.zaehler ;
}

bool Rational::operator ==(const Rational& x) const {
    return zaehler * x.nenner == nenner * x.zaehler ;
}

bool Rational::operator <=(const Rational& x) const {
    return * this < x || * this == x ;
}

double Rational::value() const {
    return (double) (zaehler / nenner);
}
