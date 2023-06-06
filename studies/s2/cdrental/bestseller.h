#include "category.h"

#ifndef CDSHOP_BESTSELLER_H
#define CDSHOP_BESTSELLER_H

class bestseller : public category{
public:
    bestseller(int baseprice, int loanlen, int penaltyfee);
    ~bestseller();
    virtual int price(int days);
};

#endif //CDSHOP_BESTSELLER_H
