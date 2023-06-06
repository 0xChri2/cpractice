#include <string>
#include "cd.h"
#include "category.h"
#include "date.h"

#ifndef CDRENTAL_VERLEIH_H
#define CDRENTAL_VERLEIH_H

class verleih{


public:
    void hinzuKunde(kunde k);
    void entferneKunde(int kunde);
    void hinzuCD(cd cd);
    void entferneCD(int cd);
    void verleiheCD(int cd,int kunde,date d);
    int annehmenCD(int cd,int kunde,date d);
    string * gibKundenliste();
    string * gibAusleiheVon(int kunde);
    void gibCDliste();
};

#endif //CDRENTAL_VERLEIH_H
