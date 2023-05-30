#include "normal.h"

normal::normal(int baseprice, int loanlen, int penaltyfee): category(baseprice, loanlen, penaltyfee) {}

normal::~normal() {

}

int normal::price(int days) {
    return (_baseprice * days + (days - _loanlen) * _penaltyfee);
}