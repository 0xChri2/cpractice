#include <Iostream>

using namespace std;

void main()
{
	double Kapital;
	double Prozentsatz;
	double Zinsen;
	char Auswahl;

	cout << "Geben sie entwerder K, P oder Z an (K = Kapital, P = Prozentsatz und Z = Zinsen):" << endl;
	cin >> Auswahl;

	if (Auswahl == 'K')
	{
		cout << "Geben sie ihren Prozentsatz:" << endl;
			cin >> Zinsen;
		cout << "Geben sie ihre Zinsen an:" << endl;
			cin >> Prozentsatz;
				Kapital = Zinsen / Prozentsatz * 100;
		cout << "Ihr Kapital ist:" << Kapital << endl;
	}

	else if (Auswahl == 'P')
	{
		cout << "Geben sie ihr Kapital an:" << endl;
			cin >> Kapital;
		cout << "Geben sie ihre Zinsen an:" << endl;
			cin >> Zinsen;
				Prozentsatz = Kapital / Zinsen * 100;
		cout << "Ihr Prozentsatz ist:" << Prozentsatz << endl;
	}

	else if (Auswahl == 'Z')
	{
		cout << "Geben sie ihr Kapital an:" << endl;
			cin >> Kapital;
		cout << "Geben sie den Prozentsatz an:" << endl;
			cin >> Prozentsatz;
				Zinsen = Kapital * Prozentsatz / 100;
		cout << "Ihre Zinsen sind:" << Zinsen << endl;
	}

	else
	{
		cout << "Ihre Eingabe ist Fehlerhaft nach drücken einer Taste wird das Programm beendet" << endl;
	}

}