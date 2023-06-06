#include <iostream>
#include "verleih.h"
#include "cd.h"
#include "kunde.h"
using namespace std;

// *******************************************************************
int menue() {
    cout << "\n\n";
    cout << "+------------------------+\n";
    cout << "| Hauptmenü:             |\n";
    cout << "+------------------------+\n\n";
    cout << "  (1) CD verleihen\n";
    cout << "  (2) CD annnehmen\n";
    cout << "  (3) Kundenliste anzeigen\n";
    cout << "  (4) Kundenausleihe anzeigen\n";
    cout << "  (5) CD-liste anzeigen\n";
    cout << "  (6) Stammdaten-Dialog\n";
    cout << "  (7) Daten aus Datei einlesen\n";
    cout << "  (8) Daten in Datei speichern\n\n";
    cout << "  (9) Programm beenden\n";
    cout << "------------------------------------------------\n";
    cout << " Ihre Auswahl? ";

    int auswahl;
    cin >> auswahl;

    return auswahl;
}

// *******************************************************************
int stammdaten() {
    cout << "\n\n";
    cout << "+------------------------+\n";
    cout << "| Stammdaten-Dialog:     |\n";
    cout << "+------------------------+\n\n";
    cout << " (1) Kunde anlegen\n";
    cout << " (2) Kunde entfernen\n";
    cout << " (3) CD anlegen\n";
    cout << " (4) CD entfernen\n\n";
    cout << " (5) Abbruch\n";
    cout << " -----------------------------------------------\n";
    cout << " Ihre Auswahl?\n";

    int auswahl;
    cin >> auswahl;

    return auswahl;
}

// *******************************************************************
int main() {
    int auswahl, cd, kunde;
    string str, datum;
    Verleih verleih;

    do {
        auswahl = menue();
        if (auswahl == 1) {         // CD verleihen
            // to do ...
        } else if (auswahl == 2) {  // CD annehmen
            // to do ...
        } else if (auswahl == 3) {  // Kundenliste anzeigen
            // to do ...
        } else if (auswahl == 4) {  // Kundenausleihe anzeigen
            // to do ...
        } else if (auswahl == 5) {  // CD-Liste anzeigen
            // to do ...
        } else if (auswahl == 6) {  // Stammdaten-Dialog
            int wahl = stammdaten();
            // to do ...
        } else if (auswahl == 7) {  // Daten einlesen
            // to do ...
        } else if (auswahl == 8) {  // Daten speichern
            // to do ...
        } else if (auswahl != 9) {
            cout << "unbekannte Auswahl\n";
        }
    } while (auswahl != 9);
}

