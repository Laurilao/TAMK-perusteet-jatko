#include <iostream>
#include <vector>

using namespace std;

bool prime_all(int);
bool prime_half(int);
bool prime_square_root(int);
void eratostheneen_seula(int[], int, const int);

int main()
{
	const unsigned int ARVOALUE = 100000;
	int valinta;
	int lkmaara = 0;
	vector<int> aLuvut;

	cout << "Valitse alkulukujen 1 - " << ARVOALUE << " tarkastustapa: " << endl;
	cout << "1) Prime_all (ei toimiva laskutapa)" << endl;
	cout << "2) Prime_half" << endl;
	cout << "3) Prime_square_root" << endl;
	cout << "4) Eratostheneen seula" << endl;
	cout << "Valinta: ";
	cin >> valinta;

	if (valinta == 4)
	{
		// Luo indeksit 0-10000
		int seulottavat[ARVOALUE + 1];

		for (int i = 0; i < ARVOALUE + 1; i++)
		{
			seulottavat[i] = 1;
		}
		eratostheneen_seula(seulottavat, ARVOALUE + 1, ARVOALUE);
	}
	else if (valinta == 1)
	{
		for (int i = 1; i <= ARVOALUE; i++)
		{
			if (prime_all(i) && i > 1)
			{
				aLuvut.push_back(i);
				lkmaara++;
			}
		}
	}
	else if (valinta == 2)
	{
		for (int i = 1; i <= ARVOALUE; i++)
		{
			if (prime_half(i) && i > 1)
			{
				aLuvut.push_back(i);
				lkmaara++;
			}
		}
	}
	else if (valinta == 3)
	{
		for (int i = 1; i <= ARVOALUE; i++)
		{
			if (prime_square_root(i) && i > 1)
			{
				aLuvut.push_back(i);
				lkmaara++;
			}
		}
	}

	if (valinta == 1 || valinta == 2 || valinta == 3)
	{
		cout << "Alkulukuja ovat: ";

		for (int i = 0; i != aLuvut.size(); i++)
		{
			cout << aLuvut[i] << ", ";
		}

		double prosentti = lkmaara * 100.0 / (double)ARVOALUE;
		cout << endl << "Alkulukujen lukumaara: " << lkmaara << endl;
		cout << "Prosenttiosuus: " << prosentti << "%" << endl;
	}

	system("pause");
	return 0;
}

bool prime_half(int luku)
{
	bool onAluku = true;

	for (int i = 2; i <= luku / 2; i++)
	{
		if (luku % i == 0)
		{
			onAluku = false;
			return onAluku;
		}
	}
	return onAluku;
}

bool prime_all(int luku)
{
	bool onAluku = true;

	for (int i = 2; i <= luku - 1; i++)
	{
		if (luku % 1 == 0)
		{
			onAluku = false;
			return onAluku;
		}
	}
	return onAluku;
}

bool prime_square_root(int luku)
{
	bool onAluku = true;

	for (int i = 2; i <= sqrt(luku); i++)
	{
		if (luku % i == 0)
		{
			onAluku = false;
			return onAluku;
		}
	}
	return onAluku;
}

void eratostheneen_seula(int luvut[], int koko, const int ARVOALUE)
{
	// 0 ja 1 eivät ole alkulukuja
	luvut[0] = 0;
	luvut[1] = 0;

	int kerroin = 2;
	int lkmaara = 0;

	while (kerroin <= ARVOALUE)
	{
		for (int i = kerroin * 2; i <= ARVOALUE; i += kerroin)
		{
			luvut[i] = 0;
		}
		kerroin++;
	}

	cout << "Alkulukuja ovat: ";

	for (int i = 0; i <= ARVOALUE; i++)
	{
		if (luvut[i] == 1)
		{
			cout << i << ", ";
			lkmaara++;
		}
	}

	cout << endl;

	cout << "Alkulukujen lukumaara: " << lkmaara << endl;
	double prosentti = lkmaara * 100.0 / (double)ARVOALUE;
	cout << "Prosenttiosuus: " << prosentti << "%" << endl;
}