#include <iostream>
#include <string>
#include "car.h"
#include "elektriccar.h"

using namespace std;

int main(){
    Car au("VW", "Golf", '2010', 300);
    Car a2("VW", "Nix", '2010', 300);
    Car a3("VW", "sd", '2010', 300);
    ecar a4("Tesla", "Nix",'2000', 250, 200, 100, 15);
    au.showinfos();
    a2.showinfos();
    a3.showinfos();
    a4.showinfos();
}