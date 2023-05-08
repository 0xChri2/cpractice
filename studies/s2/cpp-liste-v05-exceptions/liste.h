#ifndef V03_CPP_LISTE_LISTE_H
#define V03_CPP_LISTE_LISTE_H

#include <iostream>

using namespace std;

class Liste {
// von außen nicht sichtbar aber intern nutzbar
private:
    int _size, _next;
    int *_values;
    char _error;
    bool isFull(); // neuer Datentyp

    int find(int value);
    void increase();
    void decrease();

// von außen sichtbar
public:
    Liste(int size); // Konstruktor statt create
    ~Liste(); // Destruktor statt destroy

    int getSize();
    void append(int val);
    int getValueAt(int pos);
    void erase(int val);
    void toScreen();
    char getError();
    Liste operator+(Liste & lst);
    int operator[](int pos);
    friend ostream& operator<<(ostream& out,Liste & lst);
};

#endif //V03_CPP_LISTE_LISTE_H
