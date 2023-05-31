#include "account.h"
#ifndef BANK_GIROKONTO_H
#define BANK_GIROKONTO_H

class girokonto : public account{
protected:
    double _dispo;
    double _shallintrest;
public:
    girokonto(double accountbalance, string accountowner, string accountnr, double dispo, double shallintrest) : account(accountbalance, accountowner, accountnr), _dispo(dispo), _shallintrest(shallintrest) {} ;
    ~girokonto(){};
    void withdraw (double amount , date d );
    void deposit (double amount , date d );
    double accountbalance ();
    string accountstatement ();
    void transfer ( string accountnr , double amount , date d );
};

#endif //BANK_GIROKONTO_H
