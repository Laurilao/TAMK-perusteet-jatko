#include <iostream>

using namespace std;

void sekunnit_ajaksi(int, int*, int*, int*);

int main()
{
	int syote, tunnit, minuutit, sekunnit;

	cout << "Anna aika sekunteina: ";
	cin >> syote;

	sekunnit_ajaksi(syote, &tunnit, &minuutit, &sekunnit);

	cout << syote << " sekuntia on " << tunnit << " tuntia " << minuutit << " minuuttia " << sekunnit << " sekuntia." << endl;


	system("pause");
	return 0;
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