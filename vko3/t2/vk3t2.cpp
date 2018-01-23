#include <iostream>

using namespace std;

double integerPower(int, int);

int main()
{
	int kanta, potenssi;

	kanta = 2;
	potenssi = 2;

	cout << "Kanta: " << kanta << ", potenssi: " << potenssi << ", tulos: " << integerPower(kanta, potenssi) << endl;

	kanta = 3;
	potenssi = 3;

	cout << "Kanta: " << kanta << ", potenssi: " << potenssi << ", tulos: " << integerPower(kanta, potenssi) << endl;

	kanta = 3;
	potenssi = 4;

	cout << "Kanta: " << kanta << ", potenssi: " << potenssi << ", tulos: " << integerPower(kanta, potenssi) << endl;

	kanta = 5;
	potenssi = 5;

	cout << "Kanta: " << kanta << ", potenssi: " << potenssi << ", tulos: " << integerPower(kanta, potenssi) << endl;


	system("pause");
	return 0;
}

double integerPower(int kanta, int potenssi)
{
	int tulos = kanta;

	for (int i = 0; i < potenssi - 1; i++)
	{
		tulos = tulos * kanta;
	}

	return tulos;
}