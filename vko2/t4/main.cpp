#include <iostream>
#include <string>

using namespace std;

string tulostaValikko();

void tehtava1();
void printAlaosa(int);
void printYlaosa(int);

void tehtava2();
void printResult(double, double, double, double);

void tehtava3();
void kysyTiedot(string*, string*);

int main()
{
	string valinta;

	do
	{
		valinta = tulostaValikko();

		if (valinta == "a")
		{
			tehtava1();
		}
		else if (valinta == "b")
		{
			tehtava2();
		}
		else if (valinta == "c")
		{
			tehtava3();
		}
		else
		{
			cout << "Virheellinen valinta" << endl;
		}

	} while (valinta.compare("d") != 0);

	return 0;
}

string tulostaValikko()
{
	string merkki;

	cout << endl;
	cout << "a: Tehtava 1" << endl;
	cout << "b: Tehtava 2" << endl;
	cout << "c: Tehtava 3" << endl;
	cout << "d: Lopetus" << endl;

	cout << "Anna merkki: ";
	getline(cin, merkki);

	return merkki;
}

void tehtava1()
{
	int tahdet;

	cout << "Anna tahtien maksimimaara : ";
	cin >> tahdet;

	printYlaosa(tahdet);
	printAlaosa(tahdet);

	cin.ignore();
	return;
}

void tehtava2()
{
	double a, b, c, x;

	cout << "Anna arvo a: ";
	cin >> a;
	cout << "Anna arvo b: ";
	cin >> b;
	cout << "Anna arvo c: ";
	cin >> c;
	cout << "Anna arvo x: ";
	cin >> x;

	printResult(a, b, c, x);

	cin.ignore();
	return;
}

void tehtava3()
{
	string nimi, ika;

	kysyTiedot(&nimi, &ika);

	cout << "Nimesi: " << nimi << endl;
	cout << "Ikasi: " << ika << endl;

	return;
}

void printAlaosa(int tahdet)
{
	int loop = 2;
	for (int i = 0; i < tahdet - 1; i++)
	{
		for (int j = 0; j < loop; j++)
		{
			cout << "*";
		}
		loop++;
		cout << endl;
	}
	return;
}
void printYlaosa(int tahdet)
{
	int loop = tahdet;
	for (int i = 0; i < tahdet; i++)
	{
		for (int j = 0; j < loop; j++)
		{
			cout << "*";
		}
		loop--;
		cout << endl;
	}
	return;
}
void printResult(double a, double b, double c, double x)
{
	double y = a * pow(x, 2) + b * x + c;

	cout << "Y-arvo: " << y << endl;

	return;
}
void kysyTiedot(string* nimi, string* ika)
{
	cout << "Anna etunimesi: ";
	getline(cin, *nimi);
	cout << "Anna ikasi: ";
	getline(cin, *ika);

	return;
}