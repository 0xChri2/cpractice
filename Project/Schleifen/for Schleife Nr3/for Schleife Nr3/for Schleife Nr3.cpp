#include <iostream>

using namespace std;

void main()
{
	int Batterie;
	char S1, S2, S3, S4, S5, On, Off;
	cout << "Geben Sie an ob die Baterie an (1) oder aus (0)ist:" << endl;
	cin >> Batterie;


	if (Batterie >= 1)
	{
		for (int S1 = 0; !(S1 > 1); S1++)
			for (int S2 = 0; !(S2 > 1); S2++)
				for (int S3 = 0; !(S3 > 1); S3++)
					for (int S4 = 0; !(S4 > 1); S4++)
						for (int S5 = 0; !(S5 > 1); S5++)
							cout << S1 << "  " << S2 << "  " << S3 << "  " << S4 << "  " << S5 << "  " << "Lampe ist:" << ((S1 == 1 && S2 == 1) || (S3 && S5) || (S4 == 1 && S5 == 1) || (S1 == 1 && S2 == 1 && S3 == 1 && S5 == 1) || (S1 == 1 && S2 == 1 && S3 == 1 && S4 == 1 && S5 == 1)) << endl;
	}

	if (Batterie == 0){

		cout << "Leuchtet:" << endl << "Lampe leuchtet nicht" << endl;

	}
	

}
