#include <iostream>
#include "sale.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

using namespace std;

map<int, sale> extract(const string filename){
    map<int, sale> saledata;

    ifstream file(filename);
    if(!file){
        cerr << "Fehler beim Öffnen der Datei" << endl;
        return saledata;
    } else {
        string line;
        while (getline(file, line)) {
            std::istringstream iss(line);
            string car;
            int date, sales;
            if (iss >> date >> car >> sales) {
                saledata[date] = sale(date, car, sales);
            } else {
                std::cerr << "Ungültiges Format in der Datei: " << line << std::endl;
            }
        }
        return saledata;
    }


}


int main() {
    // Neue Aufgabe mit file extractor Aufgabe 10.1
    string filename;
    cout << "Geben Sie den Dateinamen an aus welcher Sie lesen möchten:" << endl;
    cin >> filename;
    try {
        std::map<int, sale> saledata = extract(filename);

        // Sale-Daten ausgeben
        for (const auto& entry : saledata) {
            sale s = entry.second;
            cout << s.tostring();
        }
    } catch (const std::exception& e) {
        std::cerr << "Fehler: " << e.what() << std::endl;
    }


    /* Alte aufgabe
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
    //int year = date / 10000;
    //int month = (date % 10000) / 100;
    //int day = date % 100;
    cout << "Datum: " << s1.getdate() << "\n Marke: " << s1.getcar() << "\n sales: " << s1.getsales();

    //delete[] salesArray;
    */
}
