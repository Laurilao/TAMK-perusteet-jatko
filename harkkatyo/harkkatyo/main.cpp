#include <iostream>

#include "Helpers.h"
#include "PlayGame.h"


int main()
{
	char peliLauta[LAUDAN_KOKO][LAUDAN_KOKO];
	Alusta(peliLauta);
	char ampumaLauta[LAUDAN_KOKO][LAUDAN_KOKO];
	Alusta(ampumaLauta);

	string valinta;

	do
	{
		valinta = PrintMenu();
		SelectedMode(valinta, peliLauta, ampumaLauta);

	} while (valinta != "l" && valinta != "L");

	TulostaLauta(peliLauta, 7, 7);

	system("pause");
	return 0;
}