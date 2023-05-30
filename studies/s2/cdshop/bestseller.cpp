#include "bestseller.h"

bestseller::bestseller(int baseprice, int loanlen, int penaltyfee): category(baseprice,loanlen,penaltyfee) {}
bestseller::~bestseller() {}

int bestseller::price(int days) {
    return _baseprice * days;
}