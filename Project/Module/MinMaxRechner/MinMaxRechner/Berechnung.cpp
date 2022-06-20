#include <iostream>
using namespace std;

double Minimum(double zahl1, double zahl2, double zahl3)
{	
	double max, min;
	min = zahl1;
	max = zahl2;

	if (zahl1 > zahl2)
	{
		min = zahl2;
		max = zahl1;
	}

	if (max < zahl3)
	{
		max = zahl3;
	}

	if (zahl3 < min)
	{
		min = zahl3;
	}
	return min;
}

double Maximum(double zahl1, double zahl2, double zahl3)
{	
	double max, min;
	min = zahl1;
	max = zahl2;

	if (zahl1 > zahl2)
	{
		min = zahl2;
		max = zahl1;
	}

	if (max < zahl3)
	{
		max = zahl3;
	}

	if (zahl3 < min)
	{
		min = zahl3;
	}
	return max;
}