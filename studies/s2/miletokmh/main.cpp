#include <iostream>
#include "miletokmh.h"

using namespace std;

int main() {
    double kmh, miles, anzahl =0;
    cout << "Geben sie die Meilen an die Sie umrechnen wollen: " <<  endl;
    cin >> miles;
    umrechnen um(miles);
    um.ausgabe(miles);
    return 0;
}
