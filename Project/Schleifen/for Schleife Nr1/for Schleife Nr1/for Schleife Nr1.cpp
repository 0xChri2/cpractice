#include <iostream>

using namespace std;

void main()

{
	int o = 11;
	int u = 10;


	for (u = 11; u > 0; u--){
		for (o = u - 1; o > -1; o--){
			cout << o << " ";
		}
		cout << endl;
	}

}