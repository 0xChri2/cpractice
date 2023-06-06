#include "offer.h"

offer::offer(int baseprice, int loanlen, int penaltyfee) : category(baseprice,loanlen,penaltyfee) {}
offer::~offer() {}

int offer::price(int days) {
    if(_penaltyfee == 0){
        return _baseprice * _loanlen;
    } else {
        return _penaltyfee * days;
    }
}