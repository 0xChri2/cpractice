#include <iostream>

using namespace std;

void main()
{
	int Zahl, Quersumme = 0, dual = 0, ZahlQ, ZahlD;


	cout << "Geben sie eine Zahl an:" << endl;
	cin >> Zahl;
	ZahlQ = Zahl * 1;
	ZahlD = Zahl * 1;

	do
	{
		Quersumme = ZahlQ % 10 + Quersumme;
		ZahlQ = ZahlQ / 10;

	} while (ZahlQ > 0);

	cout << "Ihre Quersumme ist:" << Quersumme << endl;

	cout << "Ihre Zahl in Dual ist:" ;

	while (ZahlD > 0){

		dual = ZahlD % 2;
		cout << dual;
		ZahlD = ZahlD / 2;


	} 

	 


}

