#include <iostream>
#include "liste.h"
#include "exception.h"

using namespace std;

int main(void) {
    Liste l(10);
    for (int value = 3; value < 8; value++)
        l.append(value);
    try {
        for (int i = 0; i < 8; i++)
            cout << i + 1 << " : " << l.getValueAt(i) << endl;
    } catch (Exception e) {
        cout << e.toString() << endl;
    }
    cout << endl << endl;
    Liste b(10);
    for(int i = 2;i<=8;i++)
        b.append(i);
    try{
        for(int i = 0;i<= 8; i++){
            cout << i + 1 << " : " << l.getValueAt(i) << endl;
        }
    }catch (Exception e){
        cout << e.toString() << endl;
    }
    Liste a = l + b;

    cout << endl << endl;
    try {
        for (int i = 0; i < 20; i++)
            cout << i + 1 << " : " << l.getValueAt(i) << endl;
    } catch (Exception e) {
        cout << e.toString() << endl;
    }
    return 0;
}