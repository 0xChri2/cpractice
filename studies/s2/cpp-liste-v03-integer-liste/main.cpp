#include <iostream>
#include "liste.h"

using namespace std;

int main(void) {
    Liste l(10);
    for (int i = 1; i < 60; i++)
        l.append(i);

    l.toScreen();

    cout << endl;
    for (int i = 10; i < 60; i++)
        l.erase(i);

    l.toScreen();

    return 0;

}

// Blockende: Destruktor für l wird automatisch aufgerufen


