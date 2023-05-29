#ifndef CDSHOP_CATEGORY_H
#define CDSHOP_CATEGORY_H

class category{
    int _baseprice;
    int _loanlen;
    int _penaltyfee;
    category();
    ~category();
    virtual int price(int days);
};

#endif //CDSHOP_CATEGORY_H
