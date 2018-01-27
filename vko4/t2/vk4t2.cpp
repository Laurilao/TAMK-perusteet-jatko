#include <iostream>

using namespace std;

int aika_sekunneiksi(int*, int*, int*);
void sekunnit_ajaksi(int, int*, int*, int*);

int main()
{
	int tunnit, minuutit, sekunnit, muutettu;

	tunnit = 2;
	minuutit = 46;
	sekunnit = 50;

	muutettu = aika_sekunneiksi(&tunnit, &minuutit, &sekunnit);
	sekunnit_ajaksi(muutettu, &tunnit, &minuutit, &sekunnit);

	cout << "joka on puolestaan " << tunnit << " tuntia " << minuutit << " minuuttia " << sekunnit << " sekuntia." << endl;


	system("pause");
	return 0;
}

int aika_sekunneiksi(int* hh, int* mm, int* ss)
{
	int muutettu = *hh * 3600 + *mm * 60 + *ss;

	cout << *hh << " tuntia " << *mm << " minuuttia " << *ss << " sekuntia on " << muutettu << " sekuntia" << endl;

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