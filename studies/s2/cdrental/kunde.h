#include "cd.h"
#include <string>

using namespace std;

#ifndef CDRENTAL_KUNDE_H
#define CDRENTAL_KUNDE_H

class kunde{
protected:
    string _name;
public:
    kunde(string name) : _name(name) {};
    ~kunde(){};
    void ausleihen(int cd);
    void rueckgabe(int cd);
    string * gibCDliste();
};

#endif //CDRENTAL_KUNDE_H
