#include <iostream>

using namespace std;

void main()
{
	int Zahl1;
	do
	{
		cout << "Geben sie eine Zahl an:"<< endl;
		cin >> Zahl1;



	} 
	while (Zahl1 < 1 || Zahl1 > 20 || Zahl1 == 13);


}
