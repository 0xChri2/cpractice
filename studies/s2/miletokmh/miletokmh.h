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
        void ausgabe(double milen);
        umrechnen(double milen);
    private:
        double miletokmh (double milen);
};



#endif //MILETOKMH_MILETOKMH_H
