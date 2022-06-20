#include <iostream>
using namespace std;


void main()
{
	double Spannung;
	double Widerstand;
	double Stromstärke;

		cout << "Geben sie die Spannung an:"
		cin >> Spannung;
		cout << "Geben sie den Widerstand an:"
		cin >> Widerstand;

		Stromstärke = Spannung / Widerstand;

		cout << " Die Stromstärke beträgt:" << Stromstärke << endl;


}