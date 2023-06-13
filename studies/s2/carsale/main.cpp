#include <iostream>
#include "sale.h"
#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

map<string, sale> extract(const string& filename){
    map<string, sale> data;

    ifstream file(filename);
    if(!file){
        cerr << "Fehler beim Öffnen der Datei" << endl;
        return data;
    }
    string key;
    


}


int main() {
    int count = 0;
    int date, sales;
    string car;
    cout << "Geben Sie die Anzahl der Eingaben an: ";
    cin >> count;
    //sale* salesArray = new sale(date, car, sales);
    for(int i = 0;i < 1;i++) {
        cout << endl << "Geben Sie das Datum an: ";
        cin >> date;
        cout << endl << "Geben Sie die Marke an: ";
        cin >> car;
        cout << endl << "Geben Sie die Verkäufe an: ";
        cin >> sales;
        //salesArray[i] = sale(date, car, sales);

    }
    sale s1(date, car, sales);
    /*int year = date / 10000;
    int month = (date % 10000) / 100;
    int day = date % 100;*/
    cout << "Datum: " << s1.getdate() << "\n Marke: " << s1.getcar() << "\n sales: " << s1.getsales();

    //delete[] salesArray;
}
