#include <iostream>

using namespace std;

int main()
{
	int taulukko[10] = { 1,2,3,4,5,6,7,8,3,2 };

	cout << sizeof(taulukko) << " bittia" << endl;
	cout << sizeof(taulukko[0]) << " bittia" << endl;

	for (int i = 0; i < sizeof(taulukko) / sizeof(taulukko[0]); i++)
	{
		cout << taulukko[i] << endl;
	}

	system("pause");
	return 0;
}