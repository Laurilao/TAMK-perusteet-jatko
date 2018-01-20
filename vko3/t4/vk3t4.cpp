#include <iostream>
#include <vector>

using namespace std;

bool prime_all(int);
bool prime_half(int);
bool prime_square_root(int);

int main()
{
	/*do
	{
		cout << "Tarkasta onko luku alkuluku (0 = Lopetus): ";
		cin >> luku;

		if (prime(luku) && luku > 1)
		{
			cout << "Luku on alkuluku" << endl;
		}
		else
		{
			cout << "Luku ei ole alkuluku" << endl;
		}


	} while (luku != 0);*/

	int lkmaara = 0;
	vector<int> aLuvut;
	double prosentti;

	for (int i = 1; i <= 10000; i++)
	{
		if (prime_square_root(i) && i > 1)
		{
			aLuvut.push_back(i);
			lkmaara++;
		}
	}
	
	cout << "Alkulukuja ovat: ";

	for (int i = 0; i != aLuvut.size(); i++)
	{
		cout << aLuvut[i] << ", ";
	}

	prosentti = lkmaara * 100.0 / 10000.0;
	cout << endl << "Alkulukujen lukumaara: " << lkmaara << endl;
	cout << "Prosenttiosuus: " << prosentti << "%" << endl;

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