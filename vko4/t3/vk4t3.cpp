#include <iostream>
#include <iomanip>

using namespace std;

struct aika_ty
{
	int hh;
	int mm;
	int ss;
} ;


int main()
{
	aika_ty aika;

	do
	{
		cout << "Anna tunnit: ";
		cin >> aika.hh;

		if (aika.hh < 0 || aika.hh > 23)
		{
			cout << "Virheellinen syote, yrita uudelleen..." << endl;
		}
	} while (aika.hh < 0 || aika.hh > 23);
		
	do
	{
		cout << "Anna minuutit: ";
		cin >> aika.mm;

		if (aika.mm < 0 || aika.mm > 60)
		{
			cout << "Virheellinen syote, yrita uudelleen..." << endl;
		}
	} while (aika.mm < 0 || aika.mm > 60);
	
	do
	{
		cout << "Anna sekunnit: ";
		cin >> aika.ss;

		if (aika.ss < 0 || aika.ss > 60)
		{
			cout << "Virheellinen syote, yrita uudelleen..." << endl;
		}
	} while (aika.ss < 0 || aika.ss > 60);


	cout << "Aika: ";
	cout << setfill('0') << setw(2) << aika.hh << ":";
	cout << setfill('0') << setw(2) << aika.mm << ":";
	cout << setfill('0') << setw(2) << aika.ss << endl;

	system("pause");
	return 0;
}