#ifndef V05_RATIONAL_RATIONAL_H
#define V05_RATIONAL_RATIONAL_H

#include <iostream>

class Rational {
    friend std::ostream &operator<<(std::ostream &os,
                                    const Rational &x) {
        os << x.zaehler << " / " << x.nenner;
        return os;
    }

private:
    int zaehler, nenner;

    Rational add(const Rational &x) const; // Addition
    Rational sub(const Rational &x) const; // Subtraktion
    Rational mul(const Rational &x) const; // Multiplikation
    Rational div(const Rational &x) const; // Division

    void kehrwert();
    void kuerzen();

public:
    Rational(int z = 1, int n = 1);

    Rational operator-() const;    // Vorzeichen -
    Rational operator+(const Rational &x) const;  // +
    Rational operator-(const Rational &x) const;  // -
    Rational operator*(const Rational &x) const;  // *
    Rational operator/(const Rational &x) const;  // /

    bool operator<(const Rational &x) const;
    bool operator>(const Rational &x) const;
    bool operator==(const Rational &x) const;
    bool operator<=(const Rational &x) const;

    int getZaehler() const;
    int getNenner() const;
};

#endif //V05_RATIONAL_RATIONAL_H
