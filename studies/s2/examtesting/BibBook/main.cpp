#include <iostream>
#include <string>

using namespace std;

class Buch {
protected:
    string title;
    double basisAusleihGebuehr;
public:
    Buch(string t, double bag): title(t), basisAusleihGebuehr(bag){};
    virtual double ausleihGebuehr(int tage) {
        return (basisAusleihGebuehr * tage);
    };
    virtual string getAusleihZeitraum() {
        return "2 Monate";
    };
};

class Roman : public Buch{
public:
    Roman(string t, double bag) : Buch(t, bag) {}
    double ausleihGebuehr(int tage){
        double result = basisAusleihGebuehr * tage;
        if(result >= 5){
            return 5;
        } else {
            return result;
        }
    };
    string getAusleihZeitraum() {
        return "1 Monat";
    };
};

class Fachbuecher : public Buch{
public:
    Fachbuecher(string t, double bag) : Buch(t, bag) {}
    double ausleihGebuehr(int tage){
        return 2.00;
    };
    string getAusleihZeitraum() {
        return "2 Wochen";
    };
};


    int main() {
        // Erzeugung von Buch-Objekten
        Buch buch("Ein Buch", 3.00);
        Roman roman("Ein Roman", 4.00);
        Fachbuecher fachbuch("Ein Fachbuch", 1.50);

        // Test der ausleihGebuehr()-Funktion
        int ausleihTage = 7;
        cout << "Ausleihgebühr für das Buch: " << buch.ausleihGebuehr(ausleihTage) << endl;
        cout << "Ausleihgebühr für den Roman: " << roman.ausleihGebuehr(ausleihTage) << endl;
        cout << "Ausleihgebühr für das Fachbuch: " << fachbuch.ausleihGebuehr(ausleihTage) << endl;

        // Test der getAusleihZeitraum()-Funktion
        cout << "Ausleihzeitraum für das Buch: " << buch.getAusleihZeitraum() << endl;
        cout << "Ausleihzeitraum für den Roman: " << roman.getAusleihZeitraum() << endl;
        cout << "Ausleihzeitraum für das Fachbuch: " << fachbuch.getAusleihZeitraum() << endl;

        return 0;
    }


