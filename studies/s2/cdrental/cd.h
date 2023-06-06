#include <string>
#include <iostream>
#include "date.h"
#include "category.h"

using namespace std;

#ifndef CDRENTAL_CD_H
#define CDRENTAL_CD_H

class cd {
protected:
    string _title;
    string _interpreter;
    date _ausleihen;
    bool _verliehen;
public:
    cd(string title, string interpreter, date ausleihen, bool verliehen) : _title(title), _interpreter(interpreter), _ausleihen(ausleihen), _verliehen(verliehen) {};
    ~cd(){};
    void verleihen(date tag);
    int preis(date heute);
    string beschreibung();
    void setzeKategorie(category *kat);
    bool istVerliehen();
};

#endif //CDRENTAL_CD_H
