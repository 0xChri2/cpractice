#include <string>
#include <iostream>
#include "date.h"

using namespace std;

#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H


class account{
protected:
    double _accountbalance;
    string _accountowner;
    string _accountnr;
public:
    account(double accountbalance, string accountowner, string accountnr) : _accountbalance(accountbalance), _accountowner(accountowner), _accountnr(accountnr) {};
    ~account() {};
    virtual void withdraw (double amount , date d );
    void deposit (double amount , date d );
    double accountbalance () const;
    string accountstatement();
    virtual void transfer( string accountnr , double amount , date d ) = 0;
};

#endif //BANK_ACCOUNT_H
