#include "PlayGame.h"
#include "Helpers.h"


void SelectedMode(string valinta, char peliLauta[][LAUDAN_KOKO], char ampumaLauta[][LAUDAN_KOKO], bool* boardIsEmpty)
{
	if (valinta == "1")
	{
		EnterShips(peliLauta, ampumaLauta, boardIsEmpty);
	}
	else if (valinta == "2")
	{
		if (*boardIsEmpty == true)
		{
			cout << "Valitse ensin laivojen sijainnit!" << endl;
		}
		else
		{
			ShootingMode(ampumaLauta, peliLauta, boardIsEmpty);
		}
	}
	else if (valinta == "3")
	{

	}
}

void ShootingMode(char ampumaLauta[][LAUDAN_KOKO], char peliLauta[][LAUDAN_KOKO], bool* boardIsEmpty)
{
	string koords;
	int x, y;
	int shipsLeft = 4;

	do
	{
		PrintShots(ampumaLauta, LAUDAN_KOKO, LAUDAN_KOKO);

		cout << endl << "Anna ampumiskoordinaatti: ";
		getline(cin, koords);

		if (koords == "p" || koords == "P")
		{
			break;
		}

		if (MuunnaKoordinaatti(koords, &x, &y) == 0)
		{
			if (ampumaLauta[x][y] != '0')
			{
				cout << "Kohtaan on jo ammuttu..." << endl << endl;
			}
			else if (peliLauta[x][y] == '0')
			{
				cout << "Laukaus kohtaan " << koords << " ei osunut." << endl << endl;
				ampumaLauta[x][y] = 'x';
			}
			else if (peliLauta[x][y] != '0')
			{
				shipsLeft -= CheckForSink(peliLauta, ampumaLauta, x, y, koords);
			}
		}
		else
		{
			cout << "Virheellinen koordinaatti..." << endl << endl;
		}

		if (shipsLeft == 0)
		{
			PrintShots(ampumaLauta, LAUDAN_KOKO, LAUDAN_KOKO);
			cout << endl << "Onneksi olkoon, voitit!" << endl << endl;
			*boardIsEmpty = true;
		}

	} while (shipsLeft > 0);


}

int CheckForSink(char peliLauta[][LAUDAN_KOKO], char ampumaLauta[][LAUDAN_KOKO], int x, int y, string koords)
{
	int hitCount = 0;
	char shipMarker = peliLauta[x][y];
	ampumaLauta[x][y] = shipMarker;
	bool finalBlow = false;

	for (int i = 0; i < LAUDAN_KOKO; i++)
	{
		for (int j = 0; j < LAUDAN_KOKO; j++)
		{
			if (ampumaLauta[i][j] == shipMarker)
			{
				hitCount++;
			}
		}
	}

	switch (shipMarker)
	{
	case '5':
		finalBlow = hitCount == 5 ? true : false;
		break;
	case '4':
		finalBlow = hitCount == 4 ? true : false;
		break;
	case '3':
		finalBlow = hitCount == 3 ? true : false;
		break;
	case '2':
		finalBlow = hitCount == 2 ? true : false;
		break;
	default:
		break;
	}

	if (finalBlow)
	{
		cout << "Laukaus kohtaan " << koords << " upotti laivan." << endl << endl;
		for (int i = 0; i < LAUDAN_KOKO; i++)
		{
			for (int j = 0; j < LAUDAN_KOKO; j++)
			{
				if (ampumaLauta[i][j] == shipMarker)
				{
					ampumaLauta[i][j] = '#';
				}
			}
		}
		return 1;
	}
	else
	{
		cout << "Laukaus kohtaan " << koords << " osui laivaan." << endl << endl;
		return 0;
	}
}

