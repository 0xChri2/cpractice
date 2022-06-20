#include <iostream>

using namespace std;

void main()
{
	// Eingabe 
	int ErsteZahl;
	int ZweiteZahl;
	int Rest;
	int Ergebnis;

	//Verarbeitung
	cout << "Geben sie die Erste Zahl an:";
		cin >> ErsteZahl;
		cout << "Geben sie die Zweite Zahl an:";
		cin >> ZweiteZahl;
		
		Rest = ErsteZahl % ZweiteZahl;

		cout << "Dies ist ihr Rest des Ergebnisses:" << endl << Rest << endl;



}