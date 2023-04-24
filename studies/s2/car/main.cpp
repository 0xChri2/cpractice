#include <iostream>
#include <string>
#include "car.h"

using namespace std;

int main(){
    Car au("VW", "Golf", '2010', 300);
    Car a2("VW", "Nix", '2010', 300);
    Car a3("VW", "sd", '2010', 300);
    au.showinfos();
    a2.showinfos();
    a3.showinfos();
}