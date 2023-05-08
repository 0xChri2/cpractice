#include <iostream> // neue Bibliothek
#include "liste.h"
#include "exception.h"

using namespace std; // nutze Namensraum

// Konstruktor
Liste::Liste(int size) {
    _size = size;
    _next = 0;
    _error = 0;
    _values = new int[size]; // statt malloc
}

// Destruktor
Liste::~Liste() {
   // delete[] _values; // statt free
}

void Liste::increase() {
    int *tmp = new int[_size * 2];
    for (int i = 0; i < _size; i++)
        tmp[i] = _values[i];
    delete[] _values;
    _values = tmp;
    _size *= 2;
}

void Liste::append(int val) {
    if (isFull())
        increase();
    _values[_next] = val;
    _next += 1;
}

// new: now with Exception!
int Liste::getValueAt(int idx) {
    if (idx < 0 || idx >= _next)
        throw Exception("out of bounds");
    return _values[idx];
}

int Liste::find(int val) {
    int pos;
    for (pos = 0; pos < _next; pos++)
        if (_values[pos] == val)
            return pos;
    return -1;
}

bool Liste::isFull() {
    return _next == _size;
}

void Liste::decrease() {
    _size /= 2;
    int *tmp = new int[_size];
    for (int i = 0; i < _next; i++)
        tmp[i] = _values[i];
    delete[] _values;
    _values = tmp;
}

void Liste::erase(int val) {
    int pos = find(val);
    if (pos == -1)
        return;
    for (; pos < _next - 1; pos++)
        _values[pos] = _values[pos + 1];
    _next -= 1;
    if (_next < _size / 4)
        decrease();
}

void Liste::toScreen() {
    for (int i = 0; i < _next; i++)
        cout << i << " : " << _values[i] << endl;
}

char Liste::getError() {
    return _error;
}

int Liste::getSize() {
    return _size;
}

Liste Liste::operator+(Liste & lst){
    Liste result(*this);
    for(int i = 0;i<=lst._size; i++){
        append(lst._values[i]);
    }
    return result;
}

int Liste::operator[](int pos){
    if (pos < 0 || pos >= _size) {
        throw out_of_range("Index out of range");
    }
    return _values[pos];
}

ostream& operator<<(ostream& out,Liste & lst){
    for(int i = 0;i<= lst.getSize(); i++){
        cout << i + 1 << " : " << lst.getValueAt(i) << endl;
    }
    return out;
}
