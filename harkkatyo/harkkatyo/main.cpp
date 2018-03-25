#include <iostream>

#include "Helpers.h"
#include "PlayGame.h"


int main()
{
	char peliLauta[LAUDAN_KOKO][LAUDAN_KOKO];
	char ampumaLauta[LAUDAN_KOKO][LAUDAN_KOKO];

	string valinta;
	bool boardIsEmpty = true;

	do
	{
		valinta = PrintMenu();
		SelectedMode(valinta, peliLauta, ampumaLauta, &boardIsEmpty);

	} while (valinta != "l" && valinta != "L");


	system("pause");
	return 0;
}