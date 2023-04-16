//
// Created by Christoph Riedel on 07.04.23.
//

#ifndef MILETOKMH_MILETOKMH_H
#define MILETOKMH_MILETOKMH_H

using namespace std;

class umrechnen{
    public:
        double _milen;
        double _kmh;
        int _anzahl;
        void ausgabe(double milen, int anzahl);
        double miletokmh (double milen, int anzahl);
        umrechnen(double milen, double kmh, double anzahl);
    private:

};



#endif //MILETOKMH_MILETOKMH_H
