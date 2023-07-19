#include <iostream>

using namespace std;

int main() {
    double mph = 0.0;
    cout << "Geben Sie bitte die mph an die Sie in km/h umrechenen wollen: " << endl;
    cin >> mph;
    double kmh = mph / 0.621371;
    cout << "MPH = " << mph << " in kmh ist " << kmh << endl;
    return 0;
}
