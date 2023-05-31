#include "Girokonto.h"
#include <iostream>
#include <string>

using namespace std;


void girokonto::withdraw(double amount , date d ){
    if((_accountbalance - amount) >= _dispo) {
        _accountbalance = _accountbalance - amount;
    } else {
        throw std::runtime_error("Insufficient funds");
    }
}