#include "category.h"

#ifndef CDSHOP_OFFER_H
#define CDSHOP_OFFER_H

class offer : public category{
public:
    offer(int baseprice, int loanlen, int penaltyfee);
    ~offer();
    virtual int price (int days);
};


#endif //CDSHOP_OFFER_H
