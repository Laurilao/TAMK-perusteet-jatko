#include <iostream>

using namespace std;

struct aika_ty
{
	int hh;
	int mm;
	int ss;
} aika1, aika2;

aika_ty KysyAika();
aika_ty aikojen_erotus(aika_ty, aika_ty);
int aika_sekunneiksi(int*, int*, int*);
void sekunnit_ajaksi(int, int*, int*, int*);

int main()
{
	cout << "Ajankohta 1" << endl;
	aika1 = KysyAika();

	cout << "Ajankohta 2" << endl;
	aika2 = KysyAika();

	aika_ty erotus = aikojen_erotus(aika1, aika2);

	cout << "Aikojen erotus on " << erotus.hh << " tuntia " << erotus.mm << " minuuttia " << erotus.ss << " sekuntia." << endl;


	system("pause");
	return 0;
}

aika_ty aikojen_erotus(aika_ty aika1, aika_ty aika2)
{
	aika_ty erotus;

	int aika1_sekunteina = aika_sekunneiksi(&aika1.hh, &aika1.mm, &aika1.ss);
	int aika2_sekunteina = aika_sekunneiksi(&aika2.hh, &aika2.mm, &aika2.ss);
	int sek_ero;

	if (aika1_sekunteina > aika2_sekunteina)
	{
		sek_ero = aika1_sekunteina - aika2_sekunteina;
	}
	else
	{
		sek_ero = aika2_sekunteina - aika1_sekunteina;
	}

	sekunnit_ajaksi(sek_ero, &erotus.hh, &erotus.mm, &erotus.ss);

	return erotus;
}

aika_ty KysyAika()
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

	return aika;
}

int aika_sekunneiksi(int* hh, int* mm, int* ss)
{
	int muutettu = *hh * 3600 + *mm * 60 + *ss;

	//cout << *hh << " tuntia " << *mm << " minuuttia " << *ss << " sekuntia on " << muutettu << " sekuntia" << endl;

	return muutettu;
}

void sekunnit_ajaksi(int sek, int* hh, int* mm, int* ss)
{
	*hh = sek / 3600;
	sek -= *hh * 3600;

	*mm = sek / 60;
	sek -= *mm * 60;

	*ss = sek;

	return;
}