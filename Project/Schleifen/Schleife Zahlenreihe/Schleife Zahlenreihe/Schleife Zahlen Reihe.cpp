#include <iostream>

using namespace std;

void main()
{
	int Zahl, Ergebnis = 0;

	
		do
		{
			cout << "Geben sie eine Zahl an:" << endl;
			cin >> Zahl;
			do
			{
				Ergebnis = Ergebnis + 2;
				cout << Ergebnis << endl;
			} while (Ergebnis <= Zahl);

		} 
		while (Ergebnis <= Zahl);


}