#include "category.h"

#ifndef CDSHOP_NORMAL_H
#define CDSHOP_NORMAL_H

class normal : public category{
public:
    normal(int baseprice, int loanlen, int penaltyfee);
    ~normal();
    virtual int price(int days);
};
#endif //CDSHOP_NORMAL_H
