#include <iostream>
#include "verleih.h"
#include "kunde.h"
#include "cd.h"
#include "date.h"


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
    int auswahl, cdm, kund;
    string str, datum;

    date today(1,1,1900);
    today.settodays();

    kunde kunde1("Wolfgang");
    cd cd1("Nix","nix",today, false);
    verleih verleih(&cd1, &kunde1, 0, 0);
    do {
        auswahl = menue();
        if (auswahl == 1) { // CD verleihen
            int cdIndex;
            cout << "Welche CD möchten Sie verleihen? (Index eingeben): ";
            cin >> cdIndex;

            if (cdIndex >= 0 && cdIndex < 10) {
                int kundeIndex;
                cout << "An welchen Kunden möchten Sie die CD verleihen? (Index eingeben): ";
                cin >> kundeIndex;

                if (kundeIndex >= 0 && kundeIndex < 10) {
                    verleih.hinzuCD(*cds[cdIndex]);

                    verleih.hinzuKunde(, kundeIndex);
                } else {
                    cout << "Ungültiger Kundenindex!" << endl;
                }
            } else {
                cout << "Ungültiger CD-Index!" << endl;
            }
        } else if (auswahl == 2) {  // CD annehmen
            cout << "Geben Sie den Index Ihrer CD ein.";
        } else if (auswahl == 3) {  // Kundenliste anzeigen
            cout << verleih.gibKundenliste() << endl;
        } else if (auswahl == 4) {  // Kundenausleihe anzeigen
            cout << "Welcher Kunde für die Ausgeliehen CDs soll ausgegeben werden.";
            int kundenIndex;
            cin >> kundenIndex;
            cout << verleih.gibAusleiheVon(kundenIndex) << endl;
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

