#include <iostream>
#include "Eingabe.h"
#include "Ausgabe.h"
#include "Berechnung.h"
using namespace std;


void main()
{
	double zahl1, zahl2, zahl3;

	double min, max;
	
	zahl1 = Einlesen(1);
	zahl2 = Einlesen(2);
	zahl3 = Einlesen(3);

	min = Minimum(zahl1, zahl2, zahl3);
	max = Maximum(zahl1, zahl2, zahl3);

	Ausgabe( min, max);
}