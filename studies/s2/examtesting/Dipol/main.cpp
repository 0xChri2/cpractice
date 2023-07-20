#include <iostream>
using namespace std;
class complex;

class dipol{
public:
    virtual complex impedance() = 0;

};

class resistor : public dipol{
public:
    resistor(double R);
    complex impedance() override;
};

class inductor : public dipol{
public:
    inductor(double L, double W);
    complex impedance() override;
};

class capacitor : public dipol{
public:
    capacitor(double c, double w);
    complex impedance()override;
};

class serial : public dipol{
protected:
    vector<dipol> components;
public:
    complex impedance() override;
    void append(dipol component);
};

class Parallel : public dipol{
protected:
    vector<dipol> components;
public:
    complex impedance();
    void append(dipol component);
};


int main() {
    resistor r(20);
    capacitor c(2e-6, 1e3);
    Parallel par;
    par.append(&r);
    par.append(&c);

    inductor l(0.2,1e3);
    serial ser;
    ser.append(&l);
    ser.append(&par);
    cout << ser.impedance() << endl;
    return 0;
}
