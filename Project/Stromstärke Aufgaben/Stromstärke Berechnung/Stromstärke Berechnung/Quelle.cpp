#include <iostream>
using namespace std;


void main()
{
	double Spannung;
	double Widerstand;
	double Stromst�rke;

		cout << "Geben sie die Spannung an:"
		cin >> Spannung;
		cout << "Geben sie den Widerstand an:"
		cin >> Widerstand;

		Stromst�rke = Spannung / Widerstand;

		cout << " Die Stromst�rke betr�gt:" << Stromst�rke << endl;


}