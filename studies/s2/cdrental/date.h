
#ifndef BANK_DATE_H
#define BANK_DATE_H

class date {
private:
    int _tag;
    int _monat;
    int _jahr;

public:
    date(int tag, int monat, int jahr) : _tag(tag), _monat(monat), _jahr(jahr) {}
    int diff(date& other);
};
#endif //BANK_DATE_H
