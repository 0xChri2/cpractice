#ifndef CDSHOP_CATEGORY_H
#define CDSHOP_CATEGORY_H

class category{
protected:
    int _baseprice;
    int _loanlen;
    int _penaltyfee;
public:
    category(int baseprice, int loanlen, int penaltyfee);
    ~category();
    virtual int price(int days) = 0;
};

#endif //CDSHOP_CATEGORY_H
