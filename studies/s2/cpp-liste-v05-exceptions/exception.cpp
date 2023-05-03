#include "exception.h"

using namespace std;

// Konstruktor
Exception::Exception(string error) {
    _error = error;
}

// zur Ausgabe
string Exception::toString() {
    return _error;
}