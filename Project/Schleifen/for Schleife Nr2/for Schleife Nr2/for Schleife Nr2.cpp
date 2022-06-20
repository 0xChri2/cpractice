#include <iostream>

using namespace std;

void main()
{
	int Primzahl;
	int Teiler;

	cout << "Geben sie eine Primzahl an:" << endl;
	cin >> Primzahl;

	

	if (Primzahl > 1 && Primzahl % (Primzahl / 2))
	{

		for (Teiler = 1; Teiler <= Primzahl; Teiler++)
		{
			if (Primzahl  % Teiler == 0)cout << Teiler << endl;

		}
		
	}


}