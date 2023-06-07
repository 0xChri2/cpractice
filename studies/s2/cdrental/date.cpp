#include "date.h"
#include <ctime>

int date::diff(date& other) {
    // Unterschied in Jahren berechnen
    int jahrdiff = other._jahr - _jahr;

    // Überprüfen, ob der Geburtstag im aktuellen Jahr bereits stattgefunden hat
    if (other._monat < _monat || (other._monat == _monat && other._tag < _tag)) {
        jahrdiff--;
    }
    return jahrdiff;
}

void date::settodays(){
   time_t now = time(nullptr);
   tm* currentTime = std::localtime(&now);
    int _tag = currentTime->tm_mday;
    int _monat = currentTime->tm_mon + 1;
    int _jahr = currentTime->tm_year + 1900;

}
