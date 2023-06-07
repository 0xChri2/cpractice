#include <string>
#include <iostream>
#include "cd.h"
#include "category.h"
#include "date.h"
#include "kunde.h"

#ifndef CDRENTAL_VERLEIH_H
#define CDRENTAL_VERLEIH_H

class verleih{
protected:
    kunde* _akunde[10];
    cd* _acd[10];
public:
    verleih(kunde& akunde, cd& acd, int kundennr, int cdnummer) {
    _akunde[kundennr] = &akunde;
    _acd[cdnummer] = &acd;
    };
    ~verleih(){};
    void hinzuKunde(kunde& k, int kundennr);
    void entferneKunde(int kunde);
    void hinzuCD(cd cd, int cdnummer);
    void entferneCD(int cd);
    void verleiheCD(int cd,int kunde,date d);
    int annehmenCD(int cd,int kunde,date d);
    string * gibKundenliste();
    string * gibAusleiheVon(int kunde);
    void gibCDliste();
};

#endif //CDRENTAL_VERLEIH_H
