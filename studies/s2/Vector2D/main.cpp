#include <iostream>
#include "vector2d.h"

using namespace std;

int main() {
    vector2d x1(1.00,2.00);
    vector2d x2(2.00,1.00);

    vector2d result = x1 + x2;
   cout << result << endl;
   int Zahl = x1 * x2;
   cout << "Zahl: " << Zahl;
   x1.turn(12.00);
   cout << endl << x1;
}
