#include <iostream>
#include <string>
/*#include "car.h"
#include "elektriccar.h"*/
#include "vehicle.h"

using namespace std;

int main(){
    vehicle *cars[4];
    cars[0] = new car("VW", "Golf", '2010', 300);
    cars[1] = new car("VW", "Nix", '2010', 300);
    cars[2] = new car("VW", "sd", '2010', 300);
    cars[3] = new ecar("Tesla", "Nix",'2000', 250, 200, 100, 15);

    cars[0]->showinfos();
    cars[1]->showinfos();
    cars[2]->showinfos();
    cars[3]->showinfos();
}