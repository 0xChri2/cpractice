#include <iostream>

using namespace std;

void main()
{
	int Weiche1, Weiche2, Weiche3, Weiche4, Ausgabe;

	cout << "Geben sie die einstellung Weichen an:" << endl;
	cin >> Weiche1 >> Weiche2 >> Weiche3 >> Weiche4;

	Ausgabe = ((Weiche1 == 1 && Weiche1 == 1) ||  ( Weiche1 == 0 && Weiche3 == 1 && Weiche4 =1) || (Weiche1 == 1 && Weiche2 == 0 && Weiche4 ==1) );


	cout << "Ihre Kugel ist in:" << Ausgabe << endl;

}