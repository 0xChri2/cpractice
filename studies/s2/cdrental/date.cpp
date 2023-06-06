#include "date.h"


int date::diff(date& other) {
    // Unterschied in Jahren berechnen
    int jahrdiff = other._jahr - _jahr;

    // Überprüfen, ob der Geburtstag im aktuellen Jahr bereits stattgefunden hat
    if (other._monat < _monat || (other._monat == _monat && other._tag < _tag)) {
        jahrdiff--;
    }

    return jahrdiff;
}
