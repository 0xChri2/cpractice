#include "account.h"

void account::withdraw(double amount , date d ){
    if(_accountbalance - amount) {
        _accountbalance = _accountbalance - amount;
    } else {
        throw std::runtime_error("Insufficient funds");
    }
}

void account::deposit (double amount , date d ){
    _accountbalance += amount;
}

double account::accountbalance() const{
    return _accountbalance;
}

string account::accountstatement (){
    //to do
}

void account::transfer( string accountnr , double amount , date d ){

}