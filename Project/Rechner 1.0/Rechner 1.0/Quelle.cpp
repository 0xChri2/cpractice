#include <iostream>
using namespace std;

void main()
{
	double kommazahl1;
	double kommazahl2;
	double Ergebnis1;
	double Ergebnis2;
	double Ergebnis3;

	cout << "Bitte erste Kommauahl eingeben:";
	cin >> kommazahl1;
	cout << "Bitte Zweite Zahl eingeben";
	cin >> kommazahl2;

	Ergebnis1 = kommazahl1 - kommazahl2;
	Ergebnis2 = kommazahl1 * kommazahl2;
	Ergebnis3 = kommazahl1 + kommazahl2;



	cout << "Die Diefferenz ist:" << Ergebnis1 << endl;
	cout << "Das Produkt ist:"	<< Ergebnis2 << endl;
	cout << "Die Summe ist:"	<< Ergebnis3 << endl;
}