void EnterShips(char peliLauta[][LAUDAN_KOKO], char ampumaLauta[][LAUDAN_KOKO], bool* boardIsEmpty)
{
	string koords;
	char suunta;
	int x, y, koko;
	bool sisalla;

	Alusta(peliLauta);
	Alusta(ampumaLauta);

	do
	{
		do
		{
			cout << "Anna viiden pituisen laivan alkupiste: ";
			getline(cin, koords);
			koko = 5;

		} while (MuunnaKoordinaatti(koords, &x, &y) != 0);

		do
		{
			cout << "Anna suunta (p(ohjoinen)/i(ta)/e(tela)/l(ansi)): ";
			cin >> suunta;
			cin.ignore();
			suunta = tolower(suunta);

		} while (suunta != 'p' && suunta != 'i' && suunta != 'e' && suunta != 'l');

		sisalla = CheckBoundaries(x, y, suunta, koko);

		if (!sisalla)
		{
			cout << "Laiva ei ollut pelilaudan sisalla! Yrita uudelleen..." << endl;
		}

	} while (!sisalla);

	PlaceShip(peliLauta, x, y, koko, suunta);

	do
	{
		do
		{
			cout << "Anna neljan pituisen laivan alkupiste: ";
			getline(cin, koords);
			koko = 4;

		} while (MuunnaKoordinaatti(koords, &x, &y) != 0);

		do
		{
			cout << "Anna suunta (p(ohjoinen)/i(ta)/e(tela)/l(ansi)): ";
			cin >> suunta;
			cin.ignore();
			suunta = tolower(suunta);

		} while (suunta != 'p' && suunta != 'i' && suunta != 'e' && suunta != 'l');

		sisalla = CheckBoundaries(x, y, suunta, koko);

		if (!sisalla)
		{
			cout << "Laiva ei ollut pelilaudan sisalla! Yrita uudelleen..." << endl;
		}

	} while (!sisalla);

	PlaceShip(peliLauta, x, y, koko, suunta);

	do
	{
		do
		{
			cout << "Anna kolmen pituisen laivan alkupiste: ";
			getline(cin, koords);
			koko = 3;

		} while (MuunnaKoordinaatti(koords, &x, &y) != 0);

		do
		{
			cout << "Anna suunta (p(ohjoinen)/i(ta)/e(tela)/l(ansi)): ";
			cin >> suunta;
			cin.ignore();
			suunta = tolower(suunta);

		} while (suunta != 'p' && suunta != 'i' && suunta != 'e' && suunta != 'l');

		sisalla = CheckBoundaries(x, y, suunta, koko);

		if (!sisalla)
		{
			cout << "Laiva ei ollut pelilaudan sisalla! Yrita uudelleen..." << endl;
		}

	} while (!sisalla);

	PlaceShip(peliLauta, x, y, koko, suunta);

	do
	{
		do
		{
			cout << "Anna kahden pituisen laivan alkupiste: ";
			getline(cin, koords);
			koko = 2;

		} while (MuunnaKoordinaatti(koords, &x, &y) != 0);

		do
		{
			cout << "Anna suunta (p(ohjoinen)/i(ta)/e(tela)/l(ansi)): ";
			cin >> suunta;
			cin.ignore();
			suunta = tolower(suunta);

		} while (suunta != 'p' && suunta != 'i' && suunta != 'e' && suunta != 'l');

		sisalla = CheckBoundaries(x, y, suunta, koko);

		if (!sisalla)
		{
			cout << "Laiva ei ollut pelilaudan sisalla! Yrita uudelleen..." << endl;
		}

	} while (!sisalla);
	
	PlaceShip(peliLauta, x, y, koko, suunta);

	*boardIsEmpty = false;
}

void PlaceShip(char peliLauta[][LAUDAN_KOKO], int x, int y, int koko, char suunta)
{
	char marker;
	switch (koko)
	{
	case 5:
		marker = '5';
		break;
	case 4:
		marker = '4';
		break;
	case 3:
		marker = '3';
		break;
	case 2:
		marker = '2';
		break;
	}
	if (suunta == 'p')
	{
		for (int i = 0; i < koko; i++)
		{
			peliLauta[x - i][y] = marker;
		}
	}
	else if (suunta == 'i')
	{
		for (int i = 0; i < koko; i++)
		{
			peliLauta[x][y + i] = marker;
		}
	}
	else if (suunta == 'e')
	{
		for (int i = 0; i < koko; i++)
		{
			peliLauta[x + i][y] = marker;
		}
	}
	else
	{
		for (int i = 0; i < koko; i++)
		{
			peliLauta[x][y - i] = marker;
		}
	}
}

bool CheckBoundaries(int x, int y, char suunta, int koko)
{
	if (suunta == 'p')
	{
		if (x - koko < 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else if (suunta == 'i')
	{
		if (y + koko > 7)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else if (suunta == 'e')
	{
		if (x + koko > 7)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else if (suunta == 'l')
	{
		if (y - koko < 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else
		return false;
}
